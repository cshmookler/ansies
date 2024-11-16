"""ansies root Conan file"""

from importlib import import_module
import os
from typing import List, Dict

from conan import ConanFile
from conan.errors import ConanException
from conan.tools.files import copy as copy_file
from conan.tools.gnu import PkgConfigDeps
from conan.tools.gnu.pkgconfigdeps import _PCGenerator, _PCContentGenerator
from conan.tools.meson import Meson, MesonToolchain
from conan.tools.scm import Git


this_dir: str = os.path.dirname(__file__)

placeholder_version: str = "0.0.0"

required_conan_version = ">=2.3.0"


class ansies(ConanFile):

    # Required
    name = "ansies"

    # Metadata
    license = "Zlib"
    author = "Caden Shmookler (cshmookler@gmail.com)"
    url = "https://github.com/cshmookler/ansies"
    description = "A header-only C++ library for using ANSI escape sequences. Supported on Windows and Unix-like operating systems."
    topics = []

    # Configuration
    package_type = "library"
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "quit_after_generate": [True, False],
    }
    default_options = {
        "shared": False,
        "fPIC": True,
        "quit_after_generate": False,
    }
    build_policy = "missing"

    # Files needed by Conan to resolve version and dependencies
    exports = (
        os.path.join(".git", "*"),
        "update_deps.py",
        "dependency_config.json",
        "binary_config.json",
    )

    # Files needed by Conan to build from source
    exports_sources = (
        os.path.join("build_scripts", "*"),
        os.path.join(name, "*"),
        os.path.join("src", "*"),
        os.path.join("tests", "*"),
        "meson.build",
    )

    # External includes
    _config_module = import_module("update_deps")

    def set_version(self):
        """Get project version from Git"""
        git = Git(self, folder=self.recipe_folder)
        try:
            self.version = git.run("describe --tags").partition("-")[0]
        except ConanException:
            # Set a placeholder version if an error is encountered while using Git
            self.version = placeholder_version

    def config_options(self):
        """Change available options"""
        if self.settings.os == "Windows":
            del self.options.fPIC

    def configure(self):
        """Change behavior based on set options"""
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def build_requirements(self):
        """Declare dependencies of the build system"""
        # TODO: Update meson and pkgconf versions
        self.tool_requires("meson/1.4.0")
        self.tool_requires("pkgconf/2.2.0")

    def requirements(self):
        """Resolve and declare dependencies"""
        # Read the binary configuration file
        self._binaries = self._config_module.Binaries()
        self._binaries.read()
        binary_config = self._binaries.get()

        # Read the dependency configuration file
        self._deps = self._config_module.Dependencies()
        self._deps.read()
        dep_config = self._deps.get()

        # Declare dependencies
        for dep_name, dep in dep_config.items():
            if not dep.link_preference:
                self.requires(dep.recipe)
            else:
                self.requires(dep.recipe, options={"shared": dep.dynamic})

    def layout(self):
        """Set the layout of the build files"""
        self.folders.build = os.path.join(self.recipe_folder, "build")
        self.folders.generators = os.path.join(self.folders.build, "generators")

    def generate(self):
        """Generate the build system"""
        # Get the binary and dependency data in structured form
        binary_config = self._binaries.get()
        dep_config = self._deps.get()

        # Generate .pc files for dependencies
        pkgconfig_deps = PkgConfigDeps(self)
        pkgconfig_deps.generate()

        for require, dep in self.dependencies.host.items():
            dep_name = str(dep.ref.name)

            # Ignore dependencies that are not declared in dependency configuration file.
            if dep_name not in dep_config:
                continue

            # Record the resolved version for this dependency
            dep_config[dep_name].resolved_version = str(dep.ref.version)

            # This class is used internally by Conan to get dependency component information and generate PkgConfig files
            pc_generator = _PCGenerator(pkgconfig_deps, require, dep)

            def record_component(component):
                component_pc_info = (
                    pc_generator._content_generator._get_context(component)
                )
                component_name = str(component_pc_info["name"])
                component_version = str(component_pc_info["version"])
                dep_config[dep_name].components[
                    component_name
                ] = component_version
                
            # Add the name of the package as the sole component if it does not have any components
            if not pc_generator._dep.cpp_info.has_components:
                record_component(pc_generator._package_info())

            # Accumulate all components of the dependency
            for component in pc_generator._components_info():
                record_component(component)

        # Add missing components to the dependencies listed in the binary configuration file
        for binary_name, binary in binary_config.items():
            for dep_name, components in binary.dependencies.items():

                # Verify that all dependencies in the binary configuration file are also declared in the dependency configuration file.
                if dep_name not in dep_config:
                    raise RuntimeError(
                        '"'
                        + dep_name
                        + '" was not found in "'
                        + self._deps.path
                        + '"'
                    )

                for component_name in dep_config[dep_name].components.keys():
                    if component_name not in components:
                        binary.dependencies[dep_name][component_name] = True

        # Update the binary and dependency configuration files
        self._binaries.write()
        self._deps.write()

        # Generate the Meson toolchain
        toolchain = MesonToolchain(self)
        toolchain.properties = {
            "_name": self.name,
            "_version": self.version,
            "_binaries": self._config_module.unstructured(
                binary_config, dep_config
            ),
        }
        toolchain.generate()

        if self.options.quit_after_generate:
            exit(0)

    def build(self):
        """Build this project"""
        self._build_folder = os.path.join(self.recipe_folder, "build")
        meson = Meson(self)
        meson.configure()
        meson.build()
        meson.test()

    def package(self):
        """Install project headers and compiled binaries"""
        meson = Meson(self)
        meson.install()

    def package_info(self):
        """Package information"""
        self.cpp_info.libs = [self.name]
        self.cpp_info.includedirs = ["include"]
        self.cpp_info.bindirs = ["bin"]
