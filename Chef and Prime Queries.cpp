#include <bits/stdc++.h>
using namespace std;
int MAX_SIZE = 1000001;
vector<bool>isprime(MAX_SIZE, true);
vector<int>primes;
vector<int>SPF(MAX_SIZE);

void range_sieve(int N, int minx, int maxy) {
    isprime[0]=false, isprime[1]= false ;
    for (int i=2; i<N; i++) {
        if (isprime[i]) { 
            if(minx<=i && i<=maxy) primes.push_back(i);
            SPF[i]= i;
        }
        for (int j=0; j<(int)primes.size() && i*primes[j]<N && primes[j]<=SPF[i]; j++) {
            isprime[i*primes[j]]= false;
            SPF[i*primes[j]]= primes[j] ;
        }
    }
}
int first(int low, int high, int x, int l) {
    while (high>=low) {
        int mid= low+(high-low)/2;
        if ( ( mid==0 || x>primes[mid-1] ) && primes[mid]>=x ) return mid;
        else if (x>primes[mid]) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int last(int low, int high, int y, int l) {
    while (high>=low) {
        int mid= low+(high-low)/2;
        if ( ( mid==l-1 || y<primes[mid+1] ) && primes[mid]<=y ) return mid;
        else if (y<primes[mid]) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
int main() {
	int n, q, i, j, l, r, x, y, le, numb, p, e, ind1, ind2, left, up, dia, res, minx=MAX_SIZE, maxy=1;
	scanf("%d", &n);
	vector<int> arr(n);
	for (i=0; i<n; i++) scanf("%d", &arr[i]);
	scanf("%d", &q);
	vector<int> tmp1(4);
	vector<vector<int> > query(q,tmp1);
	for (i=0; i<q; i++) {
	    scanf("%d %d %d %d", &l, &r, &x, &y);
	    if (minx>x) minx=x;
	    if (maxy<y) maxy=y;
	    query[i][0]=l, query[i][1]=r, query[i][2]=x, query[i][3]=y;
	}
	range_sieve(MAX_SIZE, minx, maxy);
    le= primes.size();
    
    vector<int> tmp2(le);
	vector<vector<int> > table(n,tmp2);
    for (i=0; i<n; i++) {
        for (j=0; j<le; j++) {
            numb=arr[i], p=primes[j], e=0;
            while (numb%p==0) {e++; numb=numb/p;}
            left= (i-1>=0)? table[i-1][j]: 0;
            up= (j-1>=0)? table[i][j-1]: 0;
            dia= ( (i-1>=0) && (j-1>=0) )? table[i-1][j-1]: 0;
            table[i][j]= left+up-dia+e;
        }
    }
    for (i=0; i<q; i++) {
        res= 0;
        l=query[i][0]-1, r=query[i][1]-1, x=query[i][2], y=query[i][3];
        ind1= first(0, le-1, x, le), ind2= last(0, le-1, y, le);
        if ( (ind1==-1) || (ind2==-1) ) { printf("%d\n",res); continue; }
        up= (l-1>=0)? table[l-1][ind2]: 0;
        left= (ind1-1>=0)? table[r][ind1-1]: 0;
        dia= ( (l-1>=0) && (ind1-1>=0) )? table[l-1][ind1-1]: 0;
        res= table[r][ind2]-up-left+dia;
        printf("%d\n",res);
    }
	return 0;
}