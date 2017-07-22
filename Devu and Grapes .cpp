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

int max_ele(int a[])
{ int m=0,mi=0; for(int i=0; i<26; i++) { if(a[i]>m) { m=a[i]; mi=i; } }  return mi;  }
  


int main()
{  
   ll t,n,k,x;
   sc(t);
   while(t--)
   { sc(n); sc(k);ll a[n];  ll r,m, sum=0;
      for(ll i=0; i<n; i++)
	  { sc(x); a[i]=x;
	    r=x%k;
	    m=min(r,k-r);
	    if((x-m)==0) sum+=max(r,k-r); else sum+=m; }
	   
	  // for(ll i=0; i<n; i++) printf("%lld ",a[i]);
     printf("%lld\n",sum);
   }  
	return 0;
}