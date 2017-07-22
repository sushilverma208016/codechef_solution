# include<iostream>
# include<algorithm>
# include<stdio.h>
#include <stdlib.h>
#define gc getchar_unlocked
#define ull unsigned long long int
using namespace std;
void scanint(ull &x)
{   register ull c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
	 for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;} }

 int main()
 { ull m,q,l,r,x,k,y;
   scanint(m);
   ull a[m]; ull emp=0;		  
   while(m--)
   { scanint(q);
      if(q==0){ scanint(x); a[emp]=x; emp++; //for(ull i=0;i<emp;i++) printf("%lld\t",a[i]);  printf("\n");
	               }
     else if(q==1){ scanint(l); scanint(r); scanint(x);   ull xr=0; 
	        for(ull i=l-1; i<r;i++) 
			{  if((a[i]^x)>xr) { xr= (a[i]^x); y=a[i];  }  }
		      printf("%lld\n",y);	 }
	 else if(q==2){ scanint(k); emp=emp-k;    }	 
	 else if(q==3){  scanint(l); scanint(r); scanint(x); ull co=0; 
	        for(ull i=l-1; i<(r);i++) 
	           if(a[i]<=x) co++;    printf("%lld\n",co);
			 }	
	 else if(q==4){ scanint(l); scanint(r); scanint(k); ull b[r-l+1];
	     for(ull i=0;i<(r-l)+1;i++) b[i]=a[i+l-1];
	       sort(b,b+(r-l+1));   //    for(ull i=0;i<(r-l)+1;i++) printf("%lld\t",b[i]);  printf("\n");
		     printf("%lld\n",b[k-1]);
	           }	 		       
    }
 	return 0;  
 }