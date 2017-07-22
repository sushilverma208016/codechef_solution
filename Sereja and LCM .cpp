# include<iostream>
# include<math.h>
#define p 1000000007
# include<stdio.h>
#include <stdlib.h>
typedef long long int ull;
using namespace std; 
		 
ull power(ull a,ull b){
  ull re;
  if(!b) return 1;
  re = power(a,b/2);
  re = (re*re)%p;
  if(b%2) re = (re*a)%p;
  return re; }   
   	 	 
void primeF(ull n, int pr[], int fig[][4])
{  ull j=0; ull num=n; ull t=1;
   while (num%2==0) 
    {  t=t*2;  num=num/2;   }  if(n%2==0) { fig[n][j]=t; j++; }
  for (int i=3; i<=(n/2); i++)
    { if(pr[i]==1){  ull t=1;
	 while (num%i == 0)
        {  t=t*i; num=num/i;  }
		if(n%i==0) { fig[n][j]=t; j++; }  }   }	   }
		
ull inter2(ull a,ull b,ull m, ull n,ull cal[], ull temp)	
{  ull c= m-((m/a)+(m/b)-(m/(a*b))); ull u=power(c,n); u=(u+p)%p;
    ull d=(temp+(p-u))%p; d=(d+p)%p; if(d<0)d=d+p; d=(d+p)%p; 
 ull g=(cal[a]+cal[b])%p; g=(g+(p-d))%p; g=(g+p)%p; if(g<0)g=g+p;  return (g+p)%p;  }
	
ull inter3(ull a,ull b,ull c,ull m, ull n,ull cal[], ull temp)	
{  ull d=m-((m/a)+(m/b)+(m/c)-(m/(a*b))-(m/(b*c))-(m/(c*a))+(m/(a*b*c))); ull u=power(d,n); u=(u+p)%p; u=(temp-u+p)%p;
   ull e=((((u+cal[a*b])%p+cal[b*c])%p+cal[c*a])%p); ull f=((cal[a]+cal[b])%p+cal[c])%p;
   ull g=(e-f+p)%p; if(g<0)g=g+p; g=(g+p)%p; return g;  }  
   
ull inter4(ull a,ull b,ull c,ull d,ull m, ull n,ull cal[], ull temp)	
{  ull e=m-((m/a)+(m/b)+(m/c)+(m/d)-(m/(a*b))-(m/(a*c))-(m/(a*d))-(m/(b*c))-(m/(b*d))-(m/(c*d))+(m/(a*b*c))+(m/(a*b*d))+(m/(a*c*d))+(m/(b*c*d))-(m/(a*b*c*d)));
   ull u=power(e,n); u=(u+p)%p; u=(temp-u+p)%p; 
   ull f=(((((((cal[a]+cal[b])%p+cal[c])%p+cal[d])%p+cal[a*b*c])%p+cal[a*b*d])%p+cal[a*c*d])%p+cal[b*c*d])%p;
   ull k=((((((cal[a*b]+cal[a*c])%p+cal[a*d])%p+cal[b*c])%p+cal[b*d])%p+cal[c*d])%p+u)%p;
   ull g=(f-k+p)%p; if(g<0) g=g+p; g=(g+p)%p; return g; }   
		      
