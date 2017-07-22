#include<string>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#define ll long long int

using namespace std;

int main() { 
     ll te; scanf("%lld",&te);
     while(te--)
     {  string s;
       cin>>s; 
      ll m=s.length() ;
      if(m==1) {printf("YES\n"); continue ; }
       char a=s[0]; char b=s[1]; ll temp;
       if(a==b) {temp=0; printf("NO\n"); continue ; }
       else { temp=1;
         for(ll i=2; i<m; i++)
            { if(i%2==0) 
            { if(s[i]==a)temp=1; else { temp=0; break;} }
            else {
                if(s[i]==b) temp=1; else { temp=0; break;} }
            } 
    if(temp==1) printf("YES\n"); else  printf("NO\n");  }     
            
		
		
		 
        
		 //  printf("%lld %lld\n",a,b);
			//printf("\n"); 
     }
    
	return 0;
}
