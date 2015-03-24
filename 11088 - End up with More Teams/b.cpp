#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;


/* WRONG UPDATE RULE the other way around */

int dp[1<<15][100];
int a[20];
int N;
void solve(){
	for(int b=0;b<(1<<15);++b){
		for(int i=0;i<100;++i){
			dp[b][i] = -1;
		}
	}
	dp[0][0] = 0;
	int ans = 0;
	for(int K=1;K<=N;++K){
		for(int b=0;b<(1<<N);++b){
			int n = 0;
			for(int i=0;i<N;++i) if(b & (1<<i)) ++n; 
			if(n!=K)continue;
			for(int i=0;i<=90;++i){
				for(int j=0;j<N;++j){
					if(b & (1<<j)) {
						if(i-a[j]<0) continue;
						dp[b][i] = max(dp[b^(1<<j)][i-a[j]], dp[b][i]);
					}
				}
			}
			if(n%3==0) {
				int cur = -1;
				int prev = -1;
				for(int i=20;i<=90;++i){
					cur = max(cur, dp[b][i]);
				}
				for(int i=0;i<19;++i){
					prev = max(prev, dp[b][i]);
				}
				for(int i=0;i<=90;++i) dp[b][i] = -1;
				dp[b][0] = max(cur+1, prev);
				ans = max(dp[b][0], ans);
			}
		}
	}
	printf("%d\n", ans);
}


int main(){
	int tc=1;
	while(scanf("%d",&N), N!=0){
		for(int i=0;i<N;++i)scanf("%d",&a[i]);
		printf("Case %d: ", tc++);
		solve();
	}
	return 0;
}