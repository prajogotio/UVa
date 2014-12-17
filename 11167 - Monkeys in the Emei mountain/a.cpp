#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
using namespace std;

/* TLE */

map<pair<int,int>, pair<int,int> > g;
typedef map<pair<int,int>,pair<int,int> >::iterator edge;
vector<vector<int> > adj;
#define NMAX 50150
int vis[NMAX];
int par[NMAX];
int S, T, N, M;
int INF = (int) 1e9;
int required;
vector<vector<int> > itv;

void build(){
	for(int u=0;u<N;++u){
		for(int i=0;i<adj[u].size();++i){
			int v = adj[u][i];
			if(v == S || v == T) continue;
			edge e = g.find(make_pair(u,v));
			if((e -> second . first) > 0 && (e -> second . second) > 0) {
				itv[u].push_back(v);
			}
		}
	}
}

int augment_path(int v, int mf) {
	if(v == S){
		return mf;
	}
	int back_edge = 0;
	int u = par[v];
	edge e = g.find(make_pair(u,v));
	edge _e = g.find(make_pair(v,u));
	if(e -> second . first == 0) back_edge = 1;
	if(back_edge){
		mf = min(mf, _e -> second . second);
	} else {
		mf = min(mf, e -> second . first - e -> second . second);
	}
	mf = augment_path(u, mf);
	if(back_edge) {
		_e -> second . second -= mf;
	} else {
		e -> second . second += mf;
	}
	return mf;
}


bool edmonds_karp(){
	int maxflow = 0;
	while(1){
		bool augmented = false;
		for(int i=0;i<NMAX;++i){
			vis[i] = 0;
			par[i] = -1;
		}
		queue<int> q;
		q.push(S);
		par[S] = S;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int i=0;i<adj[u].size();++i){
				int v = adj[u][i];
				if(par[v] != -1) continue;
				edge e = g.find(make_pair(u,v));
				edge _e = g.find(make_pair(v,u));
				if(e -> second . first - e -> second . second > 0 ||
				  _e -> second . second > 0 ) {
					par[v] = u;
					if(v == T) {
						augmented = true;
						break;
					} else {
						q.push(v);
					}
				}
			}
			if(augmented) break;
		}
		if (augmented) {
			maxflow += augment_path(T, INF);
			if(maxflow == required) break;
		} else {
			break;
		}
	}
	return (maxflow == required);
}

void add_edge(int u, int v, int cap) {
	adj[u].push_back(v);
	adj[v].push_back(u);
	g[make_pair(u,v)] = make_pair(cap, 0);
	g[make_pair(v,u)] = make_pair(0, 0);
}

void solve() {
	int tc = 1;
	int v, s, t;
	while(scanf("%d", &N), N!= 0){
		scanf("%d", &M);
		S = N+50004;
		T = N+50005;
		adj = vector<vector<int> > (N+50005+1);
		g.clear();
		required = 0;
		for(int i=0;i<N;++i){
			scanf("%d %d %d", &v, &s, &t);
			required += v;
			add_edge(S, i, v);
			for(int j=s;j<t;++j){
				add_edge(i, j+N, 1);
				add_edge(j+N, T, M);
			}
		}

		bool exist = edmonds_karp();
		if(exist){
			printf("Case %d: Yes\n", tc++);
			for(int i=0;i<NMAX;++i) {
				par[i] = -1;
				vis[i] = 0;
			}
			itv = vector<vector<int> > (N+50005+1);
			build();
			/*
			for(int i=0;i<N+50005+1;++i){
				if(itv[i].empty()) continue;
				printf("%d: ", i);
				for(int j=0;j<itv[i].size();++j){
					printf("%d ", itv[i][j]);
				}
				printf("\n");
			}
			*/
			for(int i=0;i<N;++i){
				vector<pair<int,int> > st;
				//printf("before access %d %d\n", i,(int)itv[i].size());
				if(itv[i].empty()) continue;
				int prev = itv[i][0];
				for(int j=1;j<itv[i].size();++j){
					if(itv[i][j] != itv[i][j-1] + 1) {
						st.push_back(make_pair(prev, itv[i][j-1]+1));
						prev = itv[i][j];
					}
				}
				st.push_back(make_pair(prev, itv[i].back()+1));
				printf("%d", (int)st.size());
				for(int i=0;i<st.size();++i){
					printf(" (%d,%d)", st[i].first - N, st[i].second - N);
				}
				printf("\n");
			}
		} else {
			printf("Case %d: No\n", tc++);
		}
	}
}

int main(){
	solve();
	return 0;
}