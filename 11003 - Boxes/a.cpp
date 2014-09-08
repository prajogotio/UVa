#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int MAXINT = (int) 1e9;
int w[1005], c[1005];
int dp[3004][1005];
int N;

int rec(int k, int W){
    if(W < 0) return -MAXINT;
    if(W == 0 || k == N) return 0;
    if(dp[W][k] != -1) return dp[W][k];
    int ret1=0, ret2=0;
    if(w[k] <= W){
        ret1 = 1 + rec(k+1, min(W - w[k], c[k]));
    }
    ret2 = rec(k+1, W);
    dp[W][k] = max(ret1, ret2);
    return dp[W][k];
}

int main(){
    while(scanf("%d", &N), N!=0){
        for(int i=0;i<N;++i){
            scanf("%d %d", &w[i], &c[i]);
        }
        for(int i=0;i<3004;++i)
            for(int j=0;j<N;++j)
                dp[i][j] = -1;
        int ans = 0;
        for(int i=0;i+1<N;++i){
            ans = max(ans,1+ rec(i+1, c[i]));
        }
        printf("%d\n", ans);
    }
    return 0;
}