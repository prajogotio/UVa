#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll dp[53][53][53];

ll bc(int n, int k, int m){
	if(n==0 && k==0) return 1;
	if(n<0 || k <= 0) return 0;
	if(dp[n][k][m] != -1) return dp[n][k][m];
	ll ans = 0;
	for(int i=1;i<=m;++i){
		ans += bc(n-i, k-1, m);
	}
	dp[n][k][m] = ans;
	return ans;
}

int main(){
	int N,K,M;
	while(scanf("%d %d %d\n", &N,&K,&M)!=EOF){
		for(int i=0;i<53;++i)
			for(int j=0;j<53;++j)
				for(int k=0;k<53;++k)
					dp[i][j][k] = -1;

		ll ans = bc(N, K, M);
		printf("%lld\n", ans);
	}
	return 0;
}