#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long int ll;

int main()
{  int t;
   scanf("%d",&t);
   while(t--)
   {  int n,d;
     scanf("%d %d",&n,&d);
     
   if(n<=2){ll s=0; int j=0; int a[n];  for(int x=0; x<n;x++) a[x]=0;
     for(ll i=1; i<=(n*(d-1)); i++)
       {  a[j]++; j=(j+1)%n;  ll y=0;
          for(int x=0; x<n;x++)
             y=y^a[x];
         s+= i*y;
       } 
	        
      printf("%lld\n",s); }
    else{ ll s=0; int j=0; int a[n];  for(int x=0; x<n;x++) a[x]=0; 
       for(ll i=1; i<=(n*(d-1)); i++) 
       {  if(a[j]==d-1) j++;
	        a[j]++; ll y=0;
             for(int x=0; x<n;x++)
             y=y^a[x];
         s+= i*y;
       } 
       printf("%lld\n",s); 
    }  
      
   }
	return 0;
}