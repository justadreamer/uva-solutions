#!/usr/bin/python

def calc(a):
  b=[reduce(lambda acc,y: acc+1 if y<=x else acc,a[:i],0) for i,x in enumerate(a)]
  return sum(b)
 
assert calc([38, 111, 102, 111, 177])==9
assert calc([276, 284, 103, 439, 452, 276, 452, 398,])==20