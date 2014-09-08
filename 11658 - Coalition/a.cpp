#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int MAXINT = (int) 1e9;
int a[103];
int N, idx;

int dp[103][100003];

int rec(int k, int sum){
    if(k == idx) return rec(k+1, sum);
    if(sum > 5000) return sum;
    if(k == N) return MAXINT;
    if(dp[k][sum] != -1) return dp[k][sum];
    int ret1 = rec(k+1, sum+a[k]);
    int ret2 = rec(k+1, sum);
    dp[k][sum] = min(ret1, ret2);
    return dp[k][sum];
}

int rof(int a, int b){
    double ret = (double) a/b * 10000;
    int x = (int) ret;
    if( ret - x < 0.5) return x;
    else return x+1;
}

int main(){
    int u,v;
    while(scanf("%d %d", &N, &idx), N+idx != 0){
        --idx;
        for(int i=0;i<N;++i){
            scanf("%d.%d", &u, &v);
            a[i] = u*100 + v;
        }
        for(int i=0;i<N;++i){
            for(int j=0;j<100003;++j){
                dp[i][j] = -1;
            }
        }
        int ans = rec(0, a[idx]);
        ans = rof(a[idx], ans);
        printf("%d.%02d\n", ans/100, ans%100);
    }
    return 0;
}