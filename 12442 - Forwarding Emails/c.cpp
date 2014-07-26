#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int vis[50004], dp[50004];
vector<vector<int> > adj;
void dfs(int u){
	vis[u] = 0;
	for(int i=0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(vis[v] == -1){
			dfs(v);
		}
		dp[u] = max(dp[u], dp[v] + 1);
	}
}

int main(){
	int TC, T=1;
	scanf("%d",&TC);
	while(TC--){
		printf("Case %d: ", T++);
		scanf("%d",&N);
		for(int i=1;i<=N;++i){
			vis[i] = -1;
			dp[i] = 0;
		}
		adj = vector<vector<int> >(N+3);
		for(int i=0;i<N;++i){
			int u,v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
		}
		int maxval = -1, idx = -1;
		for(int i=1;i<=N;++i){
			if(vis[i] == -1){
				dfs(i);
			}
			if(maxval < dp[i]){
				maxval = dp[i];
				idx = i;
			}
		}
		printf("\n");
		for(int i=1;i<=N;++i){
			printf("%d : %d\n", i, dp[i]);
		}
		printf("%d\n", idx);
	}
	return 0;
}