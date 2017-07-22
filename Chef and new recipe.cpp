#include<string>
#include<stdbool.h>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#define ll long long int
using namespace std;

int main()
{  
 int t;
  cin>>t;
  while(t--)
  { ll  n;
    cin>>n; 
	ll a[n];  ll sum=0,min=1000000; ll l=1;
	for(int i=0; i<n; i++) { 
    cin>>a[i]; if(a[i]<2)l=0; sum+=a[i]; if(min>a[i]) min=a[i];  }  
    
    sum=sum-min+2; 
   
   if(l==0) cout<<"-1"<<endl;
    else cout<<sum<<endl;
    
    
  }
        
	return 0;
}