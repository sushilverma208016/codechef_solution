#include <bits/stdc++.h>
#define ll long long int 
using namespace std;

int main() {
	ll t; 
	scanf("%lld",&t);
	while(t--)
	{  ll n,i,j ,m; 
	   scanf("%lld %lld",&n,&m);  ll a[m]; ll one=1; 
	   for(i=0; i<m; i++) 
	     {scanf("%lld",&a[i]); if(a[i]!=1) one=0; }
	  if(one==1){ printf("%lld\n",n/2 ); continue;  }  
	  sort(a,a+m);
	  if(a[0]>=m-1) { printf("%lld\n",m-1 ); continue;  }  
	  ll l = m ; ll sum=0 ; 
	  for(i=0; i<m; i++)
	  {  if(l-1<=a[i]) {sum=sum+ (l-1); break; }
	      l= l-a[i]-1; sum=sum+ a[i];  
	  }
	  
	    
	  printf("%lld\n",sum );  
	}
	return 0;
}