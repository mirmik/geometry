#!/usr/bin/env python3

import licant

licant.module("maho.include",
              include_paths=["include"],
              )

licant.module("maho",
              mdepends=["maho.include"],
              )
