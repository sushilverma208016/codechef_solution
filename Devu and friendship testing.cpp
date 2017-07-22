#include<string>
#include<stdbool.h>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#define ll long long int
#define MOD 1000000007
#define MAX 10000001
#define sc(x) scanf("%lld",&x);
using namespace std;

ll gcd (ll a, ll b )
{ return (a==0 )?b:(gcd(b%a,a)); }  
ll pow(ll base, ll exp, ll modulus) {
  base %= modulus; ll result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1; }
  return result; }


int main()
{  
   ll t,n,i,x;
   sc(t);
   while(t--)
   { ll ans=0;
   sc(n); ll d[101];for(i=0; i<=100; i++) d[i]=0;
   for(i=0; i<n; i++) { sc(x); d[x]=1; }
   for(i=0; i<=100; i++) if(d[i]==1) ans++;
   printf("%lld\n",ans);
   

   }  
	return 0;
}