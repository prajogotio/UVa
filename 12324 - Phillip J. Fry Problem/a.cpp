#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
S[i][k] = minimum number of time needed to finish trip [i..n] starting with k spheres
S[i][k] = min S[i+1][k+b[i]] + t[i], S[i+1][k+b[i]-1] + t[i]/2
*/

int dp[103][10003];
int b[103];
int t[103];
int N;

void solve_faster() {
	for(int i=0;i<=N;++i)dp[N][i] = 0;
	for(int i=N-1;i>=0;--i){
		for(int k=0;k<=N;++k){
			dp[i][k] = 12345678;
			dp[i][k] = min(dp[i+1][min(N, k+b[i])] + t[i], dp[i][k]);
			if(k>0) dp[i][k] = min(dp[i+1][min(N, k+b[i]-1)] + t[i]/2, dp[i][k]);
		}
	}
	printf("%d\n",dp[0][0]);
}

void solve() {
	for(int i=0;i<=N*N;++i)dp[N][i] = 0;
	for(int i=N-1;i>=0;--i){
		for(int k=0;k<=N*N;++k){
			dp[i][k] = 12345678;
			if(k+b[i]>N*N) continue;
			dp[i][k] = min(dp[i+1][k+b[i]]+t[i], dp[i][k]);
			if(k>0) dp[i][k] = min(dp[i+1][k+b[i]-1]+t[i]/2, dp[i][k]);
		}
	}
	printf("%d\n", dp[0][0]);
}

int main(){
	while(scanf("%d",&N), N!=0){
		for(int i=0;i<N;++i){
			scanf("%d%d",&t[i],&b[i]);
		}
		solve_faster();
	}
	return 0;
}