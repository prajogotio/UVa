#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int maxint = (int) 1e9;
int a[55];
int N;
int dp[55][55];
//0 stores 0, N+1 stores full length
//1 indexed
int rec(int L, int R){
    if(L+1 == R) return 0;
    if(dp[L][R] != -1) return dp[L][R];
    int ans = maxint;
    for(int i=L+1;i<R;++i){
        ans = min(ans, a[R] - a[L] + rec(L, i) + rec(i, R));
    }
    dp[L][R] = ans;
    return ans;
}

int main(){
    int L;
    while( cin >> L ){
        if (L == 0) break;
        cin >> N;
        for(int i=1;i<=N;++i){
            cin >> a[i];
        }
        for(int i=0;i<=N+1;++i)
            for(int j=0;j<=N+1;++j)
                dp[i][j] = -1;
        a[0] = 0;
        a[N+1] = L;
        int ans = rec(0, N+1);
        printf("The minimum cutting is %d.\n", ans);
    }
    return 0;
}