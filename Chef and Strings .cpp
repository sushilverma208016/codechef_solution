#include<string>
#include<stdbool.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#define ll long long int
# define MOD 1000000007
using namespace std;


int main()
{  ll q;
   string p;
   cin>> p;
   ll z=p.size();
   // printf("%lld\n",z);
   scanf("%lld",&q);
   ll c[z+2], h[z+2], e[z+2], f[z+2]; c[z]=0; h[z]=0; e[z]=0; f[z]=0; c[z+1]=0; h[z+1]=0; e[z+1]=0; f[z+1]=0;
   for(ll i=z-1; i>=0; i-- )
     {  c[i+1]=c[i+2]; h[i+1]=h[i+2]; e[i+1]=e[i+2]; f[i+1]=f[i+2]; 
	    if(p[i]=='c') c[i+1]++;
	    else if(p[i]=='h') h[i+1]++;
	   else if(p[i]=='e') e[i+1]++;
	   else if(p[i]=='f') f[i+1]++;
     }
     c[0]=c[1]; f[0]=f[1]; e[0]=e[1]; h[0]=h[1];
    // for(ll i=0; i <z+2; i++)
    //       printf("%lld\t",c[i]); printf("\n--------\n");     
    //  for(ll i=0; i <z+2; i++)
    //       printf("%lld\t",h[i]); printf("\n--------\n");   
    //  for(ll i=0; i <z+2; i++)
    //       printf("%lld\t",e[i]); printf("\n--------\n");  
//	for(ll i=0; i <z+2; i++)
   //        printf("%lld\t",f[i]);printf("\n--------\n");  	   		      
     
   while(q--)
   {
        ll  l,r,sum=0; char x,y; // string t;
       cin>>x>>y>>l>>r;
       
    
      // printf("%c %c %lld %lld\n",x,y,l,r);
       for (ll i=l-1; i<=r-1; i++)
         { if(p[i]==x) 
            { // printf("enter "); 
			 if(y=='c') sum= sum+ (c[i+2]-c[r+1]); 
              else if(y=='h') sum =sum+ (h[i+2]-h[r+1]); 
              else if(y=='e') sum= sum+ (e[i+2]-e[r+1]); 
			  else if(y=='f') sum= sum+ (f[i+2]-f[r+1]);  
            }
         }
   	  printf("%lld\n",sum);
   }
         
     
			 
     
      
       
   
   
	
	
	
	
	return 0;
}