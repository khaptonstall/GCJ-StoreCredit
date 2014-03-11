'''
Created on Mar 9, 2014

@author: kyle
'''

#Google programming problem
#Store Credit


from sys import *

def solve(x, item, c):
    for i in xrange(len(item)):
        for p in xrange(i+1, len(item)):
            if item[i] + item[p] == c:
                print "Case# %d: %d %d" %(x+1, i+1, p+1)




data = int(raw_input())
for ele in xrange(data):
    copy = int(raw_input())
    copycopy = int(raw_input())
    items = map(int, stdin.readline().split())
    solve(ele, items, copy)

