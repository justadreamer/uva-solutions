#!/usr/bin/python

import urllib2
import json
from multiprocessing import Pool, Queue
import mysql.connector
from bs4 import BeautifulSoup
import string
import ConfigParser

'''
CREATE TABLE `problems` (
  `problem_id` varchar(5) NOT NULL,
  `problem_title` varchar(256) DEFAULT NULL,
  `problem_url` varchar(256) DEFAULT NULL,
  PRIMARY KEY (`problem_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1
'''

config = ConfigParser.ConfigParser()
config.read('db.cfg')
cfg = dict((k,v) for k,v in config.items('mysql'))

base_url = 'http://uva.onlinejudge.org/'


def parse_volumes(url):
    resp = urllib2.urlopen(url)
    soup = BeautifulSoup(resp.read())
    div = soup.find('div',id='col3_content_wrapper')
    table = div.find('table')
    links = table.find_all('a')
    return map(lambda link: link['href'],links)

def parse_problems(url):
    resp = urllib2.urlopen(base_url+url)
    soup = BeautifulSoup(resp.read())
    resp.close()
    div = soup.find('div',id='col3_content_wrapper')
    table = div.find('table')
    links = table.find_all('a')

    con = mysql.connector.connect(
        host=cfg['db_host'],
        user=cfg['db_user'],
        passwd=cfg['db_passwd'],
        db=cfg['db_name']
        )
    cur = con.cursor()

    query_insert = ("INSERT IGNORE INTO problems "
              "(problem_id, problem_title, problem_url) "
              "VALUES (%s, %s, %s) ")

    for link in links:
        text = link.string 
        if text:
            problem_url = base_url+link['href'].encode('ascii','ignore')
            problem_title = text.encode('ascii','ignore')
            print problem_title
            problem_id = string.split(problem_title,'-')[0]
            problem_id = '{0:05d}'.format(int(problem_id)).encode('ascii','ignore')
            cur.execute(query_insert,(problem_id,problem_title,problem_url))
            con.commit()
    cur.close()
    con.close()


if __name__ == '__main__':
    top_volumes=[
        base_url+'index.php?option=com_onlinejudge&Itemid=8&category=1',
        base_url+'index.php?option=com_onlinejudge&Itemid=8&category=2'
    ]
    links = []
    for volume in top_volumes:
        links.extend(parse_volumes(volume))

    for link in links:
        parse_problems(link)