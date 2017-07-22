#include <bits/stdc++.h>
#define int long long int
using namespace std;
struct Val {
    int d,t,s;
};
bool comp(Val i1, Val i2) {
    return (i1.d==i2.d)?(i1.s>i2.s):(i1.d<i2.d);
}

int32_t main() {
	int t, n, d, i;
	scanf("%lld\n",&t);
	while (t--) {
	    scanf("%lld %lld\n",&n,&d);
	    Val arr[n]; 
	    int total=0;
	    pair<int, int> pr;
	    for (i=0; i<n; i++) {
	        scanf("%lld %lld %lld\n", &arr[i].d, &arr[i].t, &arr[i].s);
	        total+= (arr[i].t*arr[i].s);
	    }
	    int l= sizeof(arr)/sizeof(arr[0]), p=1;
	    sort(arr, arr+l, comp);
	    priority_queue<pair<int, int> > q;
	    
	    for (i=1; i<=d; i++) {
	        while (p<=n && arr[p-1].d<i) p++;
	        while (p<=n && arr[p-1].d==i) {
	            pr.first= arr[p-1].s, pr.second= arr[p-1].t;
	            q.push(pr);
	            p++;
	        }
	        if (!q.empty()) {
	            pr= q.top();
	            q.pop();
	            total-= pr.first;
	            if (pr.second>1) {
	                pr.second--;
	                q.push(pr);
	            }
	        }
	    }
	    printf("%lld\n",total);
	}
	return 0;
}