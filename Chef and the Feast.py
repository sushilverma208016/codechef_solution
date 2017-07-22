t= int(raw_input())

for tt in xrange(t):
    n= int(raw_input())
    a= map(int, raw_input().split())
    a.sort(reverse=True)
    s= sum(a)
    left, right= n*[0], n*[0]
    left[0], right[n-1]= a[0], a[n-1]
    for i in xrange(1, n):
        left[i]= left[i-1]+a[i]
    for i in xrange(n-2, -1, -1):
        right[i]= right[i+1]+a[i]
    for i in xrange(n):
        leftsum= left[i-1] if i-1>=0 else 0
        rightsum= right[i+1] if i+1<=n-1 else 0
        temp= (i+1)*(leftsum+a[i])+rightsum
        #print i, leftsum, rightsum, temp
        s= max(s, temp)
    print s