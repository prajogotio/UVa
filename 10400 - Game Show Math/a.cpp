#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int tg, N;
int a[103];
int dp[2][32003][102];
int par[2][32003][102];
int rec(int sum, int k){
    //printf("%d %d\n", sum, k);
    if(sum > 32000 || sum < -32000) return 0;
    if(sum == tg && k == N) {
        return 1;
    }
    if(k == N) return 0;
    if(sum < 0 && dp[0][-sum][k] != -1) return dp[0][-sum][k];
    if(sum >= 0 && dp[1][sum][k] != -1) return dp[1][sum][k];
    int ct, sm;
    if(sum < 0) {ct = 0; sm = -sum;}
    else {ct = 1; sm = sum;}
    dp[ct][sm][k] = 0;
    
    //printf("%d %d %d\n", ct, sm, k);
    par[ct][sm][k] = 1;
    dp[ct][sm][k] |= rec(sum + a[k], k+1);
    if(dp[ct][sm][k]) return 1;
    
    par[ct][sm][k] = 2;
    dp[ct][sm][k] |= rec(sum - a[k], k+1);
    if(dp[ct][sm][k]) return 1;
    
    par[ct][sm][k] = 3;
    dp[ct][sm][k] |= rec(sum * a[k], k+1);
    if(dp[ct][sm][k]) return 1;
    
    if(a[k] != 0 && sum % a[k] == 0) {
        par[ct][sm][k] = 4;
        dp[ct][sm][k] |= rec(sum / a[k], k+1);
        if(dp[ct][sm][k]) return 1;
    }
    return 0;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        cin >> N;
        for(int i=0;i<N;++i){
            cin >> a[i];
        }
        cin >> tg;
        for(int i=0;i<2;++i){
            for(int j=0;j<32001;++j){
                for(int k=0;k<N;++k){
                    dp[i][j][k] = -1;
                }
            }
        }
        int ans = rec(a[0], 1);
        if(!ans) printf("NO EXPRESSION\n");
        else {
            printf("%d", a[0]);
            int k=1;
            int sum = a[0];
            int sm = (a[0] < 0) ? -a[0]: a[0];
            int ct = (a[0] < 0) ? 0: 1;
            while(k < N){
                //printf("%d %d %d %d\n", ct, sm, k, par[ct][sm][k]);
                if(par[ct][sm][k] == 1){
                    sum += a[k];
                    printf("+");
                } else if(par[ct][sm][k] == 2){
                    sum -= a[k];
                    printf("-");
                } else if(par[ct][sm][k] == 3){
                    sum *= a[k];
                    printf("*");
                } else {
                    sum /= a[k];
                    printf("/");
                }
                if(sum < 0){
                    ct = 0; 
                    sm = -sum;
                }else {
                    ct = 1;
                    sm = sum;
                }
                printf("%d", a[k]);
                ++k;
            }
            printf("=%d\n", tg);
        }
    }
    return 0;
}
    