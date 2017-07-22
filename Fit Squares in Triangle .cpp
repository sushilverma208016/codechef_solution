#include<string>
#include<stdbool.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#define ll long long int
using namespace std;

int main()
{  
   ll t,d,n,r;
   scanf("%lld",&t);
   while(t--)
   {  scanf("%lld",&n);
       d=n/2;
       if(d==0)  {  printf("0\n"); continue;}
       
       d=d-1;
        r=d*(d+1)/2;
        printf("%lld\n",r);
   }
   
	
	
	
	
	return 0;
}