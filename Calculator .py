import math
def find(x,n,b):
    return x*(int(math.floor((n-x)/(b*1.0))))
    
def fun(n,b):
    if b>=n: return 0
    p= (n/2.0)/(b*1.0)
    #print p
    p1,p2= int(math.floor(p)), int(math.ceil(p))
    #print p1,p2
    x1,x2= n-p1*b, n-p2*b
    #print x1,x2
    return max(n-b, find(x1,n,b), find(x2,n,b))

for tt in xrange(int(raw_input())):
    n, b= map(int, raw_input().split())
    print fun(n,b)
    