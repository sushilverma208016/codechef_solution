#include <stdio.h>
#include <stdlib.h>
typedef long long int lli;
lli m= 1000000007;

int cmpfunc (const void *a, const void *b) {
   return (*(lli *)a-*(lli *)b);
}
lli last(lli arr[], lli low, lli high, lli x, lli n) {
    if (high>=low) {
        lli mid=low+(high-low)/2;
        if (( mid==n-1 || x<arr[mid+1]) && arr[mid]<=x) return mid;
        else if (x<arr[mid]) return last(arr, low, (mid -1), x, n);
        else return last(arr, (mid + 1), high, x, n);
    }
    return -1;
}

int main() {
   lli t, p ,q, r, i;
   scanf("%lld", &t);
   while(t--) {
       scanf("%lld %lld %lld", &p,&q,&r);
       lli a[p], b[q], c[r];
       for (i=0; i<p; i++) scanf("%lld", &a[i]);
       for (i=0; i<q; i++) scanf("%lld", &b[i]);
       for (i=0; i<r; i++) scanf("%lld", &c[i]);
       qsort(a, p, sizeof(lli), cmpfunc);
       qsort(b, q, sizeof(lli), cmpfunc);
       qsort(c, r, sizeof(lli), cmpfunc);
       
       //for (i=0; i<p; i++) printf("%lld ",a[i]); printf("\n");
       //for (i=0; i<q; i++) printf("%lld ",b[i]); printf("\n");
       //for (i=0; i<r; i++) printf("%lld ",c[i]); printf("\n");
       
       lli suma[p], sumc[r], sum=0; suma[0]=a[0]%m, sumc[0]=c[0]%m;
       
       for (i=1; i<p; i++) suma[i]= (suma[i-1]+a[i]%m)%m;
       for (i=1; i<r; i++) sumc[i]= (sumc[i-1]+c[i]%m)%m;
       
       //for (i=0; i<p; i++) printf("%lld ",suma[i]); printf("\n");
       //for (i=0; i<r; i++) printf("%lld ",sumc[i]); printf("\n");
       
        for (i=0; i<q; i++) {
            lli ele= b[i];
            lli ia= last(a, 0, p-1, ele, p);
            lli ic= last(c, 0, r-1, ele, r);
            ele= ele%m;
            if ((ia!=-1) && (ic!=-1)) {
                lli tmp= ( (suma[ia]+((ia+1)*ele)%m)%m * (sumc[ic]+((ic+1)*ele)%m)%m )%m ;
                sum= (sum+tmp)%m;
            }
        }
        printf("%lld\n",sum);
   }
   return(0);
}