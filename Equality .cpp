#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#define ll long long int

using namespace std;

int main() { 
     ll t; scanf("%lld",&t);
     while(t--)
     {  ll n; scanf("%lld",&n); ll a[n]; ll sum =0;
         for(ll i=0; i<n; i++)
            { scanf("%lld",&a[i]);  sum+=a[i]; }
         
        sum=sum/(n-1);
        for(ll i=0; i<n; i++)
		    printf("%lld ",sum-a[i]);
			printf("\n"); 
     }
    
	return 0;
}