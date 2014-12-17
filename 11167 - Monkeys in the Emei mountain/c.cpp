#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

#define NMAX 50155
int INF = (int) 1e9;

int N, M;
int S, T;
vector<vector<pair<int,pair<int,int> > > >adj;
vector<pair<int,int> > edges;
vector<pair<int,int> > node;
vector<pair<int,int> > st;
int mark[NMAX];
int idx[NMAX];
int par[NMAX];
int rel[NMAX];
int required;
int cnt;

int augment_path(int v, int mf){
	if(v == S){
		//printf("%d ", v);
		return mf;
	}
	int u = par[v];
	int k = rel[v];
	int m = adj[u][k].second.first;
	int n = adj[u][k].second.second;
	bool back_edge = false;
	if(edges[m].first == 0) back_edge = true;
	if(back_edge){
		mf = min(mf, edges[n].second);
	} else {
		mf = min(mf, edges[m].first - edges[m].second);
	}
	mf = augment_path(u, mf);
	//printf("%d ", v);
	if(back_edge){
		edges[n].second -= mf;
	} else {
		edges[m].second += mf;
	}
	return mf;
}

bool edmond_karps(){
	int maxflow = 0;
	while(1){
		bool can_augment = false;
		for(int i=0;i<cnt;++i) par[i] = -1;
		par[T] = -1;
		queue<int> q;
		q.push(S);
		par[S] = S;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int i=0;i<adj[u].size();++i){
				int v = adj[u][i].first;
				int m = adj[u][i].second.first;
				int n = adj[u][i].second.second;
				if(par[v] != -1) continue;
				if(edges[m].first - edges[m].second > 0 ||
				   edges[n].second > 0) {
					par[v] = u;
					rel[v] = i;
					if(v == T) {
						can_augment = true;
						break;
					} else {
						q.push(v);
					}
				}
			}
			if(can_augment) break;
		}
		if(can_augment){
			maxflow += augment_path(T, INF);
			//printf("\n");
			if(maxflow == required) break;
		} else {
			break;
		}
	}
	return (maxflow == required);
}

void add_edge(int u, int v, int cap){
	adj[u].push_back(make_pair(v, make_pair(edges.size(), edges.size()+1)));
	adj[v].push_back(make_pair(u, make_pair(edges.size()+1, edges.size())));
	edges.push_back(make_pair(cap, 0));
	edges.push_back(make_pair(0, 0));
}


int main(){
	int tc = 1;
	while(scanf("%d", &N), N!=0){
		scanf("%d", &M);
		int v, s, t;
		node = vector<pair<int,int> > (NMAX);
		adj = vector<vector<pair<int, pair<int,int> > > > (NMAX);
		edges.clear();
		st.clear();
		S = NMAX-2;
		T = NMAX-1;
		required = 0;
		for(int i=0;i<=50000;++i) mark[i] = 0;
		for(int i=0;i<N;++i){
			scanf("%d %d %d", &v, &s, &t);
			add_edge(S, i, v);
			st.push_back(make_pair(s,t));
			required += v;
			mark[s] = 1;
			mark[t] = 1;
		}
		cnt = N;
		int prev = -1;
		for(int j=0;j<=50000;++j){
			if(mark[j]){
				if(prev == -1) {
					prev = j;
				} else {
					node[cnt] = make_pair(prev,j);
					idx[prev] = cnt;
					add_edge(cnt, T, (j - prev)*M);
					prev = j;
					++cnt;
				}
			}
		}
		for(int i=0;i<N;++i){
			for(int j=st[i].first;j<st[i].second;++j){
				if(mark[j]){
					add_edge(i, idx[j], node[idx[j]].second - node[idx[j]].first);
					//printf("%d, [%d,%d], %d\n", j, node[idx[j]].first, node[idx[j]].second, node[idx[j]].second - node[idx[j]].first);
				}
			}
		}
		/*
		for(int i=0;i<=adj.size();++i){
			if(adj[i].empty()) continue;
			printf("%d:", i);
			for(int j=0;j<adj[i].size();++j){
				printf(" %d", adj[i][j].first);
			}
			printf("\n");
		}
		*/
		if(edmond_karps()){
			printf("Case %d: Yes\n", tc++);
			int tracker[50005];
			memset(tracker, 0, sizeof tracker);
			for(int i=0;i<N;++i){
				vector<pair<int,int> > itv;
				for(int j=0;j<adj[i].size();++j){
					if(adj[i][j].first == T || adj[i][j].first == S) continue;
					int v = adj[i][j].first;
					int m = adj[i][j].second.first;
					//printf("%d --> %d [%d,%d]\n",i, edges[m].second, node[v].first, node[v].second);
					if(edges[m].first > 0 && edges[m].second > 0) {
						int prev = -1;
						int counter = 0;
						for(int k = node[v].first; k < node[v].second; ++k){
							if(tracker[k] < M){
								if(prev == -1) {
									prev = k;
								}
								++tracker[k];
								++counter;
								if(counter == edges[m].second){
									if(!itv.empty() && itv.back().second == prev) {
										itv.back().second = k+1;
									} else {
										itv.push_back(make_pair(prev,k+1));
									}
									break;
								}
							} else {
								if(prev != -1) {
									if(!itv.empty() && itv.back().second == prev) {
										itv.back().second = k;
									} else {
										itv.push_back(make_pair(prev,k));
									}
									prev = -1;
								}
							}
						}
					}
				}
				printf("%d", (int) itv.size());
				for(int j=0;j<itv.size();++j){
					printf(" (%d,%d)", itv[j].first, itv[j].second);
				}
				printf("\n");
			}
		} else {
			printf("Case %d: No\n", tc++);
		}
	}
	return 0;
}