#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

typedef vector<int> vi;

vector<vi> adj;
vi par, low, vis, pv;
set<pair<int,int> > ans;
int num,child,N,M;

void dfs(int u){
	vis[u] = low[u] = num++;
	bool add = true;
	for(int i=0;i<adj[u].size(); ++i){
		int v = adj[u][i];
		if(vis[v] == -1){
			par[v] = u;
			dfs(v);
			if(par[u] == -1){
				++child;
				continue;
			}
			low[u] = min(low[v], low[u]);
			if(low[v] >= vis[u]){
				++pv[u];
			} else {
				add = false;
			}
		} else if(par[u] != v){
			low[u] = min(vis[v], low[u]);
		}
	}
	if(par[u] == -1) return;
	//if (add) ++pv[u];
	ans.insert(make_pair(pv[u], -u));
}

int main(){
	while(scanf("%d %d", &N, &M), N+M!=0){
		par.assign(N+2, -1);
		adj.assign(N+2, vi());
		low.assign(N+2, 0);
		vis.assign(N+2, -1);
		pv.assign(N+2, 1);
		child = 0;
		num = 0;
		ans.clear();
		int u,v;
		while(scanf("%d %d", &u, &v), u+v != -2){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(0);
		pv[0] += child-1;
		//printf("%d\n", child);
		ans.insert(make_pair(pv[0], 0));
		set<pair<int, int> >::iterator it;
		it = ans.end();
		/*
		for(int i=0;i<N;++i){
			printf("%d %d %d\n", i, vis[i], low[i]);
		}
		*/
		while(it != ans.begin() && M--){
			--it;
			printf("%d %d\n", -it->second, it->first);
		}
		printf("\n");
	}
	return 0;
}