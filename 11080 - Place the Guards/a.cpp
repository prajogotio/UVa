#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int vis[205];
int cc[205];
int b[205];
bool can;
vector<vector<int> > adj;
int N, ff;

void dfs(int u, int state){
	if(!can) return;
	vis[u] = state;
	++cc[ff];
	if(state == 1) ++b[ff];
	for(int i=0;i<adj[u].size(); ++i){
		int v= adj[u][i];
		if(vis[v] == -1){
			dfs(v, (state+1) % 2);
		} else {
			if(vis[v] == state) {
				can = false;
				return;
			}
		}
	}
}

int main(){
	int TC, M;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &N, &M);
		adj = vector<vector<int> > (N+3);
		for(int i=0; i<N;++i){
			vis[i] = -1;
			b[i] = 0;
			cc[i] = 0;
		}
		for(int i=0;i<M;++i){
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		can = true;
		ff = 0;
		int maxval = 0;
		for(int i=0;i<N;++i){
			if(vis[i] != -1) continue;
			dfs(i, 1);
			int temp = min(cc[ff] - b[ff], b[ff]);
			if(temp == 0) temp = 1;
			maxval += temp;
			if(!can) break;
			++ff;
		}
		if(!can) {
			printf("-1\n");
			continue;
		} else {
			printf("%d\n", maxval);
		}
	}
	return 0;
}