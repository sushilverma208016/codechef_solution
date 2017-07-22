# include <iostream>
# include <map>
# define P 1000000007
using namespace std;


long int calc(int v, int e)
  {   if (v==0 && e==0)  return 1L;
    else  if (v==1 && e==0) return 2L;
     else if (v==2 && e==0) return 4L;
    else  if (v==2 && e==1) return 3L;
    else  if (v==3 && e==0) return 8L;
    else  if (v==3 && e==1) return 6L;
    else  if (v==3 && e==2) return 5L;
    else  if (v==3 && e==3) return 4L;
      if (e <= ((v-2)*(v-3)/2) +2 ) return  (2L*calc(v-1,e)) % P  ;
	      else return  (((v*v)+v+2L-(2L*e))/2L) % P ;
       
  }
int main()
{   int N,a,b;
  cin>> N;
  bool valid[N+1];
 long int A[N+1],B[N+1];  
   A[0]=0;  B[0]=0;  
  for(int i=1; i<N+1; i++)
      {cin >> A[i];
        B[i]=0; } 
        
   for(int i=0; i<N+1; i++)
        valid[i]=0; 
   map<long int, int> num_map;     
   for(int i=1; i<N+1; i++)
      if(A[i]< 0)  
           num_map.insert(pair<long int,int> (A[i], i));
      else if(A[i]> 0) { 
           if( num_map.find(-(A[i])) != num_map.end())
             { valid[i]=1;     
              valid[num_map[-(A[i])]]=1;   }
      }
   
     for(int i=1,j=1; i<N+1; i++)
        {  if(valid[i]==1)  
              { B[j]=A[i];
                 j++;
              }  
        }  
     int i=1; int count_vertex=0, count_edge=0 ;
	 while(B[i])  
	    { long int x=B[i];
	     if(x<0L)
	      {  count_vertex++;
		    map<long int, int> check; 
		   for(int j=i+1; B[j]!=(-x); j++)
	         {  if (B[j] <0) 
	              check.insert(pair<long int,int> (B[j], 1)); 
	            else 
				{  if(check.find(-(B[j])) != num_map.end())
				      {   check.erase (-(B[j])); 
				      }
	                } 
	              } 
	         count_edge= count_edge+check.size();
	         check.clear();
	         
	       }
	      i++;
	    }		
       
		   
  	 
      a=count_vertex;  b=count_edge;
   
     cout<< calc(a,b);
  
  

 return 0;

}