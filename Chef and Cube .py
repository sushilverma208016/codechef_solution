import math,sys,numpy
tt= int(input())
while(tt>0):
    tt=tt-1
    f,b,l,r,t,bot= map(str, raw_input().split())
    if f==t==r or t==b==r or f==bot==r or bot==r==b or f==t==l or l==t==b or l==f==bot or l==b==bot:
        print "YES"
    else : print "NO"  
        