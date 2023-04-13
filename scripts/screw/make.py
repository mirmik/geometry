#!/usr/bin/env python3

import licant

licant.include("maho", "../../maho.g.py")

licant.cxx_application("screw",
                       sources=["main.cpp"],
                       mdepends=["maho"],
                       )

licant.ex("screw")
