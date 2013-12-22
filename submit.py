#!/usr/bin/python

from bs4 import BeautifulSoup
import urllib
import urllib2
import sys
import os
import string
from cookielib import LWPCookieJar

kUsername = 'username'
kPasswd = 'passwd'
base_url = 'http://uva.onlinejudge.org/'
cookiesfile = os.path.expanduser("~/.cookiejar")
is_java = False #we assume C++ by default

cookiejar = LWPCookieJar(cookiesfile)
if os.access(cookiesfile,os.F_OK):
	cookiejar.load()

opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cookiejar))

def filter_form_by_action(forms,action_part):
	l = filter(lambda f: f['action'].find(action_part)>-1,forms)
	if len(l):
		return l[0]
	return None

def get_codeform(forms):
	return filter_form_by_action(forms,'save_submission')

def get_loginform(forms):
	return filter_form_by_action(forms,'login')

def params_dict_from_inputs(inputs):
	params_dict = dict()
	for i in inputs:
		if 'name' in i.attrs and 'value' in i.attrs:
			params_dict[i['name']]=i['value']
	return params_dict

def get_code(task):
	uvatask = 'uva'+task
	filename = uvatask+'.cpp'
	if is_java:
		filename = 'Main.java'
	abspath = os.path.abspath(uvatask+'/'+filename)
	f = open(abspath)
	return f.read()

def submit_code(codeform,task,language):
	inputs = codeform("input")
	params_dict = params_dict_from_inputs(inputs)
	params_dict['language']=language
	params_dict['localid']=task
	params_dict['code']=get_code(task)
	params_string = urllib.urlencode(params_dict)
	resp = opener.open(base_url+codeform['action'],params_string)

def login(html):
	soup = BeautifulSoup(html)
	forms = soup("form")
	loginform = get_loginform(forms)
	inputs = loginform("input")
	params_dict = params_dict_from_inputs(inputs)
	
	credentials = read_credentials()
	params_dict[kUsername]=credentials[kUsername]
	params_dict[kPasswd]=credentials[kPasswd]
	params_string = urllib.urlencode(params_dict)
	resp = opener.open(loginform['action'],params_string)
	print "attempted to log in"
	return resp.read()


def read_credentials():
	creds_file = open(os.path.expanduser('~/.uvapasswd'),'r')
	creds = creds_file.read().splitlines()
	return {kUsername:creds[0],kPasswd:creds[1]}

def get_submit_page():
	quick_submit_url = "index.php?option=com_onlinejudge&Itemid=25"
	resp = opener.open(base_url+quick_submit_url)
	return resp.read()

def try_submit(html,task):
	soup = BeautifulSoup(html)
	forms = soup("form")
	codeform = get_codeform(forms)
	if not codeform:
		print "seems we are not logged in"
		return False
	language = 3 #assume C++
	if is_java:
		language = 2
	submit_code(codeform,task,language)
	print "submitted code for problem id",task
	return True

def main():
	if len(sys.argv)<2:
		print "Please specify a 5-digit task number"
		sys.exit()

	task = sys.argv[1]

	global is_java
	is_java = len(sys.argv)>2 and sys.argv[2]=='java'

	html = get_submit_page()
	if not try_submit(html,task):
		try_submit(login(html),task)

	cookiejar.save()

if __name__ == "__main__":
    main()