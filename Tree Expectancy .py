import math
from fractions import gcd
m= 10**9+7
m2= 10**9+9

def fun(n):
    p,q= n*(n-1), 2*(2*n-3)
    g= gcd(p,q)
    p,q= p//g,q//g
    pqm= (p*pow(q,m-2,m))%m
    pqm2= (p*pow(q,m2-2,m2))%m2
    print pqm, pqm2
    return
    
t= int(raw_input())
for tt in xrange(t):
    n= int(raw_input())
    if n==1:
        print "0 0"
    elif n==2 or n==3:
        print "1 1"
    else: fun(n)
    