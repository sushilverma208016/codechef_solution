     # include<iostream>
    # include<stdio.h>
    # include<map>
    # include<stdint.h>
    using namespace std;
    void countSort(int arr[][2], int n, int exp)
    { int output[n][2]; // output array
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
    count[(arr[i][0]/exp)%10]++;
    for (i = 1; i < 10; i++)
    count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    { output[count[ (arr[i][0]/exp)%10 ] - 1][0] = arr[i][0];
    output[count[ (arr[i][0]/exp)%10 ] - 1][1] = arr[i][1];
    count[ (arr[i][0]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
    { arr[i][0] = output[i][0];arr[i][1] = output[i][1]; }
    }
    void radixsort(int arr[][2], int n,int m)
    { for (int exp = 1; m/exp > 0; exp *= 10)
    countSort(arr, n, exp);
    }
     
    int main()
    {
    int t;
   scanf("%d",&t);
    while(t--){
    long int n,i,count;
    scanf("%ld",&n);
    int x,y,a,b,c,d;
    int ar[n][2];
    int maxm=0;
    for(i=0;i<n;i++)
    { scanf("%d%d",&ar[i][0],&ar[i][1]);
    if(ar[i][0]>maxm) maxm=ar[i][0];
    }
    radixsort(ar,n,maxm);
    a=-1;
    b=-1;
    count=0;
    for (int it=0; it<n; it++)
    { c=ar[it][0]; d=ar[it][1];
    if(b>=c) {a=c; if(b>d) b=d; }
    else {count++; a=c; b=d; }
    }
    printf("%ld\n",count);
    }	return 0;
    } 