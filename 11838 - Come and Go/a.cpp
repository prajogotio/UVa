#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

vector<vi> adj;
vi par, low, vis, st, onstack;
int num, N, M;
bool can;

void dfs(int u){
	if(!can) return;
	vis[u] = low[u] = num++;
	onstack[u] = 1;
	st.push_back(u);
	for(int i=0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(vis[v] == -1){
			par[u] = v;
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(onstack[v]){
			low[u] = min(low[u], vis[v]);
		}
	}
	if(low[u] == vis[u]){
		int cnt = 0;
		while(1){
			int v = st.back(); st.pop_back();
			++cnt;
			if(u == v) break;
		}
		if(cnt != N){
			can = false;
			return;
		}
	}
}

int main(){
	while(scanf("%d %d", &N, &M), N+M!=0){
		par = vi(N+2, -1);
		low = vi(N+2);
		vis = vi(N+2, -1);
		st.clear();
		onstack = vi(N+2, 0);
		num = 0;
		adj = vector<vi>(N+2);
		can = true;

		for(int i=0;i<M;++i){
			int u, v, p;
			scanf("%d %d %d", &u, &v, &p);
			adj[u].push_back(v);
			if(p==2) adj[v].push_back(u);
		}

		dfs(1);

		if(can) printf("1\n");
		else printf("0\n");
	}
	return 0;
}