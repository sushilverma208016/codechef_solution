# include <iostream>


using namespace std;



int main()
{  int T;
   cin >> T;
   while(T--)
   {   int N;
    cin >> N;
     int x[N+1],y[N+1];
	 for(int i=1; i<N+1; i++) 
	   {  cin >> x[i] >> y[i];
	   }
	   int r=0;
	 for(int i=1;i<=N; i=i+1)
	   { r= r^i;
	   }  
	 cout<< r<< endl;  
   }
 return 0;

}