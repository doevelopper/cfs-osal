#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
import subprocess

from conans import ConanFile, tools, CMake
from conans.util import files
from conans.errors import ConanInvalidConfiguration
from conans.model.version import Version

class CfsOsal(ConanFile):
    name = "CFS OSAL"
    version = "0.0.1"
    license = "Apache License, Version 2.0, Copyright (c) 2014-2018 Adrien H. <hppyman ad hotmiail dot fr>"
    settings = "os", "compiler", "build_type", "arch"
    description = "Core Flight System OS Abstraction Layer"
    author = "Adrien H. <hppyman ad hotmail dot fr>"
    url = 'https://github.com/doevelopper/cfs-osal'
    homepage = url
    topics = ("conan", "CFS OSAL", "cfsosal")
    exports = ["LICENSE"]
    exports_sources = ["CMakeLists.txt", "src/*"]
    generators = "cmake"
    scm = {
        "type": "git",
        "url": "auto",
        "revision": "auto"
    }

    no_copy_source = True

    def configure(self):
        if self.settings.os == "Windows" and \
           self.settings.compiler == "Visual Studio":
            raise ConanInvalidConfiguration("MSVC Not supported")

    def build(self):
        tools.replace_in_file("CMakeLists.txt", "project(cfsosal)", "project(cfsosal)\ninclude(conanbuildinfo.cmake)\nconan_basic_setup()")
        cmake = CMake(self)
        cmake.definitions["BUILD_TESTING"] = False
        cmake.configure()
        cmake.build()
        #cmake.install()
        #cmake.test()

    def package(self):
        self.copy("LICENSE", dst="licenses")
        self.copy("*.hpp", dst="include", src="./src")
        self.copy("*.a", dst="lib", src=".", keep_path=False)
        self.copy("*.lib", dst="lib", src=".", keep_path=False)

    def package_info(self):
        if self.settings.os == "Linux":
            self.cpp_info.libs = ["-Wl,--start-group"]
        self.cpp_info.libs.extend(tools.collect_libs(self))
        if self.settings.os == "Linux":
            self.cpp_info.libs.extend(["-Wl,--end-group", "pthread"])
