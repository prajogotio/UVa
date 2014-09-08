#include <iostream>
#include <cstdio>
using namespace std;
int MAXINT = (int) 1e9;
int s[13][104];
int N,M;
int dp[13][104];

int rec(int k, int tm){
    if(tm < 0) return -MAXINT;
    if(k == N) return 0;
    if(dp[k][tm] != -1) return dp[k][tm];
    int ret1 = -MAXINT;
    int tmp = 0;
    for(int i=0;i<M;++i){
        if(s[k][i] < 5) continue;
        tmp = s[k][i] + rec(k+1, tm-i-1);
        if(tmp > ret1){
            ret1 = tmp;
        }            
    }
    dp[k][tm] = ret1;
    return ret1;
}

int main(){
    int tc;
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d" , &N, &M);
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                scanf("%d", &s[i][j]);
            }
        }
        for(int i=0;i<=N;++i)
            for(int j=0;j<=M;++j)
                dp[i][j] = -1;
        int ans = rec(0, M);
        if( ans < 0 ) printf("Peter, you shouldn't have played billiard that much.\n");
        else printf("Maximal possible average mark - %.2lf.\n", (ans + 1e-12) / N);
    }
    return 0;
}