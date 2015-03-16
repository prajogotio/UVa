#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
	M(i) = minimum amount of time needed from [0 .. i]
	M(i) = min [j < i] M(j) + cost
*/

int N;
int A[105];
double dp[105], cost[105][10005];
double B;
int R;
double V, E, F;
double INF = 1e308;

void solve() {
	A[0] = 0;
	for(int i=0;i<=N;++i){
		cost[i][A[i]] = 0;
		for(int j=A[i]+1;j<=10000;++j){
			int X = j-A[i]-1;
			double curCost = (X < R ? 1.0 / (V - F * (R - X)) : 1.0 / (V - E * (X - R)));
			cost[i][j] = cost[i][j-1] + curCost;
		}
	}
	for(int i=1;i<=N;++i){
		dp[i] = cost[0][A[i]];
		for(int j=1;j<i;++j){
			dp[i] = min(dp[i], dp[j] + cost[j][A[i]] + B);
		}
	}
	printf("%.4f\n", dp[N]);
}

int main(){
	while(scanf("%d", &N), N>0) {
		for(int i=1;i<=N;++i) scanf("%d", &A[i]);
		scanf("%lf%d%lf%lf%lf", &B, &R, &V, &E, &F);
		solve();
	}
	return 0;
}