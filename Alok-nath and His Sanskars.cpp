#include <stdio.h>
#include <stdbool.h>
 
bool isSubsetSum (unsigned long long int arr[], unsigned long long int n, unsigned long long int sum)
{
   // Base Cases
   if (sum == 0)
     return true;
   if (n <=0)
     return false;
 
   // If last element is greater than sum, then ignore it
   if (arr[n-1] > sum)
     return isSubsetSum (arr, (n-1), sum);
 
   /* else, check if sum can be obtained by any of the following
      (a) including the last element
      (b) excluding the last element
   */
   if(isSubsetSum (arr, (n-1), sum))
       return true;
   if(isSubsetSum (arr, (n-1), (sum-arr[n-1]))){
   	  //  printf("%ld\t",arr[n-1]); 
   		arr[n-1]=0L;
   	//	printf("%ld\t",arr[n-1]);            
   		return true;
   }
     return false;
  // return isSubsetSum (arr, n-1, sum) || isSubsetSum (arr, n-1, sum-arr[n-1]);
}

int main()
{ int T;
   scanf("%d",&T);
   while(T--){ unsigned long int i,N,K;
   scanf("%ld%ld",&N,&K); 
   unsigned long long int a[N];
   for(i=0;i<N;i++)
   { scanf("%lld",&a[i]);
   }
  
    unsigned long long sum = 0;
    for ( i = 0; i < N; i++)
       sum += a[i];
       unsigned long long int x=sum/K;
       if (N<K)
      {
       printf("no\n");  continue;}
        if (K==1)
      {
       printf("yes\n");  continue;}
      if ((sum%K) != 0)
      {
       printf("no\n");  continue;}
      
      for(i=1;i<=K;i++)
	  { if(!(isSubsetSum (a, N, x)) )   {
       printf("no\n");  break;}
	    if(i==K)   
        printf("yes\n"); 
	  }  
 }
  
  return 0;
}