#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
int maxint = (int) 1e9;
int num[103];
pair<int,int> dp[20003][103];
int P, N;

pair<int,int> dfs(int S, int i){
	if( S >= P ) {
		dp[S][i].first = S;
		dp[S][i].second = 0;
		return make_pair(S,0);
	}
	if( i < 0 ){
		return make_pair(maxint, maxint);
	}
	if( dp[S][i].first != -1 ) return dp[S][i];
	pair<int,int> a = dfs(S+num[i], i-1);
	pair<int,int> b = dfs(S, i-1);
	//printf("%d %d %d %d\n", a.first, a.second, b.first, b.second);
	if(a.first < b.first){
		dp[S][i].first = a.first;
		dp[S][i].second = a.second + 1;
	} else if (a.first > b.first){
		dp[S][i].first = b.first;
		dp[S][i].second = b.second;
	} else {
		dp[S][i].first = a.first;
		dp[S][i].second = min(a.second + 1, b.second);
	}
	return make_pair(dp[S][i].first, dp[S][i].second);
}


int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d",&P);
		scanf("%d",&N);
		for(int i=0;i<N;++i){
			scanf("%d",&num[i]);
		}
		for(int i=0;i<20003;++i){
			for(int j=0;j<103;++j){
				dp[i][j].first  = -1;
			}
		}
		pair<int,int> ans = dfs(0, N-1);
		printf("%d %d\n", ans.first, ans.second);
	}
	return 0;
}