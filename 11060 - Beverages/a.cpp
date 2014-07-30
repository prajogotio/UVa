#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int vis[103];
int indeg[103];
map<string, int> dict;
int N, M;
vector<int> st;
vector<vector<int> > adj;
vector<string> label;

void tsort(){
	priority_queue<int> idx;
	while(1){
		//for(int i = 0;i<N; ++i) printf("%d ", indeg[i]); printf ("\n");
		for(int i=0;i<N;++i){
			if(indeg[i] == 0){
				--indeg[i];
				idx.push(-i);
			}
		}
		if(idx.empty()) return;
		int u = -(idx.top());
		idx.pop();
		st.push_back(u);
		for(int i=0;i<adj[u].size();++i){
			--indeg[ adj[u][i] ];
		}
	}
}

void dfs(int u){
	vis[u] = 1;
	for(int i=0;i<adj[u].size(); ++i){
		int v = adj[u][i];
		if(vis[v] == -1){
			dfs(v);
		}
	}
	st.push_back(u);
}

int main(){
	int T=1;
	while(scanf("%d", &N) != EOF){
		dict.clear();
		adj = vector<vector<int> > (N+3);
		label = vector<string > (N+3);
		st.clear();
		for(int i=0;i<N;++i) {vis[i] = -1; indeg[i] = 0;}
		for(int i=0;i<N;++i){
			string str;
			cin >> str;
			dict[str] = i;
			label[i] = str;
		}
		scanf("%d", &M);
		for(int i=0;i<M;++i){
			string a, b;
			cin>> a >> b;
			int u = dict[a], v = dict[b];
			adj[u].push_back(v);
			++indeg[v];
		}
		/*
		for(int i=0;i<N;++i){
			if(vis[i] == -1){
				dfs(i);
			}
		}
		*/
		tsort();
		printf("Case #%d: Dilbert should drink beverages in this order:", T++);
		for(int i=0;i<N;++i){
			cout << " " << label[st[i]];
		}
		printf(".\n\n");
		
	}
	return 0;
}