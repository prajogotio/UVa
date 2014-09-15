#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int N;
int dp[73][73];
int rec(int n, int t){
    if(t == 0) return 1;
    if(n == 1) return 1;
    if(dp[n][t] != -1) return dp[n][t];
    int ret = 0;
    for(int i=0;i<=t;++i){
        ret += rec(n-1, t-i);
    }
    dp[n][t] = ret;
    return ret;
}

int main(){
    int TC;
    int t,p;
    cin >> TC;
    for(int i=0;i<73;++i)
        for(int j=0;j<73;++j)
            dp[i][j] = -1;
    while(TC--){
        scanf("%d %d %d", &N, &t, &p);
        t -= p*N;
        if(t <= 0) {
            cout << 1 << endl;
            continue;
        }
        cout << rec(N, t) << endl;
    }
    return 0;
}