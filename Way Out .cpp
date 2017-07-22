#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

ll tree[1000004];
ll query(ll n,ll b)	{
	ll sum = 0;
	for (; b; b-= (b&-b)) sum= sum+tree[b];
	return sum;
}

void update(ll n,ll k,ll v) {
	for (;k <=n; k+=(k&-k)) tree[k]= tree[k]+v;   }

void rupdate(ll n, ll i, ll j, ll v)	{
	update(n, i, v); 
	update(n, j + 1, -v);  }

int main() {
	ll t,n,h,l,r,i ; scanf("%lld",&t);
	while(t--)
	{   scanf("%lld %lld", &n, &h);  ll myarr[n];
		memset(tree,0,(n+1)*sizeof(ll) );
		rupdate(n, 1, n, n);
		 for (i = 0; i<n; i++)	{
          	scanf("%lld %lld", &l,&r);
			rupdate(n, l+1, r+1, -1);  }  
		
		for (i=0; i<n; i++)	myarr[i]= query(n, i+1); 
	    // for (i=0; i<=n; i++) printf("%d ", myarr[i] ); printf("\n");
		ll tmp=0;
		for (i=0; i<h; i++)	tmp+= myarr[i]; 
		ll ans= tmp;   // printf("%d ", ans );
		for (i=h; i<n; i++)	
		{  tmp= tmp-myarr[i-h]+myarr[i]; 
		   ans= min(ans,tmp); // printf("%d ", ans );
		}
	   printf("%lld\n",ans);  
	}
	return 0;
}