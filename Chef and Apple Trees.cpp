#include <stdio.h>  

void counting(long int A[], long int k, long int N)

{

   long int i, j, counter=0;

    int C[k+1];

    for (i = 0; i <= k; i++)

        C[i] = 0;

    for (j = 1; j <= N; j++)

        C[A[j]] = 1;
      for (i = 1; i <= k; i++)
    { if(C[i]!=0) counter++;  }
        printf("%ld ", counter);

}

int main()

{

    int T;
    long int N, i, k=0;
    scanf("%d", &T);
    while(T)
{   
	scanf("%ld", &N);
    	long int A[N+1];
    for (i = 1; i <= N; i++)

    {

        scanf("%ld", &A[i]);

        if (A[i] > k) {

            k = A[i];

        }

    }

    counting(A, k, N);

    printf("\n");
    T--;}

    return 0;

}