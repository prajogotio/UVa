#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int S, N;
int dp[205][25];
int w[25];

int rec(int k, int W){
    if(W == 0) return 1;
    if(W < 0 || k < 0) return 0;
    if(dp[W][k] != -1) return dp[W][k];
    int ret1 = rec(k-1, W - w[k]);
    int ret2 = rec(k-1, W);
    dp[W][k] = (ret1|ret2);
    return dp[W][k];
}

int main(){
    int tc;
    char c;
    scanf("%d", &tc);
    while(tc--){
        scanf(" %d", &w[0]);
        N = 1;
        S = w[0];
        while((c=getchar()) != '\n' && c != EOF){
            scanf(" %d", &w[N]);
            S += w[N++];
        }
        if( S%2 != 0 ){
            printf("NO\n");
            continue;
        }
        S /= 2;
        for(int i=0;i<205;++i)
            for(int j=0;j<N;++j)
                dp[i][j] = -1;
        int res = rec(N-1, S);
        if(res == 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
        