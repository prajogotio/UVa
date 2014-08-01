#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

vector<vector<pair<int, int> > > adj;
int dist[20003];
int N, M, S, T;


void djikstra(int s, int t){
	for(int i=0;i<=N;++i){
		dist[i] = 2000000000;
	}
	dist[s] = 0;
	priority_queue<pair<int,int> > pq;
	pq.push(make_pair(0, s));
	while(!pq.empty()){
		int d = -pq.top().first;
		int u = pq.top().second;
		pq.pop();
		//printf("%d %d\n", u, d);
		if(u == t) return;
		if(d > dist[u]) continue;
		for(int i=0;i<adj[u].size();++i){
			int v = adj[u][i].first;
			int w = adj[u][i].second;
			if(dist[v] > d + w){
				dist[v] = d + w;
				pq.push(make_pair(-dist[v], v));
			}
		}
	}
}

int main(){
	int TC, Tc=1;
	scanf("%d", &TC);
	while(TC--){
		printf("Case #%d: ", Tc++);
		scanf("%d %d %d %d", &N, &M, &S, &T);
		adj = vector<vector<pair<int,int> > > (N+3);
		for(int i=0;i<M;++i){
			int u,v,w;
			scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(make_pair(v,w));
			adj[v].push_back(make_pair(u,w));
		}
		djikstra(S, T);
		if(dist[T] == 2000000000) printf("unreachable\n");
		else printf("%d\n", dist[T]);
	}
	return 0;
}