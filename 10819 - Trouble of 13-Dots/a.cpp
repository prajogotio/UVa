#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
int M,N;
pair<int,int> pf[104];
int max_int = (int) 1e9;

int dp[104][10300];

int ks(int i, int S){
	/*
	if(S < 0) return -max_int;
	if(S == 0 || i < 0) return 0;
	*/
	if(S > 2000){
		if(S - 200 > M) return -max_int;
		else if(S - 200 == M) return 0;
	}
	if(S <= 2000){
		if (S > M) return -max_int;
		else if(S == M) return 0;
	}
	if(i < 0) return 0;
	if(dp[i][S] != -1) return dp[i][S];
	int temp = max(pf[i].second + ks(i-1, S+pf[i].first), ks(i-1, S));
	dp[i][S] = temp;
	return temp;
}

int main(){
	while(scanf("%d %d", &M, &N)!=EOF){
		//if(M > 2000) M += 200;
		for(int i=0;i<N;++i){
			scanf("%d %d", &(pf[i].first), &(pf[i].second));
		}
		for(int i=0;i<104;++i)
			 for(int k=0;k<10300;++k)
			 		dp[i][k] = -1;
		int ans = ks(N-1, 0);
		printf("%d\n", ans);
	}
	return 0;
}