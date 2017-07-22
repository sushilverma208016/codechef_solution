# include<iostream>
# include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<cstdio>
#define gc getchar_unlocked
#define N 100000
#define MAX 2000003
#define ull unsigned long long int
using namespace std;
 
ull arr[N];
ull tree[MAX][4];
ull tree_query[MAX][4];
void scanint(ull &x)
 {   register ull c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
	 for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;} }
	 
 inline void fastRead_string(char *str)
    { register char c = 0;  register ull i = 0;
        for(;(c<48 || c>57);c = gc());
        while (c!='\n') {
        str[i]=c; c=gc();  i = i + 1;  }
        str[i]='\0';	} 
		 
void merge(ull tree[][4],ull u, ull v,ull w) { 
   for (ull i=1;i<4;i++) tree[u][i]=0; 
   ull x=(tree[v][0]+tree[w][0])%3; tree[u][0]=x;  
       for (ull i=1;i<4;i++) {  ull xx;
           xx =(tree[u][i]+tree[v][i]); tree[u][i]=xx; }
        for (ull i=1;i<4;i++) {  ull zz;
            zz=tree[u][(((i-1)+tree[v][0]+3)%3)+1]+tree[w][i];  tree[u][(((i-1)+tree[v][0]+3)%3)+1]=zz;
			   }   }			    
               
void merge_query(ull tree_query[][4],ull u, ull v,ull w) { 
    for (ull i=1;i<4;i++) tree_query[u][i]=0; 
    ull x= (tree_query[v][0]+tree_query[w][0])%3; tree_query[u][0]=x;
     for (ull i=1;i<4;i++) {  ull xx;
           xx =(tree_query[u][i]+tree_query[v][i]); tree_query[u][i]=xx; }
        for (ull i=1;i<4;i++) {  ull zz;
            zz=tree_query[u][(((i-1)+tree_query[v][0]+3)%3)+1]+tree_query[w][i]; tree_query[u][(((i-1)+tree_query[v][0]+3)%3)+1]=zz;
			   }   }             
               
void build_tree(ull tree[][4], ull node,ull a,ull b) 
{    if(a>b) return;
     if(a==b) { ull x=arr[a]%3;  tree[node][0] =x; 
     if(x==0) {  tree[node][1]=1; tree[node][2]=0; tree[node][3]=0; }
     else  if(x==1) {  tree[node][1]=0; tree[node][2]=1; tree[node][3]=0; }
     else  if(x==2) {  tree[node][1]=0; tree[node][2]=0; tree[node][3]=1; }
           return; }
    build_tree(tree, node*2,a,(a+b)/2); 
    build_tree(tree, node*2+1,1+(a+b)/2, b);
    merge(tree,node, node*2,node*2+1);  }
    
void update(ull tree[][4], ull node, ull left, ull right, ull pos, ull newValue)
 {     if (pos<left||pos>right) return;
   if(left==right) { ull x=newValue%3;  tree[node][0] =x; 
     if(x==0) {  tree[node][1]=1; tree[node][2]=0; tree[node][3]=0; }
     else  if(x==1) {  tree[node][1]=0; tree[node][2]=1; tree[node][3]=0; }
     else  if(x==2) {  tree[node][1]=0; tree[node][2]=0; tree[node][3]=1; }  }
     
	else { ull mid=(left+right)/2;
        if(pos<=mid)  update(tree,node*2,left,mid,pos,newValue);
        else update(tree,node*2+1,mid+1,right,pos,newValue);
           merge(tree,node,node*2,node*2+1); 
		    }  }    

ull count(ull tree_query[][4], ull node) 
 {  ull res = 0;
    for (ull i=1;i<4; i++) 
	{     ull curr = tree_query[node][i];
          if (i==1) curr++;
           res=res+(curr*(curr-1)/2); }
   return res; }
   
ull query_tree(ull tree[][4],ull tree_query[][4],ull node,ull a,ull b,ull i,ull j) 
  {  if (b<i || a>j)  return 0; 
   if(a>=i && b<=j) 
    { for(ull ii=0;ii<4;ii++) tree_query[node][ii]=tree[node][ii];
	  return node; } 
	  
   ull q1 = query_tree(tree,tree_query,node*2,a,(a+b)/2,i,j); 
   ull q2 = query_tree(tree,tree_query,1+node*2,1+(a+b)/2, b, i, j);
      merge_query(tree_query,node,q1,q2);  return node; }
 
int main() { 
     for(ull ind=0;ind<MAX;ind++){
       for(ull indx=0;indx<4;indx++){ 
          tree[ind][indx]=0;tree_query[ind][indx]=0;   }  } 
      ull q,n,x,y,m;
       scanint(n); scanint(m);
       char inp[n];
       fastRead_string(inp);
       for(ull ind=0;ind<n;ind++){
	       arr[ind]=inp[ind]-'0';}  
	    build_tree(tree,1,0,n-1);   
        while(m--)
        {  scanint(q);scanint(x);scanint(y);
           if(q==1){ arr[x-1]=y; 
		           update(tree,1,0,n-1,x-1,y); 
				        }
            else if(q==2){  tree[0][0]=0;tree[0][1]=0;tree[0][2]=0;tree[0][3]=0;
                            tree_query[0][0]=0;tree_query[0][1]=0;tree_query[0][2]=0;tree_query[0][3]=0;
             ull  result=count (tree_query, query_tree(tree,tree_query,1,0,n-1,x-1,y-1) );     
			  cout<<result<<endl;        
         } }
         return 0;
       } 