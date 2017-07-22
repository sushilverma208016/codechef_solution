#include<iostream>
#include<algorithm>
using namespace std;

int main ()
{
	long long int n,x,y,l;
	cin >> n>>x>>y;
long long 	int a[n+1],b[n+1]; 
		for(long int i=0; i<n+1; i++)
	  {
	 a[i]=0; b[i]=0; } 
	for(long int i=1; i<n+1; i++)
	  {
	  cin >> l;
	  if(l>0)  a[i]=l; }
	  
	   for(long int i=1; i<n+1; i++)
	    {
	  cin >> l;
	  if(l>0)  b[i]=l; }
	   long long int sum=0;
if(n>=1 && (x+y)>=n && x<=n &&y<=n && x>=1 && y>=1) {
for(long int i=1; i<n+1; i++)
	   { if(a[i]>=b[i])
	     { sum=sum + a[i];    
	     }
	     
	     else sum=sum + b[i];
	   }  }

cout<< sum;	

	   
	   
	
	
	
	
	return 0;
}