def nlast(x):
    return (x[0].upper())+'.'
def last(x):
    s= x[0].upper()
    for i in xrange(1,len(x)):
        s+= x[i].lower()
    return s

for tt in xrange(int(raw_input())):
    a= map(str, raw_input().split())
    s= ''
    if len(a)==1:
        s= last(a[0])
    elif len(a)==2:
        s= nlast(a[0])+' '+last(a[1])
    else: 
        s= nlast(a[0])+' '+nlast(a[1])+' '+last(a[2]) 
    print s