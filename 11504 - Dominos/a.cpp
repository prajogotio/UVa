#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;
vi low, vis, par, onstack, check;
vi st, st2;
int num, N, M;

void dfs(int u){
	low[u] = vis[u] = num++;
	onstack[u] = 1;
	st.push_back(u);
	for(int i=0;i<adj[u].size(); ++i){
		int v = adj[u][i];
		if(vis[v] == -1){
			//printf("%d %d\n", u, v);
			par[v] = u;
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(onstack[v]){
			low[u] = min(low[u], vis[v]);
		}
	}
	if(low[u] == vis[u]){
		int v;
		while(1){
			v = st.back();
			st.pop_back();
			onstack[v] = 0;
			st2.push_back(v);
			if(v == u) break;
		}
	}
}

void dfs2(int u){
	check[u] = 1;
	for(int i=0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(check[v] == -1){
			//printf("dfs 2 %d %d\n", u, v);
			dfs2(v);
		}
	}
}

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &N, &M);
		adj = vector<vi>(N+3);
		vis = vi(N+3, -1);
		low = vi(N+3);
		par = vi(N+3, -1);
		check = vi(N+3, -1);
		onstack = vi(N+3, 0);
		st.clear(); st2.clear(); 
		num = 0;
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
		int ans = 0;
		//for(int i=0;i<st2.size(); ++i) printf("%d ", st2[i]); printf("\n");
		while(!st2.empty()){
			int u = st2.back();
			st2.pop_back();
			if(check[u] == -1){
				//printf("%d\n", u);
				++ans;
				dfs2(u);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}