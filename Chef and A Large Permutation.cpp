# include<iostream>
# include<algorithm>
# include<stdio.h>
#include <stdlib.h>
#define ull unsigned long long int
#define gc getchar_unlocked
using namespace std;

ull find1(ull a[],ull k ,ull tot,ull sumn)
 {  if(a[0]==1) return 1;
    if(a[0]==2) return 2;     bool flg=0;
   ull u,v,w,i,diff,index;
     ull rs, work =a[0];
	  	 ull valuework = (work*work-work+2)/2; 
   for(i=0; ;)
	  { diff=valuework-a[i];
	     index=i+diff;
	     if(index<k)
	             { if(a[index]==valuework)
	                { rs=valuework; flg=1; break;}
	               else{  u=a[index-1];v=a[index]-1;
				          w=((v*(v+1))-(u*(u+1)))/2;  
						   valuework=valuework+w;
						  i=index;	   }  }
	     else{ break; }
	      }
	   if(flg==1) return rs%2;   
        ull ans= ((( tot*tot+tot) /2)%2-sumn%2+1 )%2;
      //  printf("%lld\n",ans);
        return ans;
 }

void scanint(ull &x)
{
register ull c = gc();
x = 0;
for(;(c<48 || c>57);c = gc());
for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

 ull find(ull a[],ull k ,ull tot)
 {    if(a[0]==1) return 1;
        if(a[0]==2) return 2;  
     ull b[k],i,y,z,an,w, x=a[0]; bool flag=0;
      b[0]=(x*(x-1)/2)+1;
      for(i=1;i<k;i++)
      {    if(a[i]==a[i-1]+1) b[i]=b[i-1];
	        else{  y=a[i-1]; z=a[i]-1;
             w= (z*(z+1)/2)-(y*(y+1)/2);
             b[i]=b[i-1]+w;  }
             if(a[i]==b[i]) { flag=1; an=b[i]; break;  }
      }
      	if(flag==1) return an%2;
        if(tot<=a[k-1]) return b[k-1]%2;
            else { ull r=a[k-1];
			 ull o= ((( tot*tot+tot) /2)-(r*(r+1)/2) );
			  ull ans=(o%2+b[k-1]%2)%2;
			 return ans;   }
 }

 int main()
 {  ull t;
    scanint(t);
   // scanf("%lld",&t);
    while(t--){ ull n,k,i; 
   // scanint(n);scanint(k);
      scanf("%lld%lld",&n,&k);
      ull p, sumn=0, miss[k]; 
     for(i=0;i<k;i=i+1) {  	// scanf("%lld",&miss[i]); 
	 scanint(miss[i]); sumn=sumn+miss[i];}
     sort(miss,miss+k); 
	 //for(i=0;i<k;i=i+1) printf("%d\t",miss[i]);  
      if(k==0) p=find1(miss,k ,n,sumn);
	  else p= find(miss,k,n);
 
     // printf("%d\n",p);
      if(p%2==0) { printf("Mom\n");} 
      else { printf("Chef\n");  }    
   
   }
 	return 0;
}