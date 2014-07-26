#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int maxint = (int) 1e9;
int N;
int p[10][1004];
int dp[10][1004];

int rec(int alt, int i){
	if(i == N && alt == 0) return 0;
	if(alt < 0 || i >= N || alt > 9) return maxint;
	if(dp[alt][i] != -1) return dp[alt][i];
	int temp = min(30+rec(alt, i+1), min(60 + rec(alt+1, i+1), 20 + rec(alt-1, i+1)));
	temp -= p[alt][i];
	dp[alt][i] = temp;
	return temp;
}

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		for(int i=0;i<10;++i)
			for(int j=0;j<1004; ++j)
				dp[i][j] = -1;

		scanf("%d",&N);
		N /= 100;
		for(int i=0;i<10;++i){
			for(int j=0;j<N;++j){
				scanf("%d", &p[10-i-1][j]);
			}
		}
		int ans = rec(0,0);
		/*
		for(int i=0;i<10;++i){
			for(int j=0;j<N;++j){
				printf("%d ", dp[10-i-1][j]);
			}
			printf("\n");
		}
		*/
		printf("%d\n\n", ans);
	}
	return 0;
}