#include<string>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
typedef long long int ll ;
using namespace std;

int main()
{  
   ll n,m,temp1,temp2; ll sum =0L;  ll tem=1L;
   scanf("%lld %lld",&n,&m);    ll a[n],b[n], c[n];
   for(ll i=0L; i<n; i++)
     {  scanf("%lld",&a[i]);
         c[i]=a[i]+1L;
          b[i]=0L;
	    }
      sort(a,a+n);
      sort(c,c+n);
      if(m==1L) { printf("O\n"); return 0; }
      
      
      if(c[0]<m) 
     { for (ll i = 1L; i<=c[0] ; i++) 
         tem = ((tem %m)* i) %m;
      b[0]=tem%m;  }
      
      for(ll i=1L; (i<n)&& (c[i]<m);i++)
      {  tem=b[i-1];
        
        if(c[i-1]==c[i]) b[i]=b[i-1];
         else {
         	for(ll j=(c[i-1]+1L); j<=c[i]; j++)
             tem = ((tem %m)* (j%m)) %m;
          b[i]=tem%m;   }
      	
      }
         
      
     
    
	  //for(ll i=0; i<n ; i++)//
       //  cout<< b[i]<< "\t";
     
	 for(ll i=0L; i<n; i++)
       {  if(a[i]==m) temp1=0L;
          else {
          	
       	     if(a[i]%2L==0L)
              temp1= ((((a[i]/2)%m*((a[i]+1)%m)%m))*(a[i]%m))%m;
            else 
               temp1= ((((a[i])%m*(((a[i]+1)/2)%m)%m))*(a[i]%m))%m;
           temp1=temp1%m;  }
              // cout<< temp1<< "\t";
    
            temp2= (b[i]%m +(m-1)%m )%m; 
            temp2=temp2%m;
            sum=((sum%m+temp1%m)%m+temp2%m)%m;
            sum=sum%m; 
            
        } 
        
    // while(sum<0)
      // { sum=sum+m;  }
      
     printf("%lld\n",sum);
   
   
	
	
	
	
	return 0;
}