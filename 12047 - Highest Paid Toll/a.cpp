#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
int maxint = (int) 1e9;
vector<vector<pair<int,int> > > adj;
vector<pair<int, pair<int,int> > > edge;
ll dist[10004];
vector<int> mark;
int dest, end;
int N, M, P, S, T;
int ans;

ll dijkstra(int s, int t){
	priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll, int> > > pq;
	pq.push(make_pair(0, s));
	for(int i=0;i<=N;++i) dist[i] = maxint;
	dist[s] = 0;
	while(!pq.empty()){
		ll d = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if(u == t){
			return d;
		}
		if(d > dist[u]) continue;
		for(int i=0;i<adj[u].size();++i){
			int v = adj[u][i].first;
			ll w = adj[u][i].second;
			if(dist[v] > d+w){
				dist[v] = d+w;
				pq.push(make_pair(d+w, v));
			}
		}
	}
	return -1;
}

void backtrack(){
	ll left, right;
	int tmp;
	ans = -1;
	for(int i=M-1; i >= 0; --i){
		int w = edge[i].first;
		int u = edge[i].second.first;
		int v = edge[i].second.second;
		left = dijkstra(S, u);
		if(left == -1) continue;
		right = dijkstra(v, T);
		if(right == -1) continue;
		if(left+right+w > P) continue;
		ans = w; break;
	}
}

int main(){
	int tc, u, v, w;
	scanf("%d", &tc);
	while(tc--){
		scanf("%d %d %d %d %d", &N, &M, &S, &T, &P);
		edge.clear();
		adj = vector<vector<pair<int, int> > > (N+2);
		for(int i=0;i<M;++i){
			scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(make_pair(v, w));
			edge.push_back(make_pair(w, make_pair(u,v)));
		}
		sort(edge.begin(), edge.end());
		backtrack();
		printf("%d\n", ans);
	}
	return 0;
}