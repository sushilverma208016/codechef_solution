#include<string>
#include<stdbool.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#define ll long long int
# define MOD 1000000007
using namespace std;


int main()
{  ll t;
   scanf("%lld",&t);
   
   while(t--)
   {  string s;
     cin >>s;
     ll i=0, c=0;
     while(s[i])
      { if(s[i]=='4')
          c++; 
          i++;
      }
      cout<<c<<endl;
   	  
   }
         
     
			 
     
      
       
   
   
	
	
	
	
	return 0;
}