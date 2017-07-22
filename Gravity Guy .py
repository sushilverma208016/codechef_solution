import math,sys
    
tt= int(input())
while(tt>0):
    tt=tt-1
    l=0
    s1= str(raw_input())
    s2= str(raw_input())
    n= len(s1) 
    a1,a2=j = [None]*n, [None]*n 
    if s1[0]=='#' and s2[0]=='#':
        print 'No'
        continue
    if s1[0]=='#': a1[0]=-1
    else: a1[0]=0
    if s2[0]=='#': a2[0]=-1
    else: a2[0]=0
    for i in range(1,n):
        if s1[i]=='#' and s2[i]=='#':
            l=1
            break
        if s1[i]=='#': a1[i]=-1
        else : 
            if a1[i-1]!=-1 :a1[i]= a1[i-1]
            else: a1[i]= a2[i-1]+1 
        if s2[i]=='#': a2[i]=-1
        else : 
            if a2[i-1]!=-1 :a2[i]= a2[i-1]
            else: a2[i]= a1[i-1]+1
        if a1[i]>-1 and a2[i]>-1:
            a1[i]= min(a1[i],a2[i]+1)
            a2[i]= min(a2[i],a1[i]+1)
            
    if l==1 :
        print 'No'
        continue
    if a1[n-1]==-1: ans= a2[n-1]
    elif a2[n-1]==-1: ans= a1[n-1]
    else : ans= min(a1[n-1],a2[n-1])
    print 'Yes'
    print ans 
    
    
    
    