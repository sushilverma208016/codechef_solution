#include <iostream>
using namespace std;


int rank(int M, int N, int  a[][1000], int b[], int p) {
    // M equations, N variables, modulo p
    int ans = 0;
     
    bool used[M] ;
     for(int i=0;i<M;i++){  used[i]=0;
     }
    // Using Gauss-Jordan in [ A : b ] to make it in row-echellon form.
    // So that we can find the rank. We also need to make sure that the
    // rank of [ A ] is equal to the rank of [A : b], else there are
    // no solutions
    for (int j=0; j<N; j++){
        int i = 0;
        while ( (i < M) && (used[i] || (a[i][j] == 0) ) ) {
            i++;
        }
        if(i == M) continue;
        ans++;
        used[i] = true;
        for (int k=0; k<M; k++) if(!used[k]){
            // Find a value of coef equal to (-a[k][j] / a[i][j]);
            // we can just try 0,1,..,p-1 until we find one.
            int coef = 0;
            while ( (a[i][j] * coef + a[k][j]) % p != 0) {
                coef++;
            }
            for (int l=0; l<N; l++) {
                 a[k][l] = (a[k][l] + a[i][l] * coef) % p;
            }
            b[k] = (b[k] + b[i] * coef) % p;
        }
    }
     
    // If rank of [A] is not equal to the rank of [A : b]
    for (int i=0; i<M; i++) {
         if(!used[i] && b[i] != 0) {
              return -1;
         }
    }
          
    return ans;
}
 
  
 
int numberOfExactWays(int number[], int must, int len)
{    int BITS = 10; 
    int n = len;
    int res = 0;
    // make the system of equations
    int M = BITS; //one equation per bit
    int N = n   ; // one variable per card
    int A[M][1000];
    int   b[M] ;
     
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            if ( (number[j] & (1<< i)) != 0) {
                A[i][j] = 1;
            } else {
                A[i][j] = 0;
            }
        }
        if ( (must & (1<< i)) != 0) {
            b[i] = 1;
        } else {
            b[i] = 0;
        }
    }
    // Find the rank of the system of equations:
    int r = rank(M, N, A, b, 2);
    // Number of free variables is equal to N minus rank.
    return (r <= -1) ? 0 : 1;
}
 



int main()
{  int T,N,K;
   cin >> T;
   while(T--)
   {  cin >> N >>K ;
      int a[N];
      for(int i=0;i<N;i++)
         {  cin >> a[i];
         } 
      int comp=1023;
      while(!(numberOfExactWays(a,comp^K,N)) && comp>=K) comp--;
      cout << comp <<endl;  
   }
     

return 0;
}