t= int(raw_input())
for tt in xrange(t):
    n,q= map(int, raw_input().split())
    arr= map(int, raw_input().split())
    for qq in xrange(q):
        a,b,c,d=  map(int, raw_input().split())
        a,b,c,d= a-1,b-1,c-1,d-1
        one= sorted(arr[a:b+1])
        two= sorted(arr[c:d+1])
        miss=0
        f=1 
        for i in xrange(b-a+1):
            if (one[i]!=two[i]):
                miss+=1 
                if (miss==2):
                    f=0
                    break;
        if f==0: print "NO"
        else: print "YES"