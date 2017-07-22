#include<vector>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#define ll long long int
#define sc(t) scanf("%lld",&t);
#define mod 1000000007
using namespace std;

int main() {
     ll t; scanf("%lld",&t);
     while(t--)
     {ll n; sc(n); ll a[n],b[n]; ll c=0;
      for(ll i=0; i<n; i++) { sc(a[i]);  b[i]=0;}
       for(ll i=1; i<n; i++) 
       { if(a[i-1]!=a[i]) { b[i-1]=1; b[i]=1;
          }
       }
     for(ll i=0; i<n; i++) if(b[i]==1) c++;

		  printf("%lld\n",c); 
     }
 
	return 0;
}