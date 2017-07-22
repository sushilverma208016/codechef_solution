#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#define ll long long int

using namespace std;

int main() { 
     ll te; scanf("%lld",&te);
     while(te--)
     {  ll n,m,k,x,y; scanf("%lld %lld %lld",&n,&m,&k); ll mark[n+1];  for(ll i=0; i<n+1; i++) mark[i]=0;
         for(ll i=0; i<m; i++)
            { scanf("%lld",&x);  mark[x]=1;  } 
             for(ll i=0; i<k; i++)
            { scanf("%lld",&y); if(mark[y]==1) mark[y]=2; else mark[y]=1; } 
        ll a=0,b=0;
		for(ll i=1; i<n+1; i++) 
		{  if(mark[i]==0) b++;
		  else if(mark[i]==2) a++;
		}
		
		 
        
		    printf("%lld %lld\n",a,b);
			//printf("\n"); 
     }
    
	return 0;
}