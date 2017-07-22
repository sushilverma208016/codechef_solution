for tt in xrange(int(raw_input())):
    s= str(raw_input())
    n= len(s)
    m,i,k= 0,0,1
    while i<n:
        if s[i]=='>' or s[i]=='=' :
            while i<n and (s[i]=='>' or s[i]=='='):
                if s[i]=='>': k=k+1
                i= i+1
            m= max(m,k)
            k=1
        elif s[i]=='<' or s[i]=='=':
            while i<n and (s[i]=='<' or s[i]=='='):
                if s[i]=='<': k=k+1
                i= i+1
            m= max(m,k)
            k=1
    print m