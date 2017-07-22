import math,sys
def f(a,b):
    if(b%a==0):
        return int(math.log((b/a),2))
    return 1+ f((a/2),b) 
    
tt= int(input())
while(tt>0):
    tt=tt-1
    a,b= map(int, raw_input().split())
    print f(a,b)
    