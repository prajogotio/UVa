#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

typedef long long ll;
ll maxll = (ll) 1e18;
vector<vector<pair<int,ll> > > sadj;
vector<vector<pair<int,ll> > > tadj;
ll sdist[10004], tdist[10004];
vector<pair<pair<int,int>, ll> >  edge;
int N, M;
int S, T;
ll ans, P;

void dijkstra(int s, ll dist[], vector<vector<pair<int,ll> > > &adj){
	for(int i=0;i<=N;++i) dist[i] = maxll;
	dist[s] = 0;
	priority_queue<pair<ll,int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
	pq.push(make_pair(0, s));
	while(!pq.empty()){
		ll d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		//printf("%d %lld\n", u, d);
		if(dist[u] < d) continue;
		for(int i=0;i<adj[u].size();++i){
			int v = adj[u][i].first;
			ll w = adj[u][i].second;
			if(dist[v] > w + d){
				dist[v] = w+d;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}

void backtrack(){
	dijkstra(S, sdist, sadj);
	dijkstra(T, tdist, tadj);
	ans = -1;
	for(int i=0;i<M;++i){
		int u = edge[i].first.first;
		int v = edge[i].first.second;
		ll w = edge[i].second;
		//printf("u: %d v:%d w:%lld %d-%d: %lld %d-%d: %lld\n", u, v, w, S, u, sdist[u], v, T,tdist[v]);
		if(sdist[u] + w + tdist[v] <= P){
			ans = max(ans, w);
		}
	}
}

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d %d %d %lld", &N, &M, &S, &T, &P);
		sadj = vector<vector<pair<int,ll> > > (N+3);
		tadj = vector<vector<pair<int,ll> > > (N+3);
		edge.clear();
		for(int i=0;i<M;++i){
			int u,v;
			ll w;
			scanf("%d %d %lld", &u, &v, &w);
			edge.push_back(make_pair(make_pair(u,v), w));
			sadj[u].push_back(make_pair(v,w));
			tadj[v].push_back(make_pair(u,w));
		}
		backtrack();
		printf("%lld\n", ans);
	}
	return 0;
}