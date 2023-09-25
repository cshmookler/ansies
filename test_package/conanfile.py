from conan import ConanFile
from os.path import join as join_path
from conan.tools.meson import Meson
from conan.tools.build import can_run

required_conan_version = ">=2.0.6"

class ansiesTestPackage(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "PkgConfigDeps", "MesonToolchain"

    def build_requirements(self):
        self.tool_requires("meson/1.2.1")
        self.tool_requires("pkgconf/2.0.3")

    def requirements(self):
        if self.tested_reference_str is not None:
            self.requires(self.tested_reference_str)
        else:
            # self.requires("ansies/[0.2.0-2-ga75d58b]")
            self.requires("ansies/[*]")
    
    def layout(self):
        self.folders.build = "build"
        self.folders.generators = join_path("build", "generators")

    def build(self):
        meson = Meson(self)
        meson.configure()
        meson.build()
    
    def test(self):
        if can_run(self):
            cmd = join_path(self.build_folder, "ansies_package_test")
            self.run(cmd, env="conanrun")
