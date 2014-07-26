//TOPOLOGICAL SORTING
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int vis[50004];
int cc[50004];
int sz[50004];
int par[50004];
vector<pair<int, int> > tout;
vector<vector<int> > adj;
int N;
int t, ff;

void dfs(int u){
	vis[u] = 0;
	for(int i=0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(vis[v] == -1){
			dfs(v);
		}
	}
	tout.push_back(make_pair(t++, u));
}

void flood(int u){
	cc[u] = ff;
	++sz[ff];
	for(int i=0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(cc[v] == -1){
			flood(v);
		}
	}
}

int main(){
	int TC, T=1;
	scanf("%d",&TC);
	while(TC--){
		printf("Case %d: ", T++);
		tout.clear();
		scanf("%d",&N);
		adj = vector<vector<int> >(N+3);
		t = 0; ff = 0;

		for(int i=0;i<=N;++i){
			vis[i] = -1;
			cc[i] = -1;
		}
		for(int i=0;i<N;++i){
			int u,v;
			scanf("%d %d",&u, &v);
			adj[u].push_back(v);
		}
		for(int i=1;i<=N;++i){
			if(vis[i] == -1){
				dfs(i);
			}
		}
		sort(tout.begin(), tout.end());
		for(int i = N; i >= 1; --i){
			if(cc[tout[i].second] == -1){
				++ff;
				sz[ff] = 0;
				par[ff] = tout[i].second;
				flood(tout[i].second);
			}
		}
		int maxval = -1, idx = -1;
		for(int i=1;i<=ff;++i){
			//printf("%d\n", sz[i]);
			if(maxval < sz[i]){
				maxval = sz[i];
				idx = i;
			}
		}
		printf("%d\n", par[idx]);
	}
	return 0;
}