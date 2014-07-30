#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

int vis[204];
vector<vector<int> > adj;
int N, M;
bool can;
void dfs(int u, int state){
	if(!can) return;
	vis[u] = state;
	for(int i=0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(vis[v] == -1){
			dfs(v, (state+1)%2);
		} else {
			if(vis[v] == vis[u]) {
				can = false;
				return;
			}
		}
	}
}

int main(){
	while(scanf("%d", &N), N!=0){
		scanf("%d", &M);
		adj = vector<vector<int> > (N+2);
		for(int i=0;i<N;++i) vis[i] = -1;
		can = true;
		for(int i=0;i<M;++i){
			int u,v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(0, 0);
		if(can) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}
	return 0;
}