#include<iostream>
#include<cstdio>
#define gc getchar_unlocked
#define v long
void scanint(v &x)
{
    register v c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

 v gcd (v a, v b )
    { if(a<b) return gcd(b,a);
      if ( b==0 ) return a;
      return gcd (b,a%b);
   }

int main()
{   v t;
     scanint(t);
     while(t--)
     {  v x,y,z,i,n,q;
         scanint(n); scanint(q);
        v a[n+1],b[n+1],c[n+2]; a[0]=0;
        for(i=1; i<n+1;i++)
           scanint(a[i]);
          
        b[0]=a[1]; c[n+1]=a[n];  
      for(i=1; i<n+1;i++)
          { b[i]=gcd(a[i],b[i-1]);
            c[n-i+1]=gcd(a[n-i+1],c[n-i+2]);
          } 
       
      while(q--)
       {  scanint(x); scanint(y);
          if(x==1) printf("%ld\n",c[y+1]);
		  //cout<< c[y+1] <<endl;
         else if(y==n)  printf("%ld\n",b[x-1]);
		 //cout<< b[x-1] <<endl;
         else{ z= gcd(b[x-1],c[y+1]);printf("%ld\n",z);
         // cout<< z <<endl; 
		 }
       }
	 
	 }
	return 0;
}