#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

double dp[10][105];
int N, K;
void solve() {
	for(int i=0;i<=K;++i){
		for(int j=0;j<=N;++j){
			dp[i][j] = 0;
		}
	}
	for(int i=0;i<=K;++i){
		dp[i][1] = 1.0/(K+1);
	}
	for(int i=1;i<N;++i){
		for(int k=0;k<=K;++k){
			if(k!=K) dp[k+1][i+1] += dp[k][i] * (1.0 / (K+1));
			dp[k][i+1] += dp[k][i] * (1.0 / (K+1));
			if(k!=0) dp[k-1][i+1] += dp[k][i] * (1.0 / (K+1));
		}
	}
	double ans = 0;
	for(int i=0;i<=K;++i){
		ans += dp[i][N];
	}
	printf("%.5lf\n", ans * 100.0);
}

int main(){
	while(scanf("%d%d",&K,&N)!=EOF) {
		solve();
	}
	return 0;
}