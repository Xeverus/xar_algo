from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout


class XarEngine(ConanFile):
    name = "Xar Algo"
    version = 0.0
    author = "michal.wendel@gmail.com"

    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"
    options = {
        "shared": [True, False],
    }
    default_options = {
        "shared": False,
    }

    def build_requirements(self):
        self.build_requires("cmake/3.25.0")

    def requirements(self):
        self.requires("gtest/1.15.0")

    def layout(self):
        cmake_layout(self)

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package_info(self):
        self.cpp_info.libs = ["xar_algo"]

    def package(self):
        cmake = CMake(self)
        cmake.install()
