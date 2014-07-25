#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[20005][102];
int num[105];
int P, N, minsum, minc;
int maxint = (int) 1e9;

int rec(int S, int i){
	printf("%d %d %d \n", S, i, P);
	if(S >= P) return 0;
	if(i < 0) return maxint;
	if(dp[S][i] != -1) return dp[S][i];
	int ret = min(1+rec(S+num[i], i), rec(S, i-1));
	dp[S][i] = ret;
	if(S >= P){
		printf("hm %d %d %d\n", S, i, P);
		if(minsum > S || (minsum == S && ret < minc) ){
			minsum = S;
			minc = ret;
		}
	}
	return ret;
}

int main(){
	int TC;
	scanf("%d",&TC);
	while(TC--){
		scanf("%d",&P);
		scanf("%d", &N);
		for(int i=0;i<N;++i){
			scanf("%d",&num[i]);
		}
		for(int i=0;i<20005;++i){
			for(int j=0;j<102;++j){
				dp[i][j] = -1;
			}
		}
		minsum = maxint;
		minc = maxint;
		rec(0, N-1);
		printf("%d %d\n", minsum, minc);
	}
	return 0;
}