#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;



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
	for(int K=0;K<=N;++K){
		for(int b=0;b<(1<<N);++b){
			int n = 0;
			for(int i=0;i<N;++i) if(b & (1<<i)) ++n; 
			if(n!=K)continue;
			if(n!=0 && n%3==0){
				int cnt = -1;
				int prev = -1;
				for(int i=20;i<=90;++i){
					cnt = max(dp[b][i],cnt);
					dp[b][i] = -1;
				}
				for(int i=0;i<=19;++i) {
					prev = max(dp[b][i], prev);
					dp[b][i] = -1;
				}
				dp[b][0] = max(cnt+1, prev);
				ans = max(dp[b][0], ans);
			}
			for(int i=0;i<90;++i){
				if(dp[b][i]!=-1){
					for(int j=0;j<N;++j){
						if(b & (1<<j)) continue;
						dp[b|(1<<j)][i+a[j]] = max(dp[b|(1<<j)][i+a[j]], dp[b][i]);
					}
				}
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