import math,sys,numpy
t = int(input())
for tt in range(t):
    days,peice = map(int, raw_input().split())
    #print days,peice
    req = map(int, raw_input().split())
    #print req 
    bread,packet,curpacket =0,0,0 
    for i in range(days):
        curreq= req[i]
        if bread>=curreq:
            bread=bread-curreq
            if bread>0: bread= bread-1
            #if bread==0: curpacket-= 1 
        else:
            x= float(curreq-bread) # rmain curreq
            bread=0 
            y= int(math.ceil(x/float(peice) ))
            #print y 
            bread= bread+ y*peice
            #curpacket+= y 
            packet =packet+ y
            bread= bread- x 
            bread= bread-1 
            if bread<0: bread=0 
        
    print packet

    