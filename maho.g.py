#!/usr/bin/env python3

import licant

licant.module("maho.include",
              include_paths=["."],
              )

licant.module("maho",
              mdepends=["maho.include"],
              libs=["nos"],
              )
