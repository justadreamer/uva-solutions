#!/usr/bin/python

import sys
import os
import urllib2

def download(problem):
	prefix = int(problem[:3])
	i=0
	while problem[i]=='0':
		i=i+1
	suffix = problem[i:]
	url = "http://uva.onlinejudge.org/external/{0}/{1}.pdf".format(prefix,suffix)
	print "downloading",url

	req = urllib2.Request(url)
	con = urllib2.urlopen(req)
	filename = os.path.dirname(__file__)+os.sep+"uva"+problem+os.sep+"uva"+problem+".pdf"
	print filename

	f = open(filename,'w+')
	f.write(con.read())
	f.close()

if len(sys.argv)<2:
	print "usage: download.py {5_digit_uva_problem_number}"
else:
	for arg in sys.argv[1:]:
		download(arg)
