#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int choice[90];
int val[1<<9];
int dp[1<<9];
int N;
void solve() {
	for(int i=0;i<(1<<9);++i) dp[i] = -1;
	dp[0] = 0;
	for(int k=0;k<9;k+=3){
		for(int b=0;b<(1<<9);++b){
			int m = __builtin_popcount(b);
			if(m!=k)continue;
			if(dp[b] == -1) continue;
			for(int i=0;i<N;++i){
				if(b & choice[i]) continue;
				dp[b | choice[i]] = max(dp[b | choice[i]], dp[b] + val[choice[i]]);
			}
		}
	}
	printf("%d\n",dp[(1<<9)-1]);
}

int main(){
	int tc = 1;
	int x;
	while(scanf("%d",&N), N!=0){
		for(int i=0;i<90;++i){choice[i] = -1; }
		for(int i=0;i<(1<<9);++i){val[i] = -1; }
		for(int i=0;i<N;++i){
			int b = 0;
			for(int j=0;j<3;++j){
				scanf("%d",&x);
				b |= (1<<(x-1));
			}
			scanf("%d",&x);
			choice[i] = b;
			val[b] = max(val[b], x);
		}
		printf("Case %d: ", tc++);
		solve();
	}
	return 0;
}