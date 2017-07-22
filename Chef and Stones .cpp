# include<iostream>
using namespace std;
 
 int main()
 { int t;
   cin >> t;
   while(t--)
   {  long int i,n;
   cin >> n;
     long long int k,y, x,a[n], b[n],r=0;
     cin >>k;
     for(i=0;i<n;i++)
       {  cin >> a[i]; }
  
    for(i=0;i<n;i++)
       {  cin >> b[i]; }
     for(i=0;i<n;i++)
       {  x=k/a[i];
          y=x*b[i];
	     if(y>=r) r=y;    
	    }  
       
   
    cout << r<< endl;
   }

 	return 0;
 }