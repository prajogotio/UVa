#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int maxi = (int) 1e9;
int x[11];
int y[11];
int dp[11][2048];
int N;

int dist(int i, int j){
	int dx = x[i] - x[j];
	int dy = y[i] - y[j];
	if(dx  < 0) dx = -dx;
	if(dy < 0) dy = -dy;
	return dy + dx;
}

int tsp(int init, int pos, int ch){
	if(ch == (1<<N+1)-1) {
		return dist(init, pos);
	}
	if(dp[pos][ch] != -1) return dp[pos][ch];
	int temp = maxi;
	for(int i=1;i<N+1;++i){
		if(ch & (1<<i))continue;
		temp = min(temp, dist(pos, i) + tsp(init, i, ch | (1<<i)) );
	}
	dp[pos][ch] = temp;
	return temp;
}

int main(){
	int TC,X,Y;
	scanf("%d",&TC);
	while(TC--){
		scanf("%d %d",&X,&Y);
		scanf("%d %d",&x[0], &y[0]);
		scanf("%d",&N);
		for(int i=0;i<11;++i)
			for(int j=0;j<2048;++j)
				dp[i][j] = -1;
		for(int i=1;i<N+1;++i){
			scanf("%d %d", &x[i], &y[i]);
		}
		int ans = maxi;
		for(int i=1;i<N+1;++i){
			ans = min(dist(0, i) + tsp(0,i,(1 | (1<<i))) , ans);
		}
		printf("The shortest path has length %d\n", ans);
	}
	return 0;
}