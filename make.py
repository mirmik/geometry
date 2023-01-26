#!/usr/bin/env python3
# coding: utf-8

import licant
import licant.install
import os
import sys

licant.execute("maho.g.py")

licant.cxx_application("runtests",
                       sources=[
                           "tests/*.cpp",
                           "tests/base/*.cpp",
                           "tests/rga/*.cpp",
                           "tests/cga/*.cpp",
                       ],
                       cxxstd="c++20",
                       ccstd="c11",
                       cxx_flags="-g -fPIC -Werror=all -Wno-gnu-zero-variadic-macro-arguments -Weffc++",
                       include_paths=["./tests", "."],
                       )

# licant.install.install_library(
#    tgt="install",
#    uninstall="uninstall",
#    libtgt=["libigris.so", "libigris.a"],
#    hroot="igris",
#    headers="igris")
#licant.fileset("all", targets=["runtests", "libigris.so", "libigris.a"])

licant.ex("runtests")
