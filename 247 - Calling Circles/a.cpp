#include <string>
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;
map<string, int> dict;
vector<vi> adj;
vi par, vis, low, st, onstack;
vector<string> name;
int num, N, M;

void dfs(int u){
	onstack[u] = 1;
	st.push_back(u);
	vis[u] = low[u] = num++;
	for(int i=0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(vis[v] == -1){
			par[v] = u;
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(onstack[v]){ //if not onstack, will lead to other scc. 
			low[u] = min(low[u], vis[v]);
		}
	}
	int ctr = 0;
	//printf("%d %d %d\n",u, vis[u], low[u]);
	if(low[u] == vis[u]){
		while(1){
			int v = st.back();
			st.pop_back();
			onstack[v] = 0;
			if(ctr != 0) cout << ", ";
			cout << name[v];
			++ctr;
			if(v == u) break;
		}
		printf("\n");
	}
}

int main(){
	int T=1;
	string first, second;
	bool flag = false;
	int u,v, idx;
	while(scanf("%d %d", &N, &M), N+M!= 0){
		if(flag) printf("\n");
		printf("Calling circles for data set %d:\n", T++);
		dict.clear();
		adj.assign(N+2, vi());
		par.assign(N+2, -1);
		vis.assign(N+2, -1);
		low.assign(N+2, -1);
		st.clear();
		onstack.assign(N+2, 0);
		name.clear();

		num = 0;
		idx = 0;
		for(int i=0;i<M;++i){
			cin >> first >> second;
			if(dict.find(first) != dict.end() ){
				u = dict[first];
			} else {
				dict[first] = idx;
				name.push_back(first);
				u = idx;
				++idx;
			}

			if(dict.find(second) != dict.end()){
				v = dict[second];
			} else {
				dict[second] = idx;
				name.push_back(second);
				v = idx;
				++idx;
			}

			adj[u].push_back(v);
		}
		for(int i=0;i<N;++i){
			if(vis[i] == -1){
				dfs(i);
			}
		}
		flag = true;
	}
	return 0;
}
