#include<iostream>
#include<algorithm>
using namespace std;

int main()
{   int t,n,i;
    cin>>t;
    while(t--)
    {  cin>> n; int a[n];int sum=0;
       for(i=0;i<n;i++)
        cin >> a[i];
         sort(a,a+n); 
       if(n==1) { cout<<a[0]<<endl; continue; }
      else if(n==2) { cout<<a[0]+a[1]<<endl; continue;}
       else if(n==3) { cout<<a[2]+a[1]<<endl; continue;}
       else if(n==4) { cout<<a[2]+a[3]<<endl; continue;}
        //sort(a,a+n); 
       for(i=n-1;i>=0;i=i-4)
	      { if(i>=0) { sum=sum+a[i] ;}
		     if((i-1)>=0) { sum=sum+a[i-1] ;  }    }
	     cout<<sum<<endl;   
       
		  
       
    }
	
	return 0;
}