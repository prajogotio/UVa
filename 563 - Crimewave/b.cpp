#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

struct edge {
	int u;
	int v;
	int cap;
	int flow;
	edge(int u, int v, int cap, int flow) {
		this -> u = u;
		this -> v = v;
		this -> cap = cap;
		this -> flow = flow;
	}
};

int INF = 1234567;
vector<vector<pair<int,int> > > adj;
vector<edge> edges;
int vis[6000];
int par[6000];
int M, N, B;
int S, T;
int maxflow;


int augment_path(int v, int mf) {
	if(v == S) {
		return mf;
	}
	edge &e = edges[par[v]];
	int u;
	bool isBackEdge = (e.v != v);
	if(isBackEdge) {
		u = e.v;
		mf = min(e.flow, mf);
	} else {
		u = e.u;
		mf = min(e.cap - e.flow, mf);
	}

	mf = augment_path(u, mf);
	if(isBackEdge) {
		e.flow -= mf;
	} else {
		e.flow += mf;
	}
	return mf;
}

void edmondskarp() {
	while(1) {
		bool augmented = false;
		queue<int> q;
		q.push(S);
		for(int i=0;i<adj.size();++i){
			vis[i] = 0;
		}
		vis[S] = 1;
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(int i=0;i<adj[u].size();++i){
				int v = adj[u][i].first;
				edge e = edges[adj[u][i].second];
				if(vis[v])continue;
				bool added = false;
				if(e.u == u && e.v == v) {
					if(e.cap - e.flow > 0) {
						vis[v] = 1;
						q.push(v);
						par[v] = adj[u][i].second;
						added = true;
					}
				} else {
					if(e.flow > 0) {
						vis[v] = 1;
						q.push(v);
						par[v] = adj[u][i].second;
						added = true;
					}
				}
				if(added) {
					if(v == T) {
						augmented = true;
						maxflow += augment_path(T, INF);
						break;
					}
				}
			}
			if(augmented) break;
		}
		if(!augmented) break;
	}
}


int getIndexIn(int x, int y) {
	return (x-1) * N + (y-1);
}

int getIndexOut(int x, int y) {
	return getIndexIn(x,y) + M*N;
}

void makeEdge(int u, int v) {
	edges.push_back(edge(u, v, 1, 0));
	adj[u].push_back(make_pair(v, edges.size()-1));
}

int main(){
	int tc;
	scanf("%d",&tc);
	int x, y;
	while(tc--){
		edges.clear();
		adj.clear();
		scanf("%d%d%d",&M,&N,&B);
		adj = vector<vector<pair<int,int> > >(2*M*N+10);
		S = 2*M*N;
		T = 2*M*N+1;
		for(int i=1;i<=M;++i){
			for(int j=1;j<=N;++j){
				makeEdge(getIndexIn(i,j), getIndexOut(i,j));
				if(i-1>0) {
					makeEdge(getIndexOut(i,j), getIndexIn(i-1,j));
				}
				if(j-1>0) {
					makeEdge(getIndexOut(i,j), getIndexIn(i, j-1));
				}
				if(i+1 <= M) {
					makeEdge(getIndexOut(i,j), getIndexIn(i+1, j));
				}
				if(j+1 <= N) {
					makeEdge(getIndexOut(i,j), getIndexIn(i, j+1));
				}
				if(i-1 == 0 || j-1 == 0 || i+1 >M || j+1 > N) {
					makeEdge(getIndexOut(i,j), T);
				}
			}
		}
		bool ok = true;
		for(int i=0;i<B;++i){
			scanf("%d%d",&x,&y);
			makeEdge(S, getIndexIn(x,y));
		}
		if(!ok)continue;
		maxflow = 0;
		edmondskarp();
		//cout << maxflow << endl;
		if(maxflow == B) printf("possible\n");
		else printf("not possible\n");
	}
	return 0;
}