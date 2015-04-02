#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int INF = 500000000;
int N, L, C;
int dp[1005][1005];
int low[1005];
int hi[1005];
int sum[1005];
int t[1005];

int getDi(int val) {
	if (val == 0) return val;
	if (val <= 10) return -C;
	return (val - 10) * (val - 10);
}

void solve(){
	sum[0] = 0;
	for(int i=1;i<=N;++i){
		sum[i] = sum[i-1] + t[i];
	}
	int trail = 0;
	int cnt = 1;
	for(int i=1;i<=N;++i){
		trail += t[i];
		if(trail > L) {
			trail = t[i];
			cnt++;
		}
		low[i] = cnt;
	}
	trail = 0;
	for(int i=N;i>=1;--i){
		trail += t[i];
		if(trail > L) {
			trail = t[i];
			cnt--;
		}
		hi[i] = cnt;
	}

	for(int i=0;i<1005;++i){
		for(int j=0;j<1005;++j){
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	low[0] = hi[0] = 0;
	for(int k=1;k<=N;++k){
		for(int i=low[k];i<=hi[k];++i){
			for(int j=k-1;j>=0;--j){
				int val = L - (sum[k] - sum[j]);
				if (val >= 0) {
					dp[i][k] = min(dp[i][k], dp[i-1][j] + getDi(val));
				} else {
					break;
				}
			}
		}
	}
	printf("Minimum number of lectures: %d\n", low[N]);
	printf("Total dissatisfaction index: %d\n", dp[low[N]][N]);
}

int main(){
	int tc = 1;
	while(scanf("%d",&N),N!=0){
		if(tc != 1)printf("\n");
		scanf("%d%d",&L,&C);
		for(int i=1;i<=N;++i) scanf("%d",&t[i]);
		printf("Case %d:\n", tc++);
		solve();
	
	}
}