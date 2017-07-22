import math,sys

tt= int(input())
n =90  
a= [None]*n
a[0],a[1] =1,2
for i in range(2,n):
    a[i]=a[i-1]+a[i-2]
while(tt>0):
    tt=tt-1
    x=int(input())
    #print x 
    for i in range(0,n):
        if x<a[i]:
            print i 
            break 
    