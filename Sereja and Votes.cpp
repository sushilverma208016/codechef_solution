# include<iostream>
using namespace std;
 
 int main()
 { int t;
   cin >> t;
   while(t--)
   {  long int i,n,x,mark=0,zero=0,z=0;
   cin >> n;
   long int sum=0;
   for(i=0;i<n;i++)
     {  cin >> x;
        if(x>100) {mark=1; }
        if(x==0) {zero=1; z++; }
        sum=sum+x;
     } 
    // if(mark==1) { cout<<"NO"<<endl; continue;}
  if(sum>=100 && sum<=(99+n) && mark==0 && zero==0 ) { cout<<"YES"<<endl;}
    else if(zero==1 && sum>=100 && sum<=(99+n-z) && mark==0) { cout<<"YES"<<endl;}
    else  { cout<<"NO"<<endl;}
     }
 	return 0;
 }