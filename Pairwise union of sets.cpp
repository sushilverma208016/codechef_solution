#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n, k, i, j, x, y;
    scanf("%d",&t);
    while(t--) {
        scanf("%d %d",&n,&k);
        vector<vector<int> > occur(n);
        for (i=0; i<n; i++) {
            scanf("%d",&y);
            vector<int> temp(y);
            for (j=0; j<y; j++) {
                scanf("%d",&temp[j]);
            }
            sort(temp.begin(), temp.begin()+y);
            occur[i]=temp;
        }
        //for (i=0; i<n; i++) {
        //    for (j=0; j<occur[i].size(); j++) cout<<occur[i][j]<<" ";
        //    cout<<"\n"; }
        if (n==1) { printf("0\n"); continue; }
        int count=0;
        for (i=0; i<n-1; i++) {
            if (occur[i].size()==k) { count+=(n-1-i); continue; }
            for (j=i+1; j<n; j++) {
                if (occur[j].size()==k) { count++; continue; }
                
                x=0, y=0; int z=1;
                while (x<occur[i].size() && y<occur[j].size() && ((z==occur[i][x]) || (z==occur[j][y])) ) {
                    if (occur[i][x]<occur[j][y]) { x++; z++; }
                    else if (occur[i][x]>occur[j][y]) { y++; z++; }
                    else { x++; y++; z++; }
                }
                while(x<occur[i].size() && (z==occur[i][x]) ) { x++; z++; }
                while(y<occur[j].size() && (z==occur[j][y]) ) { y++; z++; }
                if (z>k) count++;
                
            }
        }
        printf("%d\n", count);
    }
	return 0;
}