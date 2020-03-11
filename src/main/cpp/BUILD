
package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")
load("@rules_pkg//:pkg.bzl", "pkg_tar", "pkg_deb")

cc_library(

    name = "cfs-osal-main",

    srcs = [
        "cfs/osal/Activator.cpp",
    ],

    hdrs = [
        "cfs/osal/Activator.hpp",
    ],

    copts = [
        "-std=c++17",
        "-DLOG_LEVEL=1",
        "-lapr-1",
        "-laprutil-1",
        "-llog4cxx",
		"-D_REENTRANT",
        "-I/usr/local/include/",
    ],

    linkopts = [
        "-L/usr/local/lib",
		"-pthread",
        "-lapr-1",
        "-laprutil-1",
        "-llog4cxx",
	],

	includes = [
		".",
	],

    #visibility = ["//visibility:public"],
    #visibility = ["//main:__pkg__"],
)

#cc_binary(
#    name = "cfs-osal-main.bin",
#    srcs = ["computer/science/main.cpp"],
#    copts = [
#       "-std=c++17",
#    ],

#    deps = [
#        ":cfs-arkhe-gcs-main",
#    ],
#)

pkg_tar(
    name = "cfs-osal-main-libs",
    strip_prefix = "/src/main/cpp",
    package_dir = "/opt/lib",
    srcs = ["//src/main/cpp:cfs-osal-main"],
    mode = "0755",
)

pkg_tar(
    name = "cfs-osal-main-hdrs-pkg",
#    testonly = True,
    srcs = glob([
        "**/*.hpp",
    ]),
    # extension = "tar.gz",
    package_dir = "/opt/include",
    strip_prefix = "/src/main/cpp",
    tags = ["manual"],
    visibility = ["//visibility:public"],
    mode = "0644",
)

#pkg_tar(
#    name = "cfs-osal-main-bin-pkg",
##    testonly = True,
#    srcs = [
#        # ":cfs-algo-main",
#        ":cfs-osal-main.bin",
#    ],
#    # extension = "tar.gz",
#    package_dir = "/opt/bin",
#    strip_prefix = "/src/main/cpp",
#    tags = ["manual"],
#)

pkg_tar(
    name = "cfs-osal",
    extension = "tar.gz",
    deps = [
        ":cfs-osal-main-libs",
        ":cfs-osal-main-hdrs-pkg",
#        ":cfs-arkhe-gcs-main-bin-pkg",
    ],
)

pkg_deb(
    name = "cfs-osal-main-deb-pkg",
    testonly = True,
    architecture = "amd64",
    data = ":cfs-osal",
    description = "Core Flight System Os Abstraction LAyer",
    homepage = "https://gitlab.com/doevelopper/cfs-osal",
    maintainer = "Adrien H.",
    package = "CFSOsal",
    tags = ["manual"],
    version = "0.0.1",
    visibility = ["//visibility:public"],
)

