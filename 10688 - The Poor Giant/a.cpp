#include <iostream>
#include <cstdio>
using namespace std;
int maxint = (int) 1e9;
int dp[503][503];
int N, K;

int a(int n){
    return K+n+1;
}

int rec(int L, int R){
    if(R <= L) return 0;
    if(R-L == 1) return a(L)*2;
    if(R-L == 2) return a(L+1)*3;
    if(dp[L][R] != -1) return dp[L][R];
    int ret = maxint;
    for(int i=L; i<= R; ++i){
        ret = min(a(i)*(R-L+1) + rec(L,i-1) + rec(i+1,R), ret);
    }
    dp[L][R] = ret;
    return ret;
}

int main(){
    int TC, T=1;
    cin >> TC;
    while(TC--){
        cin >> N >> K;
        for(int i=0;i<=N;++i)
            for(int j=0;j<=N;++j)
                dp[i][j] = -1;
        printf("Case %d: %d\n", T++, rec(0,N-1));
    }
    return 0;
}