#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int maxint = (int) 1e9;
int x[43], y[43];
int dp[43][301][301];
int rec(int S, int i, int X, int Y){
	int tot = X*X + Y*Y;
	if(tot == S) return 0;
	if(tot > S) return maxint;
	if(i < 0) return maxint;
	if(dp[i][X][Y] != -1) return dp[i][X][Y];
	int ret = min(1+rec(S, i, X+x[i], Y+y[i]), rec(S, i-1, X, Y));
	dp[i][X][Y] = ret;
	//printf("S: %d i: %d X: %d Y: %d M: %d ret: %d\n", S, i, X, Y, M, ret);
	return ret;
}

int main(){
	int TC,N,S;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &N, &S);
		for(int i=0;i<N;++i){
			scanf("%d %d", &x[i], &y[i]);
		}
		for(int i=0;i<43;++i)
			for(int j=0;j<301;++j)
				for(int k=0;k<301;++k)
					dp[i][j][k] = -1;
		int ans = rec(S*S, N-1, 0, 0);
		if(ans >= maxint) printf("not possible\n");
		else printf("%d\n", ans);
	}
	return 0;
}