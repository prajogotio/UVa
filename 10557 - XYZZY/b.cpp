#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

ll maxint = (ll) 1e15;
ll dist[104];
ll weight[104];
vector<pair<int,int> > edge;
vector<vector<int> > adj;
int vis[104];
int V, M;
bool reached;

void dfs(int u){
	if(reached) return;
	if(u == V) {
		reached = true;
		return;
	}
	vis[u] = 0;
	for(int i=0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(vis[v] == -1){
			dfs(v);
		}
	}
}

void bellman(){
	for(int i=0;i<=V;++i) dist[i] = maxint;
	dist[1] = 0;
	for(int i=0;i<V+1;++i){
		for(int j=0;j<M;++j){
			int u = edge[j].first;
			int v = edge[j].second;
			ll w = -weight[v];
			if(dist[u] == maxint) continue;
			if(dist[v] > dist[u] + w && dist[u] + w < 100){				
				dist[v] = dist[u] + w;
			}
			//for(int k=1;k<=V;++k) printf("%d ", dist[k]); printf("\n");
		}
	}
	int cycle[104] = {0};
	for(int i=0;i<M;++i){
		int u = edge[i].first;
		int v = edge[i].second;
		ll w = -weight[v];
		if(dist[u] == maxint) continue;
		if(dist[v] > dist[u] + w && dist[u] + w < 100){
			for(int i=0;i<104;++i) vis[i] = -1;
			dfs(u);
			if(reached) break;
		}
	}
}

int main(){
	while(scanf("%d", &V), V!=-1){
		edge.clear();
		adj = vector<vector<int> > (V+2);
		M = 0;
		for(int i=1;i<=V;++i){
			int w,e,v;
			scanf("%d %d", &w, &e);
			weight[i] = w;
			M+=e;
			for(int j=0;j<e;++j){
				scanf("%d", &v);
				edge.push_back(make_pair(i, v));
				adj[i].push_back(v);
			}
		}
		reached = false;
		bellman();
		//for(int i=1;i<=V;++i) printf("%d %d\n", i, dist[i]);
		if(reached || dist[V] < 100) printf("winnable\n");
		else printf("hopeless\n");
	}
	return 0;
}