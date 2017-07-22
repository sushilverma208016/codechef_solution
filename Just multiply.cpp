#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long int ll;
ll power(ll b, ll e, ll m){
	ll res=1;
	while(e){
		if(e&1){
			res=(res*b)%m;
		}
		e>>=1;
		b=(b*b)%m;
	}
	return res;
}

int main()
{  int t;
   scanf("%d",&t);
   while(t--)
   { ll m; scanf("%lld",&m);
     string str;
     cin>> str;
       ll s=1;
     for(int i=0; i<str.size(); )
          {
          ll num1=0;
		   while(str[i]<='9' && str[i]>='0')
		   { num1=num1*10+ str[i]-'0'; 
		       i=i+1;
		   }
		  i+=2; ll num2=0;
		  while(str[i]<='9' && str[i]>='0')
		   { num2=num2*10+ str[i]-'0'; 
		       i=i+1;
		   }
		   int y=power(num1, num2, m);
		     s=((s%m)*(y%m))%m;
		     i++;
	     }
		  
	  printf("%lld\n",s); 
      
   }
	return 0;
}