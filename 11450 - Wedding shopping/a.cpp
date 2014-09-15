#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int maxint = (int) 1e9;
int M,N;
int a[23][23];
int b[23];
int dp[23][203];

int rec(int k, int rem){
    if(rem < 0) return -maxint;
    if(k == N) return 0;
    if(dp[k][rem] != -1) return dp[k][rem];
    int ret = -maxint;
    for(int i=0;i<b[k];++i){
        ret = max(ret, a[k][i] + rec(k+1, rem - a[k][i]));
    }
    dp[k][rem] = ret;
    if(ret < 0) dp[k][rem] = -maxint;
    return dp[k][rem];
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        cin >> M >> N;
        for(int i=0;i<=N;++i){
            for(int j=0;j<=M;++j){
                dp[i][j] = -1;
            }
        }
        for(int i=0;i<N;++i){
            cin >> b[i];
            for(int j=0;j<b[i];++j){
                cin >> a[i][j];
            }
        }
        int ans = rec(0, M);
        if(ans < 0) cout << "no solution\n";
        else cout << ans << endl;
    }
    return 0;
}