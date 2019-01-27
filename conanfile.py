import os
import subprocess

from conans import ConanFile, tools, CMake
from conans.util import files

class CfsOsal(ConanFile):
    name = "CFS OSAL"
    version = "0.0.0"
    license = "Apache License, Version 2.0, Copyright (c) 2014-2018 Adrien H. <hppyman ad hotmiail dot fr>"
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"
    description = "Core Flight System OS Abstraction Layer"
    author = "Adrien H. <hppyman ad hotmiail dot fr>"
    url = 'https://github.com/doevelopper/cfs-osal'
    scm = {
        "type": "git",
        "url": "auto",
        "revision": "auto"
    }

    no_copy_source = True


    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        #cmake.install()
        #cmake.test()

