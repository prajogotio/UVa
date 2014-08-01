#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

vector<vector<pair<int,int> > > adj;
vector<int> onstack;
int N, M, ans, tot; 

void prim(int u){
	ans = 0;
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(0, u));
	while(!pq.empty()){
		int v;
		while( v = pq.top().second, onstack[v] ) {pq.pop(); if(pq.empty()) return;}
		onstack[v] = 1;
		ans -= pq.top().first;
		pq.top();
		for(int i=0;i<adj[v].size();++i){
			int w = adj[v][i].first;
			int len = adj[v][i].second;
			if(onstack[w]) continue;
			pq.push(make_pair(-len, w));
		}
	}
}

int main(){
	while(scanf("%d %d", &N, &M), N+M!=0){
		adj = vector<vector<pair<int,int> > >(N+3);
		onstack = vector<int>(N+3, 0);
		tot = 0;
		for(int i=0;i<M;++i){
			int u,v,w;
			scanf("%d %d %d", &u, &v, &w);
			tot += w;
			adj[u].push_back(make_pair(v,w));
			adj[v].push_back(make_pair(u,w));
		}
		prim(0);
		printf("%d\n", tot - ans);
	}
	return 0;
}

