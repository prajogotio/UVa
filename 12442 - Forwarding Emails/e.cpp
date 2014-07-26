#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int adj[50004];
int vis[50004];
int ons[50004];
int low[50004];
int idx[50004];
int sz[50004];
vector<int> st;
int ctr, N;

void scc(int u){
	vis[u] = 1;
	ons[u] = 1;
	low[u] = idx[u] = ctr++;
	st.push_back(u);
	int v = adj[u];
	//printf("%d\n", v);
	if(vis[v] == -1){
		scc(v);
		low[u] = min(low[u], low[v]);
		if(low[u] < low[v]){
			sz[u] = sz[v] + 1;
			st.pop_back();
			ons[u] = 0;
			return;
		}
	} else if(ons[v] == 1){
		low[u] = min(low[u], idx[v]);
	} else {
		sz[u] = sz[v] + 1;
		st.pop_back();
		ons[u] = 0;
		return;
	}
	if(low[u] == idx[u]){
		int temp = 0;
		vector<int> tt;
		while(1){
			int k = st.back();
			tt.push_back(k);
			st.pop_back();
			ons[k] = 0;
			if(u == k) break;
		}
		temp = tt.size();
		while(!tt.empty()){
			sz[tt.back()] = temp;
			tt.pop_back();
		}
	}
}

int main(){
	int TC, T=1;
	scanf("%d", &TC);
	while(TC--){
		printf("Case %d: ", T++);
		scanf("%d",&N);
		ctr = 1;
		for(int i=0;i<N;++i){
			int u, v;
			scanf("%d %d", &u, &v);
			adj[u] = v;
		}
		for(int i=1;i<=N;++i){
			vis[i] = -1;
			ons[i] = -1;
			sz[i] = 0;
		}
		int maxval = -1, ans = -1;
		for(int i=1;i<=N;++i){
			if(vis[i] == -1){
				scc(i);
				if(sz[i] > maxval){
					maxval = sz[i];
					ans = i;
				}
			}
		}
		/*
		for(int i=1;i<=N;++i){
			printf("%d %d\n", i, low[i]);
		}
		*/
		printf("%d\n", ans);
	}
	return 0;
}