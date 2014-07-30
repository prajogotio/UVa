#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int vis[103];
vector<vector<int> > adj;
vector<int> tsort;

void dfs(int u){
	vis[u] = 1;
	for(int i=0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(vis[v] == -1){
			dfs(v);
		}
	}
	tsort.push_back(u);
}

int main(){
	while(scanf("%d %d", &N, &M), N+M!=0){
		for(int i=1;i<=N;++i) vis[i] = -1;
		adj = vector<vector<int> >(N+2);
		tsort.clear();
		for(int i=0;i<M;++i){
			int u,v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
		}
		for(int i=1;i<=N;++i){
			if(vis[i] == -1){
				dfs(i);
			}
		}
		for(int i=0;i<N;++i){
			if(i != 0) printf(" ");
			printf("%d", tsort[N-i-1]);
		}
		printf("\n");
	}
	return 0;
}