#!/usr/bin/env python3
import sys,os
target=sys.argv[1]
try:
    if os.system("clang-format -i "+target)!=0:
        1/0
except:
    sys.stderr.write("\n\n[WARNING] clang-format not found!!!fallback to plain file\n\n")