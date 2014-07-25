#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int maxint = (int) 1e9;
int x[43];
int y[43];
int dp[43][90003];
int N;
//READ WRONGLY
int rec(int i, int S, int X, int Y, int M){
	int tot = X*X + Y*Y;
	printf("%d %d %d %d %d %d\n", i, S, X, Y, M, tot);
	if(S < tot) return maxint;
	if(S == tot) return M;
	if(i < 0) return maxint;
	if(dp[i][S] != -1) return dp[i][S];
	int ret = min( rec(i-1, S, X+x[i], Y+y[i], M+1), rec(i-1, S, X,Y,M));
	dp[i][S] = ret;
	return ret;
}

int main(){
	int tc, S;
	scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&N, &S);
		for(int i=0;i<N;++i){
			scanf("%d %d", &x[i], &y[i]);
		}
		for(int i=0;i<43;++i){
			for(int j=0;j<S*S;++j){
				dp[i][j] = -1;
			}
		}
		int ans = rec(N-1, S*S, 0, 0, 0);
		if(ans >= maxint) printf("not possible\n");
		else printf("%d\n", ans);
	}
	return 0;
}