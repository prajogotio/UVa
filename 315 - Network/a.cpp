#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int vis[104], low[104], par[104], N, num, child, ans, cc;
int crit[104];
vector<vector<int> > adj;

void dfs(int u){
	vis[u] = low[u] = num++;
	for(int i=0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(vis[v] == -1){
			par[v] = u;
			dfs(v);
			low[u] = min(low[v], low[u]);
			if(u == 1) {++child; continue;}
			if(low[v] >= vis[u]) crit[u] = 1;
		} else if(par[u] != v){
			low[u] = min(vis[v], low[u]);
		}
	}	
}

int main(){
	char buff[1000];
	while(scanf("%d", &N), N!=0){
		getchar();
		adj = vector<vector<int> > (N+3);
		int u,v;
		while(scanf(" %d", &u), u != 0){
			while(scanf(" %d", &v) ){
				adj[u].push_back(v);
				adj[v].push_back(u);
				//printf("%d %d\n", u, v);
				char check = getchar();
				if(check == '\n') break;
			}
		}
		ans = 0, cc = 0, num = 0, child = 0;
		for(int i=1;i<=N;++i) {vis[i] = -1; par[i] = -1; crit[i] = 0;}
		dfs(1);
		/*
		for(int i=1;i<=N;++i){
			printf("%d %d %d\n", i, vis[i], low[i]);
		}
		*/
		/*
		for(int i=1;i<=N;++i){
			//if(low[i] == vis[i]) ++cc;
			if(low[i] == vis[i] 
				&& adj[i].size() > 1
				) ++ans;
		}
		*/
		//if(cc == 1) ans = 0;
		//printf("child: %d\n", child);
		if(child > 1) crit[1] = 1;
		for(int i=1;i<=N;++i){
			if(crit[i]) ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}