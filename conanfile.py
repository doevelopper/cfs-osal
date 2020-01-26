#!/usr/bin/env python
# -*- coding: utf-8 -*-

from conans import ConanFile, tools, CMake
from conans.util import files
from conans.errors import ConanInvalidConfiguration
from conans.errors import ConanException
from conans.client.build.cppstd_flags import cppstd_flag
from conans.model.version import Version
from conans.tools import load
import re
import os
import sys
import shutil
import subprocess

def get_version_from_git_tag():
    """
    :returns: The git tag associated with the current commit, or None if it is not able to get the Git data.
    Returning None is necessary when the recipe is already in the Conan cache, and the Git repository may not be there.
    A value of None makes Conan get the version from the metadata.
    See: https://docs.conan.io/en/latest/howtos/capture_version.html
    """
    try:
        return tools.Git().get_tag()
    except:
        return None


class CfsOsal(ConanFile):
    name = "CFS OSAL"
#    version = "0.0.1"  get_version_from_git_tag()
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

    options = {
        "shared": [True, False],
        "header_only": [True, False],
        "error_code_header_only": [True, False],
        "fPIC": [True, False],
        "namespace_alias": [True, False],  # enable namespace alias,ns=cfs::osal
    }

    default_options = "shared=False"

    no_copy_source = True

    def set_version(self):
        # capture package version from PROJECT_VERSION in CMakeList.txt
        content = load(os.path.join(self.recipe_folder, "CMakeLists.txt"))
        #version = re.search(b"set\(MY_LIBRARY_VERSION (.*)\)", content).group(1)
        version = re.search(b"VERSION (.*)", content).group(1)
        self.version = version.strip()
        ### capture package version from SCM: git
        # git = tools.Git(folder=self.recipe_folder)
        # self.version = "%s_%s" % (git.get_branch(), git.get_revision())

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
        self.copy("*.hpp", dst="include/cfs-osal", src="./src")
        self.copy("*.a", dst="lib", src=".", keep_path=False)
        self.copy("*.lib", dst="lib", src=".", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)

    def package_info(self):
        if self.settings.os == "Linux":
            self.cpp_info.libs = ["-Wl,--start-group"]
        self.cpp_info.libs.extend(tools.collect_libs(self))
        if self.settings.os == "Linux":
            self.cpp_info.libs.extend(["-Wl,--end-group", "pthread"])
        bindir = os.path.join(self.package_folder, "bin")
        self.output.info("Appending PATH environment variable: {}".format(bindir))
         self.env_info.PATH.append(bindir)

    def package_id(self):
        self.info.header_only()
        del self.info.settings.compiler


