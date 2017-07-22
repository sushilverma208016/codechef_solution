#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <inttypes.h>
#include <ctype.h>
#define MOD 1000000007
using namespace std;

template<typename T> T _pow(T num, T exp, T x){
if(exp==0)
return 1;
if(exp==1)
return num%x;
if(exp%2==0){
T temp = _pow(num,exp>>1,x);
return (temp*temp)%x;
}
else {
T temp = _pow(num,exp>>1,x);
return ((temp*temp)%x*num)%x;
}

}

int main()
{
uint64_t n,m,l,r,tc,i,temp,j,k;
map<uint64_t,uint64_t>pow_values;
cin>>tc;
while(tc--){
cin>>n>>m>>l>>r;
uint64_t arr_M[m+1];
pow_values.clear();
for(i=m;m<2*i;i--){
arr_M[i]=1;
}
while(i && (i>=l)){
temp=m/i;
if(pow_values.find(temp)!=pow_values.end()){
arr_M[i]= pow_values.find(temp)->second;
}
else {
uint64_t val= _pow((uint64_t)temp,(uint64_t)n,(uint64_t)MOD);
pow_values.insert(make_pair(temp,val));
arr_M[i]=val;
}
if(temp==2){
arr_M[i]--;
}
else {
j=i*2;
while(j<=m){
arr_M[i] -= arr_M[j];
j+= i;
}
}
i--;
}
uint64_t result=0;
for(;l<=r;l++)
result = result+arr_M[l]%MOD;
cout<<result<<endl;
}
return 0;
}