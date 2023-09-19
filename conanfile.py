from conan import ConanFile
from conan.tools.scm import Git
# from conan.tools.gnu import PkgConfigDeps
from conan.tools.meson import Meson, MesonToolchain
from conan.tools.files import copy as copy_file
from os.path import join as join_path

required_conan_version = ">=2.0.6"

class ansies(ConanFile):
    # Required
    name = "ansies"

    # Metadata
    license = "Zlib"
    author = "Caden Shmookler (cshmookler@gmail.com)"
    url = "https://github.com/cshmookler/ansies.git"
    description = "C++ library for utilizing ANSI escape sequences."
    topics = "c++"

    # Configuration
    package_type = "library"
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True, False],
        "fPIC": [True, False]
    }
    default_options = {
        "shared": False,
        "fPIC": True
    }
    build_policy = "missing"

    # Essential files
    exports_sources = ".git/*", "include/*", "src/*", "meson.build", "LICENSE"

    def set_version(self):
        git = Git(self)
        self.version = git.run("describe --tags")

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def build_requirements(self):
        self.tool_requires("meson/[>=1.2.1 <2.0.0]")

    def layout(self):
        self.folders.source = ""
        self.folders.build = "build"
        self.folders.generators = join_path("build", "generators")
    
    # def requirements(self):
    #     pass

    def generate(self):
        # deps = PkgConfigDeps(self)
        # deps.generate()
        tc = MesonToolchain(self)
        tc.properties = { "version" : self.version }
        tc.generate()

    def build(self):
        meson = Meson(self)
        meson.configure()
        copy_file(self,
            "version.hpp",
            self.build_folder,
            join_path(self.source_folder, "include", "ansies"))
        meson.build()

    def package(self):
        meson = Meson(self)
        meson.install()

    def package_info(self):
        self.cpp_info.libs = ["ansies"]
        self.cpp_info.includedirs = ["include"]