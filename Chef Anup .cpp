#include <iostream>
#include <stdio.h>
#define ll long long int
using namespace std;

int main() {
     ll t; scanf("%lld",&t);
     while(t--)
     { ll n,k,l;
       scanf("%lld %lld %lld",&n,&k,&l);
       ll a[n];ll b[n];
       for(ll i=0; i<n; i++) a[i]=0;
      ll  index = n-1 ;
      while (l!= 0 )
        {
      ll r= l%k ;  // assume K > 1
         l=l/k;  // integer division
         a[index] = r;
       index-- ;
        }
        ll x=index;ll  i=n-1;
        while(a[i]==0) {b[i]=k; i--; } 
         b[i]=a[i]; i--;
        for( ; i>x; i--) 
        { b[i]=a[i]+1; }
        for(ll i=0; i<=x; i++) b[i]=1;   
        for(ll i=0; i<n; i++) printf("%lld ",b[i]);  printf("\n"); 
      //  printf("%lld ",x);   
     }
 
	return 0;
}