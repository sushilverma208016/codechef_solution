#include<string>
#include<stdbool.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#define ll long long int
using namespace std;

int main()
{  ll t;
   scanf("%lld",&t);
   
   while(t--)
   { ll x,y,k,n,f=0;
    scanf("%lld %lld %lld %lld",&x,&y,&k,&n);
      ll p[n], c[n];
      for(int i=0; i<n;i++)
         scanf("%lld %lld",&p[i],&c[i]);
       if(x<=y) { cout<<"LuckyChef\n"<<endl; continue;  } 
	   if((x-y)> *max_element(p,p+n)) { cout<<"UnluckyChef\n"<<endl; continue; } 
     for(int i=0; i<n;i++)
     { if((x-y)<=p[i] && k>=c[i]) f=1;
     }
   	  if(f==0) cout<<"UnluckyChef"<<endl;
   	   else  cout<<"LuckyChef"<<endl;
   	  
   }
        
	return 0;
}