# include <iostream>


using namespace std;



int main()
{  int T;
   cin >> T;
   while(T--)
   {   unsigned int N;
    cin >> N;
    float r=0.0;
    for(int i=1; i<=N; i=i+1)
         r=r+(float)1.0/(float)i;
     
	 cout<< (float)N*r<< endl;  
   }
 return 0;

}