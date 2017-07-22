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
     {  string str; cin>>str; ll ans,k,q,r,s=0;
         for(ll i=0; i<str.size(); i++)
            { if(str[i]=='T') s=s+2;
               else if(str[i]=='S') s=s+1;  }
         scanf("%lld",&k); k=12*k;
         q=k/s; r=k%s; 
         ans= s* (((q-1)*q)/2)  + q*r ;
         
		 printf("%lld\n",ans); 
     }
    
	return 0;
}