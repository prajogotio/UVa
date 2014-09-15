#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long Long;
Long MOD, a[1003], dp[1003][1003];
int N;
// Recursion: S(k, n) = a_n * S(k-1, n-1) + S(k, n-1)

int main(){
    for(int i=0;i<1003;++i){
        dp[0][i] = 1;
    }
    while(cin >> N >> MOD){
        if(N+MOD == 0) break;
        for(int i=1;i<=N;++i){
            cin >> a[i];
        }
        for(int i=1;i<=N;++i){
            for(int j=i;j<=N;++j){
                dp[i][j] = (a[j] * dp[i-1][j-1])%MOD;
                if(j > i) dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
                if(dp[i][j] < 0) dp[i][j] += MOD;
            }
        }
        Long ans = 0;
        for(int i=1;i<=N;++i){
            ans = max(ans, dp[i][N]);
        }
        cout << ans << endl;
    }
    return 0;
}
