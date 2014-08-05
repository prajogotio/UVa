#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
ll maxll = (ll) 1e18;
vector<pair<pair<int, int>, ll> > edge;
int cost[203];
ll dist[203];
int N, M;

void bellman(){
	for(int i = 0;i<=N;++i) dist[i] = maxll;
	dist[1] = 0;
	for(int k=0;k<M+1;++k){
		bool relaxed = false;
		for(int i=0;i<M;++i){
			int u =	edge[i].first.first;
			int v = edge[i].first.second;
			ll w = edge[i].second;
			if(dist[u] == maxll) continue;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				relaxed = true;
			}
		}
		if(!relaxed) break;
	}
	for(int i = 0; i< M;++i){
		int u = edge[i].first.first;
		int v = edge[i].first.second;
		ll w = edge[i].second;
		if(dist[u] == maxll) continue;
		if(dist[v] > dist[u] + w){
			dist[u] = -maxll;
			dist[v] = -maxll;
		}
	}
}

int main(){
	int u,v,w,Q,q, T=1;
	while(cin >> N){
		printf("Set #%d\n", T++);
		for(int i=1;i<=N;++i) scanf("%d", &cost[i]);
		edge.clear();
		scanf("%d", &M);
		for(int i=0;i<M;++i){
			scanf("%d %d", &u, &v);
			w = cost[v] - cost[u];
			w = w*w*w;
			edge.push_back(make_pair(make_pair(u,v), w));
		}
		bellman();
		scanf("%d", &Q);
		while(Q--){
			scanf("%d", &q);
			if(N == 0 || q > N || dist[q] < 3 || dist[q] == maxll) printf("?\n");
			else printf("%lld\n", dist[q]);
		}
	}
	return 0;
}