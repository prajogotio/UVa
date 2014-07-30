#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
int vis[303], N;
bool can = true;

void dfs(int u, int state){
	if(!can) return;
	vis[u] = state;
	for(int i=0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(vis[v] == -1){
			dfs(v, (state + 1) %2);
		} else {
			if(vis[v] == state){
				can = false;
				return;
			}
		}
	}
}

int main(){
	while(scanf("%d", &N), N!=0){
		can = true;
		adj = vector<vector<int> > (N+3);
		int u,v;
		while(scanf("%d %d", &u, &v), u+v!= 0){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i=0;i<=N;++i){
			vis[i] = -1;
		}
		for(int i=1; i<=N;++i){
			if(vis[i] == -1){
				dfs(i, 0);
				if(!can) break;
			}
		}
		if(!can) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
