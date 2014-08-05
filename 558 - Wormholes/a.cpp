#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int maxint = (int) 1e9;
vector<pair<pair<int,int>, int> > edge;
int dist[1003];
int N,M;
bool ans;
void bellmanford(){
	for(int i=0;i<=N;++i) dist[i] = maxint;
	dist[0] = 0;
	for(int k=0;k<M+1;++k){
		for(int i=0;i<M;++i){
			int u = edge[i].first.first;
			int v = edge[i].first.second;
			int w = edge[i].second;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
			}
		}
	}
	bool cycle = false;
	for(int i=0;i<M;++i){
		int u = edge[i].first.first;
		int v = edge[i].first.second;
		int w = edge[i].second;
		if(dist[v] > dist[u] + w){
			cycle = true;
			break;
		}
	}	
	ans = cycle;
}

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &N, &M);
		edge.clear();
		for(int i=0;i<M;++i){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			edge.push_back(make_pair(make_pair(u,v), w));
		}
		bellmanford();
		if(ans) printf("possible\n");
		else printf("not possible\n");
	}
	return 0;
}