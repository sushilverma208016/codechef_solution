# include <iostream>
# include <stdio.h>
# include <vector>
# include <map>
# include <math.h>
# include <limits.h>
#include <algorithm>
using namespace std;
  unsigned int hasproduct[10001];
  unsigned int capital;
  unsigned int N,K,Q; //   city, product, query
  unsigned int G[10001][101] , L[10001][101];
  bool visited[10001];
  vector<unsigned int> nodelist[10001];

pair<int, int >final(unsigned int node,unsigned int level,unsigned int g,unsigned int l, unsigned int p, unsigned int item)
{   visited[p]=1;
     if(G[node][item]==INT_MAX  || L[node][item]==INT_MAX)
      { if (hasproduct[node]==item)
           { G[node][item]=level; L[node][item]=node; }
      }
     if(g!=INT_MAX  && l!=INT_MAX)
      { if (g>G[node][item] || G[node][item]==INT_MAX)
             {  G[node][item]= g; L[node][item]=l;  }
        else if(g==G[node][item] && L[node][item]>l){
                   L[node][item]=l; }        
      } 
      for(vector<unsigned int>::iterator itr=nodelist[node].begin();itr!=nodelist[node].end(); itr++)
     {  if(visited[*itr]==0){
            pair<int,int>res=final(*itr,level+1,G[node][item],L[node][item],node,item);
        
		   if(res.first<0)
                res.first=INT_MAX;
            if((res.first!=INT_MAX) && (G[node][item]==INT_MAX || res.first>G[node][item])) 
              {   G[node][item]=res.first;
                L[node][item]=res.second;
            }
            else if(res.first!=INT_MAX && res.first==G[node][item] && res.second<L[node][item]){
                    L[node][item]=res.second; 
            }
            }
      }
   
    if(G[node][item]==INT_MAX)
       return make_pair(G[node][item],L[node][item]);
    else
        return make_pair(G[node][item]-1,L[node][item]);
     
}  

void populate(void)
  {    for(int i=0;i<10001; i++ ) visited[i]=0;
       for(int i=1;i< K+1; i++ ) 
         { final(capital, 0, G[capital][i], L[capital][i], capital,i ); 
            for(int j=0;j<10001; j++ ) visited[j]=0;
         } 
       for(int i=0;i<10001; i++ ) visited[i]=0;
       for(int i=1;i< K+1; i++ ) 
         { final(capital, 0, G[capital][i], L[capital][i], capital,i ); 
            for(int j=0;j<10001; j++ ) visited[j]=0;   
         } 
  }

int main ()
{   
     

	cin>> N>> K;  // node ,product
	cin >> capital;  // B  root
    unsigned int x, y;
	for (int i=1;i<N; i++)
	  { cin >> x>> y;  //edges
	    nodelist[x].push_back(y);
	    nodelist[y].push_back(x);
	  }
     for(int i=0; i<10001; i++)
	    for(int j=0; j<101; j++)
	        {  G[i][j]=INT_MAX; L[i][j]=INT_MAX; hasproduct[i]=0;  }
	 
	      
		  for (int i=1;i<(N+1); i++)
	          {  cin >> hasproduct[i]; } // product
	           
	                
    	populate();
	 unsigned int  A, reqpro;  
	  cin>> Q; // QUERIES// chef city A  reqpro is required product
    	while(Q--){  cin>> A>> reqpro ;
       
	   
	       if(L[A][reqpro]==INT_MAX) 
            printf("-1\t");
        else
            printf("%d\t",L[A][reqpro]);  
          
		  
	          
     	}  

	return 0;
}