#include <iostream>
using namespace std;
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v; 
 
int main()
{ int t ; cin>>t; 
   while(t--)
   {  string s1,s2; int i,l1,l2, mn=0,mx=0;
   cin>>s1; cin>> s2;
   l1= s1.length(); l2=s2.length();
   for(i=0;i<min(l1,l2);i++)
   { if(s1[i]=='?'|| s2[i]=='?') {mx++; }
   else if(s1[i]!=s2[i]&& s1[i]!='?'&& s2[i]!='?') { mx++; mn++; } 
   
   }
    cout<<mn<<" "<<mx<<"\n";
   
   }
    return 0;
}