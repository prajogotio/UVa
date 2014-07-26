#include <iostream>
#include <cstdio>
using namespace std;
#define MOD 1000000

int dp[104][104];

int rec(int N, int K){
	if(N == 0) return 1;
	if(N < 0) return 0;
	if(K <= 1) return 1;
	if(dp[N][K] != -1) return dp[N][K];
	int ans = 0;
	for(int i=0;i<=N;++i){
		ans = (rec(N-i, K-1) + ans) % MOD;
	}
	dp[N][K] = ans %MOD;
	return ans%MOD;
}

int main(){
	int N,K;
	while(scanf("%d %d", &N, &K), N+K != 0){
		for(int i=0;i<104;++i)
			for(int j=0;j<104;++j)
				dp[i][j] = -1;

		int ans = rec(N,K);
		printf("%d\n", ans);
	}
	return 0;
}