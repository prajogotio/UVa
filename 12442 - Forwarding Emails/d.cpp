
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int dfs_low[50004];
int dfs_num[50004];
int par[50004];
int vis[50004];
int sz[50004];
vector<vector<int> > adj;
vector<int> st;
int ctr;
int N;


void dfs(int u){
	vis[u] = 0;
	dfs_num[u] = dfs_low[u] = ctr++;
	st.push_back(u);
	for(int i=0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(vis[v] == -1){
			par[v] = u;
			dfs(v);
		}
		//else if(par[u] != v){
		//	sz[u] = max(sz[u], sz[v] + 1);
		else dfs_low[u] = min(dfs_low[v], dfs_low[u]);
		//}
	}
	if(dfs_low[u] == dfs_num[u]){
		vector<int> temp;
		int v;
		while(1){
			v = st.back();
			st.pop_back();
			temp.push_back(v);
			if(u == v)break;
		}
		int res = temp.size();
		while(!temp.empty()){
			sz[temp.back()] = max(res, sz[temp.back()]);
			temp.pop_back();
		}
	}
}

int main(){
	int TC;
	scanf("%d",&TC);
	for(int T=1;T<=TC;++T){
		printf("Case %d: ", T);
		scanf("%d", &N);
		st.clear();
		ctr = 0;
		adj = vector<vector<int> >(N+3);
		for(int i=1;i<=N;++i){
			par[i] = -1;
			vis[i] = -1;
			sz[i] = 0;
			dfs_low[i] = -1;
			dfs_num[i] = -1;
		}
		for(int i=1;i<=N;++i){
			int u,v;
			scanf("%d %d",&u,&v);
			adj[u].push_back(v);
		}
		int maxval = -1, idx = -1;
		for(int i=1;i<=N;++i){
			if(vis[i] == -1){
				dfs(i);
			}
			if(maxval < sz[i]){
				maxval = sz[i];
				idx = i;
			}
		}
		
		for(int i=1;i<=N;++i){
			printf("%d: %d\n",i, dfs_low[i]);
		}

		printf("%d\n", idx);
	}
	return 0;
}