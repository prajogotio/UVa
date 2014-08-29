#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int vis[27], par[27];
vector<vector<int> > adj;
int ans, M, N, u, v;

//wrong because a vertex can be passed many times, but edges can only be used once.
void dfs(int u, int len){
	vis[u] = 1;
	ans = max(ans, len);
	for(int i=0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(!vis[v]){ par[v] = u; dfs(v, len+1); par[v] = -1; }
		else if (par[u] != v) { ans = max(ans, len+1); }
	}
	vis[u] = 0;
}

int main(){
	for(int i=0;i<27;++i){ vis[i] = 0; par[i] = -1; }
	while(scanf("%d %d", &N, &M), N+M != 0){
		adj = vector<vector<int> >(N+3);
		ans = 0;
		for(int i=0;i<M;++i){
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i=0;i<N;++i){
			dfs(i, 0);
		}
		printf("%d\n", ans);
	}
	return 0;
}