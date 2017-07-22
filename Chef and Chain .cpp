#include<string>
#include<stdbool.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#define ll long long int
using namespace std;

int main()
{  
   int t;
   scanf("%d",&t);
   while(t--)
   {  string strg;
       cin>> strg;
       ll n=strg.size();
      // printf("%lld\n",n);
       ll res;
        ll c0=0; ll c1=0; bool temp; bool z1=1; bool z0=0;
       if(n==1)  { printf("0\n"); continue;
                           }
       for(ll i=0; i<n; i++)
       {   char charac=strg[i];
           if(charac=='+') temp=1; else  temp=0;
          // printf("%d\n",temp);
          //printf("%d\n",z0);
          //printf("%d\n",z1);
           if((temp^z0)==1) c0++;
           if((temp^z1)==1) c1++;
           if(z0==1) z0=0; else z0=1;
		   if(z1==1) z1=0; else z1=1;         
       }
        res= min(c0,c1);
      // printf("%lld\n",c0);
	  // printf("%lld\n",c1); 
       printf("%lld\n",res);
   }
   
	
	
	
	
	return 0;
}