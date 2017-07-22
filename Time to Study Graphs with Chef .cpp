#include<string>
#include<stdbool.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#define ll long long int
# define MOD 1000000007
using namespace std;

ll find(ll x, ll y, ll size, ll n) // layer
{  if(x==0) return 0;
   else if(x==size) return (n+1);
 else if(x%y==0) return (x/y) ;
   else return ((x/y)+1);
} 
ll get(ll x, ll y, ll size)   // nth in layer
{  if(x==0 || x==size) return 0;
  else return ((x%y)+(y-1))%y;
}

int main()
{     ll  n,m,k; 
       cin>>n>>m>>k; 
       ll size=n*m+2;
       ll a[k][4]; ll mi[size];
       for(ll i=0; i<size; i++)
           mi[i]=0;
	    mi[size-1]=1;
       for(ll i=0;i<k; i++)
       {  ll l1,v1,l2,v2;
	     cin>>l1>>v1>>l2>>v2;
	      a[i][0]=l1; a[i][1]=v1; a[i][2]=l2; a[i][3]=v2;
	     
       }
      for(ll i=size-2; i>=0; i--)
      { if(find(i,m,size-1,n)==n) 
	      { mi[i]= ( (mi[i] %MOD )+ (mi[size-1] % MOD )) % MOD;
	      } 
	    else {
	     ll st= find(i,m,size-1,n)*m +1; ll end= find(i,m,size-1,n)*m +m; 
	     for(ll j=st; j<=end; j++)
		   { mi[i]= ( ((mi[i] %MOD)+ (mi[j] % MOD))%MOD) % MOD;
		   }   }
      
	     for(ll j=0; j<k; j++)
                { if((a[j][0]==find(i,m,size-1,n) ) && (a[j][1]==get(i,m,size-1)) )
                    { 
                       mi[i] = ( (mi[i]%MOD )+ (mi[(((a[j][2])-1)*m+(a[j][3]+1))] %MOD ) ) %MOD ;
                      }  
                }  
      }
      
    //  for(ll i=0; i<size; i++)
     //      printf("%lld\t",mi[i]%MOD);
      
   	  printf("%lld\n",mi[0]%MOD);
   
         
     
			 
     
      
       
   
   
	
	
	
	
	return 0;
}