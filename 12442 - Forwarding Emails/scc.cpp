#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int idx[50004];
int low[50004];
int ctr;
vector<vector<int> > adj;
vector<int> st;
int ons[50004];
int vis[50004];
int ff;
void scc(int u){
	idx[u] = low[u] = ctr++;
	ons[u] = 1;
	vis[u] = 1;
	st.push_back(u);
	for(int i=0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(vis[v] == -1){
			scc(v);
			low[u] = min(low[u], low[v]); //update lowlink of u
		} else if(ons[v] == 1){ //if on stack
			//if not on stack, its already commited as scc
			low[u] = min(low[u], idx[v]);
			//note : not min(low[u], low[v]). this is to update the lowlink of u in scc 
		}
	}
	if(low[u] == idx[u]){
		printf("SCC:\n");
		while(1){
			int v = st.back();
			printf("%d\n", v);
			st.pop_back();
			ons[v] = 0;
			if(u == v) break;
		}
	}
}

int main(){
	int TC, T=1;
	scanf("%d",&TC);
	while(TC--){
		printf("Case %d: \n", T++);
		scanf("%d",&N);
		for(int i=1;i<=N;++i){
			vis[i] = -1;
			ons[i] = -1;
		}
		ctr = 0;
		adj = vector<vector<int> >(N+3);
		for(int i=0;i<N;++i){
			int u,v;
			scanf("%d %d", &u, &v);
			adj[u].push_back(v);
		}
		for(int i=1;i<=N;++i){
			if(vis[i] ==-1){
				scc(i);
			}
		}
	}
	return 0;
}