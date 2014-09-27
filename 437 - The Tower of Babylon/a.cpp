#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int d[99][3];
int dp[99];
int N;

int rec(int k){
    if(dp[k] != -1) return dp[k];
    int ret = 0;
    for(int i=0;i<N;++i){
        if( (d[k][1] > d[i][1] && d[k][2] > d[i][2]) || (d[k][1] > d[i][2] && d[k][2] > d[i][1]) ){
            ret = max(ret, d[i][0] + rec(i) );
        }
    }
    dp[k] = ret;
    return ret;
}

int main(){
    int n, T=1;
    while(cin >> n, n!=0){
        N = 3*n;
        for(int i=0;i<n;++i){
            int x,y,z;
            cin >> x >> y >> z;
            d[i*3][0] = d[i*3+1][1] = d[i*3+2][2] = x;
            d[i*3][1] = d[i*3+1][2] = d[i*3+2][0] = y;
            d[i*3][2] = d[i*3+1][0] = d[i*3+2][1] = z;
        }
        for(int i=0;i<99;++i){
            dp[i] = -1;
        }
        /*
        for(int i=0;i<N;++i){
            printf("%d %d %d\n", d[i][0], d[i][1], d[i][2]);
        }
        */
        int ans = 0;
        for(int i=0;i<N;++i){
            ans = max(d[i][0] + rec(i), ans);
        }
        /*
        for(int i=0;i<N;++i){
            printf("%d ", dp[i]);
        }
        printf("\n");
        */
        printf("Case %d: maximum height = %d\n", T++, ans);
    }
    return 0;
}