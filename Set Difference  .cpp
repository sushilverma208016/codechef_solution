#include<string>
#include<stdbool.h>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#define ll long long int
#define M 1000000007
using namespace std;

int main()
{ int pow[100000];
  int x=1; 
 for(int i=0; i<100000; i++) { 
      x=x<<1; x=x%M;  pow[i]=(x+M-1)%M; }//printf("%d ",pow[i]); } 
  // for(int i=0; i<10; i++) printf("%d ",pow[i]); 
   ll t;
  scanf("%lld",&t);
  while(t--)
  { ll  n;
    scanf("%lld",&n);
	ll a[n];  ll sum=0;
	for(ll i=0; i<n; i++) { 
    scanf("%lld",&a[i]);  }  
    sort(a,a+n);
    ll sum1=0,sum2=0;  ll i,j;
    for(i=1,j=0; i<n; i++,j++) { 
	  //  sum1= sum1+ a[i]*pow[j] ; printf("%lld\n",sum1);
      //  sum2=sum2+ a[n-i-1]* pow[j] ; printf("%lld\n",sum2);  } 
		sum1= (sum1%M+ (a[i]%M*(pow[j]%M))%M )%M  ; 
        sum2=(sum2%M+ (a[n-i-1]%M*(pow[j]%M) )%M )%M  ; }
    ll ans;  ans= (sum1+M-sum2)%M ;
    printf("%lld\n",ans);
    
  
  }
	return 0;
}