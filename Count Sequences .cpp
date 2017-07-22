#include<iostream>
#include<cstdio>
using namespace std;

long long M = 1000003;
long long Fact[1000004];
long long pow(long long a,long long b,long long M)
{
 if(b == 0)
      return 1;
  long long value = pow(a,b>>1,M)%M;
  if(b%2 == 0)
         return (value*value)%M;
  else
      return ((value*value)%M*(a))%M;     
}
int main()
{
    int t;
    scanf("%d",&t);
    Fact[0] = 1;
    Fact[1] = 1;
    for(int i = 2;i <= M;i++)
            Fact[i] = (Fact[i-1]*i)%M;
    while(t--)
    {
              long long N,K,u,v,w,ans = 1;
              scanf("%lld %lld %lld",&u,&v,&w);
              N= u+w+1-v  ; K= u ;
              long long s = 1;
              while(N>0 || K>0)
              {
                        long long int a = N%M;
                        long long int b = K%M;
                        if (a < b)
			                  {
				                ans = 0;
				                break;
		                  	}
                        long long value = (pow(Fact[b],M-2,M)*pow(Fact[a-b],M-2,M))%M;
                        value = (Fact[a]*value)%M;
                        ans*=value;
                        ans = ans%M;
                        s*=M;
                        N = N-a;
                        K = K-b;
                        N = N/M;
                        K = K/M;
             }
               ans= (ans%M+(M-1)%M)%M;
              printf("%lld\n",ans);
    }
 return 0;    
}