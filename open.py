#!/usr/bin/python

import sys
import os
import urllib2
import mysql.connector
import ConfigParser

config = ConfigParser.ConfigParser()
config.read('db.cfg')
cfg = dict((k,v) for k,v in config.items('mysql'))

def open_problem(problem_id):
	con = mysql.connector.connect(
		host=cfg['db_host'],
		user=cfg['db_user'],
		passwd=cfg['db_passwd'],
		db=cfg['db_name']
		)
	cur = con.cursor()
	cur.execute('select problem_url from problems where problem_id=%s',[problem_id])
	url = cur.fetchone()
	print url
	os.system('open '+'"'+url[0]+'"')

if len(sys.argv)<2:
	print "usage: open.py {5_digit_uva_problem_number}"
else:
	for arg in sys.argv[1:]:
		open_problem(arg)
