#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, t; 
	scanf("%d",&t);
	while(t--)
	{  scanf("%d",&n);  int st[n*n+1]; int en[n*n+1];
	  for(int i=1; i<=n; i++)
	    {  for(int j=1; j<=n; j++)
	     {   scanf("%d",&x);
	         st[x]= i; en[x]= j; 
	     }
	    }
	    int sum=0; 
	  for(int i=2; i<=n*n; i++)
	   {  sum+= ( abs(st[i]-st[i-1]) + abs(en[i]-en[i-1]) ) ;
	       
	   }
	  printf("%d\n",sum );  
	}
	return 0;
}