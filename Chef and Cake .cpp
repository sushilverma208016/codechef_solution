#include<string>
#include<stdbool.h>
#include<math.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
#define ll long long int
# define MOD 1000000007
# define MAX 10000001
ll arr[MAX]; ll qr[MAX][2]; ll tree[2*MAX+3]; 
using namespace std;


void build_tree(ll node, ll a, ll b,ll arr[], ll tree[]) {
if(a > b) return; // Out of range
if(a == b) { // Leaf node
tree[node] = arr[a]; // Init value
return; }
build_tree(node*2, a, (a+b)/2, arr,tree); // Init left child
build_tree(node*2+1, 1+(a+b)/2, b, arr,tree); // Init right child
tree[node] = min(tree[node*2], tree[node*2+1]); // Init root value
}

ll query_tree(ll node, ll a, ll b, ll i, ll j, ll arr[], ll tree[]) {
if(a > b || a > j || b < i) return MOD+1; // Out of range
if(a >= i && b <= j) // Current segment is totally within range [i, j]
return tree[node];
ll q1 = query_tree(node*2, a, (a+b)/2, i, j, arr,tree);  // printf("%ld ",q1); 
ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j, arr, tree); //printf("%ld ",q2);
ll res = min(q1, q2); // Return final result
return res;
}
 

int main()
{  
   long long int i,j, temp,n,k,q; long long int L,R, A, b, c, d, e, f, r, s, t, m,L1, La, Lc, Lm, D1, Da, Dc, Dm ;
  scanf("%lld %lld %lld",&n,&k,&q);  
  scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld",&A,&b,&c,&d,&e,&f,&r,&s,&t,&m,&arr[0]);
   ll t2=t%s ;
  for( i=1;i<n; i++)
	{ t2= (t2%s*t%s)%s;
	 if( t2 <= r) arr[i] = ( (A%m*(arr[i-1]%m * arr[i-1]%m) %m )%m  + ( (b%m *arr[i-1]%m) %m + c%m) %m ) %m ;
	else arr[i] = ( (d%m*(arr[i-1]%m * arr[i-1]%m) %m )%m  + ( (e%m *arr[i-1]%m) %m + f%m) %m ) %m ;  }
	
	for(ll i=0;i<2*n+3; i++) tree[i]=-1;
     build_tree(1, 0, n-1, arr, tree) ;

     long long int mul=1,sum=0;     
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&L1,&La,&Lc,&Lm,&D1,&Da,&Dc,&Dm);
	for( i=0;i<q; i++)
	 {   L1 = ( (La%Lm * L1%Lm) %Lm + Lc%Lm)% Lm;
	     D1 = ((Da%Dm * D1%Dm) %Dm + Dc%Dm) % Dm; 
	      L = L1 + 1; R = min(L + k - 1 + D1, n);  
	   ll temp= query_tree(1, 0, n-1, L-1, R-1 , arr,tree); 
	     sum+= temp;  mul = (mul%MOD * temp%MOD) %MOD ;	} // printf("%lld %lld %lld %lld\n",i,temp,sum,mul%MOD);  }
        	printf("%lld %lld\n",sum,mul%MOD);  
	 
	return 0;
} 