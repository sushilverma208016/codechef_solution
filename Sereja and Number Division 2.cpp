# include<iostream>
# include<string>
# include<stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
 
 int main()
 { int t;
   scanf("%d",&t); 
   while(t--)
   {   string line;
       cin>>line;
       int n,i;
       scanf("%d",&n); 
       int b[n];
       for(i=0;i<n;i++) scanf("%d",&b[i]); 
       size_t found = line.find('0');
     if (found!=string::npos)
         {  char lastChar = *line.rbegin();
            line[found]=lastChar;
            int x=line.size();
           line.at(x-1)='0';
         }
	   cout<<line<<endl;
  }
 	return 0;
 }