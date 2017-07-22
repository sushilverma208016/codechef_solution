#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long int ll;

int main()
{  int t;
   scanf("%d",&t);
   while(t--)
   { int a[26]={0};
   string str; int y=0;
     cin>> str;
     //cout<<str<<endl;
     for(int i=0; i<str.size(); i=i+1)
         {   int  x=str[i]-'a';  //printf("%d\t",x);  
		    a[x]=a[x]+1;
         }   
     sort(a,a+26);
     // for(int i=0;i<26; i++) printf("%d\t",a[i]);  
     for(int i=0;i<=24; i++)
        y+=a[i];
	if(y==a[25]) printf("YES\n");
	  else  printf("NO\n");   
      
   }
	return 0;
}