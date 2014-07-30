#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;
vi vis, low, par;
set<pair<int,int> > ans;
int num, N;

void dfs(int u){
	vis[u] = low[u] = num++;
	for(int i=0;i<adj[u].size(); ++i){
		int v = adj[u][i];
		if(vis[v] == -1){
			par[v] = u;
			dfs(v);
			low[u] = min(low[v], low[u]);
			if(low[v] > vis[u]){
				int s = u, t = v;
				if(s>t) swap(s,t);
				ans.insert(make_pair(s,t));
			}
		} else if(par[u] != v){
			low[u] = min(vis[v], low[u]);
		}
	}
}

int main(){
	while(scanf("%d", &N)!=EOF){
		num = 0;
		ans.clear();
		adj = vector<vi>(N+2);
		for(int i=0;i<N;++i){
			int u, p;
			scanf("%d (%d)", &u, &p);
			for(int j=0;j<p;++j){
				int v;
				scanf(" %d", &v);
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
		for(int i=0;i<N;++i){
			vis.assign(N+2, -1);
			low.assign(N+2, -1);
			par.assign(N+2, -1);
		}
		for(int i=0;i<N;++i){
			if(vis[i] == -1){
				dfs(i);
			}
		}
		int sz = ans.size();
		printf("%d critical links\n", sz);
		for(set<pair<int,int> >::iterator it = ans.begin(); it!=ans.end(); ++it){
			printf("%d - %d\n", it->first, it->second);
		}
		printf("\n");
	}
	return 0;
}