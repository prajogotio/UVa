#include <iostream>
#include <cstdio>
using namespace std;

int adj[27][27];
int vis[27][27];
int ans, M, N;

//BACTRACK ON THE EDGES!

void dfs(int u, int len){
	ans = max(ans, len);
	for(int i=0;i<N;++i){
		if(adj[u][i] && !vis[u][i]){
			vis[u][i] = 1; vis[i][u] = 1;
			dfs(i, len+1);
			vis[u][i] = 0; vis[i][u] = 0;
		}
	}
}

int main(){
	int u,v;
	for(int i=0;i<27;++i)
		for(int j=0;j<27;++j){
			vis[i][j] = 0;
			if(i == j) vis[i][i] = 1;
		}
		
	while(scanf("%d %d", &N, &M), N+M != 0){
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				adj[i][j] = 0;
		for(int i=0;i<M;++i){
			scanf("%d %d", &u, &v);
			adj[u][v] = 1;
			adj[v][u] = 1;
		}
		ans = 0;
		for(int i=0;i<N;++i){
			dfs(i, 0);
		}
		printf("%d\n", ans);
	}
	return 0;
}