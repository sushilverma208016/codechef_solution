#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#define ll long long int
#define sc(x) scanf("%lld",&x)
#include <bitset>
using namespace std;

int main(){ 
    ll t; sc(t);
	while(t--)
	{  ll n,k; sc(n); sc(k); ll x,sum=0;
	  for(ll i=0; i<n; i++) { sc(x); sum+= x; }
	  sum=sum%2;
	  if(sum==0 && k==1) printf("odd\n") ;else printf("even\n"); 
	} 
   
    return 0;
}