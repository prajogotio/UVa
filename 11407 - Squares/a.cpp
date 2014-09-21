#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int maxint = (int)1e9;
int dp[10003];

int main(){
    dp[0] = 0;
    for(int i=1;i<=10000;++i) dp[i] = maxint;
    for(int i=1;i<=10000;++i){
        for(int j=1;j*j<=i;++j){
            dp[i] = min(dp[i], 1+dp[i-j*j]);
        }
    }
    int TC, u;
    cin >> TC;
    while(TC--){
        cin >> u;
        cout << dp[u] << endl;
    }
    return 0;
}