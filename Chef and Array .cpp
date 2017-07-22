#include<iostream>
#include<algorithm>
using namespace std;
#include<string.h>
#include<stdio.h>
#include<math.h> 
#define ll long long int

void build_tree(ll node, ll a, ll b,ll arr[], ll tree[]) {
if(a > b) return; // Out of range
if(a == b) { // Leaf node
tree[node] = arr[a]; // Init value
return;
}
build_tree(node*2, a, (a+b)/2, arr,tree); // Init left child
build_tree(node*2+1, 1+(a+b)/2, b, arr,tree); // Init right child
tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}
//
//void update_tree(ll node, ll a, ll b, ll i, ll j, ll value) {
//if(a > b || a > j || b < i) // Current segment is not within range [i, j]
//return;
//if(a == b) { // Leaf node
//tree[node] += value;
//return;
//}
// 
//update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
//update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child
// 
//tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
//}

ll query_tree(ll node, ll a, ll b, ll i, ll j, ll arr[], ll tree[]) {
if(a > b || a > j || b < i) return -1; // Out of range
if(a >= i && b <= j) // Current segment is totally within range [i, j]
return tree[node];
ll q1 = query_tree(node*2, a, (a+b)/2, i, j, arr,tree); // Query left child
ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j, arr, tree); // Query right child 
ll res = max(q1, q2); // Return final result
return res;
}
 
int  main() {   
	 ll n; scanf("%lld",&n);  ll arr[n];  
	  ll tree[2*n+3];  
     for(ll i = 0; i <n; i++) scanf("%lld",&arr[i]);
     build_tree(1, 0, n-1, arr, tree) ;
     ll u,v,f,s, sum=0;
	 ll m, x1,y1,x2,y2 ; scanf("%lld %lld %lld",&m,&x1,&y1);  
	   u=min(x1,y1); v=max(x1,y1); f=min(u,v); s=max(u,v);
	 
	   if(f==s) sum+= arr[f];
	      else sum += query_tree(1, 0, n-1, f,s, arr,tree); 
	 for(ll i =2; i <=m; i++) 
	    { x2= (x1 %(n-1) +7%(n-1))%(n-1);
		  y2= (y1 %n +11%n)%n;
		  u=min(x2,y2); v=max(x2,y2);  f=min(u,v); s=max(u,v);
		  if(f==s) sum+= arr[f];
		  else if(f==0 && s==n-1) sum+=tree[1];
		   else sum += query_tree(1, 0, n-1, f,s, arr,tree); 
		  x1=x2; y1=y2;
	    }
	 
     printf("%lld\n",sum);
     return 0;
} 