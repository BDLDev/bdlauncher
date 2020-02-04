#!/usr/bin/env python3
import sys,os
target=sys.argv[0]
gen=""
try:
    pip=os.popen("clang-format -i "+target,"r")
    gen=pip.read()
    pip.close()
except:
    gen=""
if len(gen)==0:
    sys.stderr.write("[WARNING] clang-format not found!!!fallback to plain file\n")
    sys.stdout.write(open(target,"r").read())
else:
    sys.stdout.write(gen)