int fig[1001][4]; int mark[1001]; int pr[1001]; 
 int main()  
 { ull t,l,m,n,r;
     cin >>t;
   while(t--)
   {     cin>>n>>m>>l>>r;
   	   ull cal[r+1];
   	   for(int j=0; j<1001; j++)   { mark[j]=-1; pr[j]=-1; }
   	 pr[2]=1;pr[3]=1;pr[5]=1;pr[7]=1;pr[11]=1;pr[13]=1;pr[17]=1;pr[19]=1;pr[23]=1;pr[29]=1;pr[31]=1;pr[37]=1;pr[41]=1;
	pr[43]=1;pr[47]=1;pr[53]=1;pr[59]=1;pr[61]=1;pr[67]=1;pr[71]=1;pr[73]=1;pr[79]=1;pr[83]=1;pr[89]=1;pr[97]=1;pr[101]=1;
	pr[103]=1;pr[107]=1;pr[109]=1;pr[113]=1;pr[127]=1;pr[131]=1;pr[137]=1;pr[139]=1;pr[149]=1;pr[151]=1;pr[157]=1;pr[163]=1;
	pr[167]=1;pr[173]=1;pr[179]=1;pr[181]=1;pr[191]=1;pr[193]=1;pr[197]=1;pr[199]=1;pr[211]=1;pr[223]=1;pr[227]=1;pr[229]=1;
	pr[233]=1;pr[239]=1;pr[241]=1;pr[251]=1;pr[257]=1;pr[263]=1;pr[269]=1;pr[271]=1;pr[277]=1;pr[281]=1;pr[283]=1;pr[293]=1;
	pr[307]=1;pr[311]=1;pr[313]=1;pr[317]=1;pr[331]=1;pr[337]=1;pr[347]=1;pr[349]=1;pr[353]=1;pr[359]=1;pr[367]=1;pr[373]=1;
  pr[379]=1;pr[383]=1;pr[389]=1;pr[397]=1;pr[401]=1;pr[409]=1;pr[419]=1;pr[421]=1;pr[431]=1;pr[433]=1;pr[439]=1;pr[443]=1;
  pr[449]=1;pr[457]=1;pr[461]=1;pr[463]=1;pr[467]=1;pr[479]=1;pr[487]=1;pr[491]=1;pr[499]=1;pr[503]=1;pr[509]=1;pr[521]=1;
  pr[523]=1;pr[541]=1;pr[547]=1;pr[557]=1;pr[563]=1;pr[569]=1;pr[571]=1;pr[577]=1;pr[587]=1;pr[593]=1;pr[599]=1;pr[601]=1;
  pr[607]=1;pr[613]=1;pr[617]=1;pr[619]=1;pr[631]=1;pr[641]=1;pr[643]=1;pr[647]=1;pr[653]=1;pr[659]=1;pr[661]=1;pr[673]=1;
  pr[677]=1;pr[683]=1;pr[691]=1;pr[701]=1;pr[709]=1;pr[719]=1;pr[727]=1;pr[733]=1;pr[739]=1;pr[743]=1;pr[751]=1;pr[757]=1;
  pr[761]=1;pr[769]=1;pr[773]=1;pr[787]=1;pr[797]=1;pr[809]=1;pr[811]=1;pr[821]=1;pr[823]=1;pr[827]=1;pr[829]=1;pr[839]=1;
  pr[853]=1;pr[857]=1;pr[859]=1;pr[863]=1;pr[877]=1;pr[881]=1;pr[883]=1;pr[887]=1;pr[907]=1;pr[911]=1;pr[919]=1;pr[929]=1;
  pr[937]=1;pr[941]=1;pr[947]=1;pr[953]=1;pr[967]=1;pr[971]=1;pr[977]=1;pr[983]=1;pr[991]=1;pr[997]=1;
   	 cal[0]=0; ull temp= power(m,n); temp=temp%p; // cout<<temp<<endl;
	 mark[1]=1; cal[1]=temp;    
  
	for(ull i=2;i<(r+1); i++) 
	  {	 if(pr[i]==1){
	    for(ull j=1; pow(i,j)<(r+1); j++) 
	    {   ull tp=pow(i,j); 
		  if(mark[tp]==-1){ ull h=power((m-(m/tp)),n); h=(h+p)%p; ull q=(temp+(p-h))%p; if(q<0)q=q+p; q=(q+p)%p;
		    cal[tp]=q; mark[tp]=1; }   }    }	}
     
	 for(ull i=6; i<(r+1); i++)  
	   {   if(mark[i]==-1)  {  
	       for(ull j=0; j<4; j++) { fig[i][j]=0; } 
	        primeF(i,pr,fig);   	 
	       if(fig[i][0]>0 &&fig[i][1]>0 &&fig[i][2]==0&&fig[i][3]==0 )
	            { ull x=inter2(fig[i][0],fig[i][1],m,n,cal,temp); cal[i]=(x+p)%p; mark[i]=1;}
	       else if(fig[i][0]>0 &&fig[i][1]>0 &&fig[i][2]>0&&fig[i][3]==0 )
	            { ull x=inter3(fig[i][0],fig[i][1],fig[i][2], m,n, cal,temp); cal[i]=(x+p)%p;  mark[i]=1;   }
	       else if(fig[i][0]>0 &&fig[i][1]>0 &&fig[i][2]>0&&fig[i][3]>0)
	            { ull x=inter4(fig[i][0],fig[i][1],fig[i][2],fig[i][3], m,n, cal,temp);cal[i]=(x+p)%p; mark[i]=1;   }     		    
	    }  }
	  ull cum=0; 
	  for(ull i=l; i<=r; ++i) 
   	     { 	//cout<<cal[i]<<endl;
			 cum=(cum+cal[i]); if(cum>=p)cum=cum%p;  } 
	  	   cout<< cum<<endl;
	    //	ull y= ((temp+(p-power(24,100)))+(p-cal[3])+(p-cal[5])+(p-cal[4])+cal[12]+cal[20]+cal[15])%p; cout<<y<<endl;
   }
 	return 0;  
 } 