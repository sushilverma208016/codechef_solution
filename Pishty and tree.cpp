#include <bits/stdc++.h>
#define int long long int
using namespace std;
const int MAX= 5000005;
int bit[MAX], tym, L[MAX], R[MAX], ans[MAX];
vector<int> G[MAX];
map< pair<int, int>, int> edge;
struct Query { int u, v, w, idx; };
struct ArrayElement { int u, v, w; };
bool cmp1(Query q1, Query q2) { return q1.w<q2.w; }
bool cmp2(ArrayElement a1, ArrayElement a2) { return a1.w<a2.w; }
ArrayElement arr[MAX];
Query queries[MAX];

int read(int idx) {
    int result= 0;
    while(idx>0){
        result ^=  bit[idx];
        idx -= ( idx & -idx );
    }
    return result;
}
void update (int idx, int new_val){
    while(idx<MAX){
        bit[idx] ^=  new_val;
        idx += ( idx & -idx );
    }
}
void dfs(int u, int p= -1){
	L[u]= ++tym;
	for(int i=0; i<G[u].size(); i++){
		int v= G[u][i];
		if(v==p) continue;
		dfs(v, u);
	}
	R[u]= tym;
}
 
int32_t main() {
    int t, n, q, i, j, u, v, w, wt;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld",&n);
        tym= 0;
        memset(L, 0, MAX);
        memset(R, 0, MAX);
        memset(ans, 0, MAX);
        memset(bit, 0, MAX);
        for(i=0; i<MAX; i++) G[i].clear();
        edge.clear();
        for(i=0; i<n-1; i++){
        	scanf("%lld %lld %lld",&u, &v, &w);
        	if(u>v) swap(u, v);
        	pair<int, int> e= make_pair(u,v);
        	edge[e]= 0;
        	arr[i].u=u, arr[i].v=v, arr[i].w=w;
        	G[u].push_back(v);
        	G[v].push_back(u);
        }
        dfs(1);
        scanf("%lld",&q);
        for(i=0; i<q; i++) {
            scanf("%lld %lld %lld",&u, &v, &w);
            if(u>v) swap(u, v);
            queries[i].u=u, queries[i].v=v, queries[i].w=w, queries[i].idx=i;
        }
        sort(arr, arr+n-1, cmp2);
        sort(queries, queries+q, cmp1);
        //for(i=0; i<n-1; i++) printf("%d %d %d\n", arr[i].u, arr[i].v, arr[i].w);
        //for(i=0; i<q; i++) printf("%d %d %d\n", queries[i].u, queries[i].v, queries[i].w);
        int curr= 0;
        for(i=0; i<q; i++) {
            while(curr<n-1 && arr[curr].w<=queries[i].w) {
                u=arr[curr].u, v=arr[curr].v, w=arr[curr].w;
                //printf("%d %d %d\n", u, v, w);
                map< pair<int, int>, int>::iterator it= edge.find(make_pair(u,v));
                if (it!= edge.end()) wt= it->second;
                update(L[v], wt);
                update(R[v]+1, wt);
                it->second= w;
                update(L[v], w);
                update(R[v]+1, w);
                curr++;
            }
            u=queries[i].u,v=queries[i].v;
            ans[queries[i].idx]= read(L[u])^read(L[v]);
        }
        for(i=0; i<q; i++) printf ("%lld\n",ans[i]);
    }
    return 0;
}