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
   {   ll a[100001]; ll n,i,x,maxm=0,res; 
       for(i=0; i<100001;i++)  a[i]=0;
       scanf("%lld",&n);
       for(i=0; i<n; i++)
       {  scanf("%lld",&x);
	      a[x]=a[x]+1;        
       }
       for(i=0; i<100001;i++)
         if(a[i]>maxm) maxm=a[i];
	    res=n-maxm;
       printf("%lld\n",res);
   }
   
	
	
	
	
	return 0;
}