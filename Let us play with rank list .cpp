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
   {   ll n,s,i=1;
       scanf("%lld %lld",&n,&s);
       //printf("%lld\n",n);printf("%lld\n",s);
       if(n==s){ printf("%lld\n",(n-1)); continue; }
       if(s==(((n+1)*n)/2)){ printf("0\n"); continue; } 
       
       while((n+(i*(i-1)/2))<=s)
       {  i++;
       }
       // printf("%lld\n",i);
       printf("%lld\n",(n-(i-1)));
   }
   
	
	
	
	
	return 0;
}