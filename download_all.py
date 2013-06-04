#!/usr/bin/python

import sys
import os
import fnmatch
import urllib2

import fnmatch
import os

for file in os.listdir('.'):
    if fnmatch.fnmatch(file, 'uva*'):
        suffix = file[3:8]
        print suffix
        os.system("./download.py "+suffix)
        #os.system("mv "+file+os.sep+"main.cpp"+" "+file+os.sep+file+".cpp")