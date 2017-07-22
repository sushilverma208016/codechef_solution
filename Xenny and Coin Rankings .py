t= int(raw_input())
for tt in xrange(t):
    u,v = map(int, raw_input().split())
    level= u+v+1
    last= (level*(level+1))/2
    ans= last-v
    print ans
    