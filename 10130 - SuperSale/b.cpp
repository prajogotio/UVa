#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int w[1005], p[1005], dp[1005][35];
int N;
//1-indexed
void ks(){
    for(int i=0;i<=N;++i){
        dp[i][0] = 0;
    }
    for(int i=0;i<35;++i){
        dp[0][i] = 0;
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=30;++j){
            dp[i][j] = dp[i-1][j];
            if(j - w[i] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + p[i]);
        }
    }
    /*
    for(int i=1;i<=N;++i){
        for(int j=1;j<=30;++j){
            printf("%3d", dp[i][j]);
        }
        printf("\n");
    }
    */
}

int main(){
    int TC, Q, g;
    cin >> TC;
    while(TC--){
        cin >> N;
        for(int i=1;i<=N;++i){
            scanf("%d %d", &p[i], &w[i]);
        }
        ks();
        int ans = 0;
        cin >> Q;
        while(Q--){
            cin >> g;
            ans += dp[N][g];
        }
        printf("%d\n", ans);
    }
    return 0;
}
            