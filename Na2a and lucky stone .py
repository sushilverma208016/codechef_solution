import math,sys,numpy
n = int(input())
a = map(int, raw_input().split())
for i in range(n):
    num,x,y= a[i],a[i],a[i]
    c5,c2= 0,0
    while (x%5==0):
        x=x/5
        c5=c5+1 
    while (x%2==0):
        x=x/2
        c2=c2+1
    if(c5<=c2): print num
    else:
        g= c5-c2
        t=g/2
        for j in range(t):
            num=num*4
        if g%2==1: num=num*4 
        print num 
    