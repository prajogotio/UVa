#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int par[103], rank[103];
vector<pair<int, pair<int, int> > > adj;
int mark[10000];
vector<int> mst, mst2;
int N, M, dset;

void initset(int N){
	for(int i=0;i<=N;++i){
		par[i] = i;
		rank[i] = 0;
	}
}

int findset(int i){ return (par[i] == i) ? i : (par[i] = findset(par[i])); }
bool sameset(int i, int j){ return findset(i) == findset(j); }
void unionset(int i, int j){
	int x = findset(i), y = findset(j);
	if(x == y) return;
	if(rank[x] > rank[y]){
		par[y] = x;
	} else {
		par[x] = y;
		if(rank[x] == rank[y]) ++ rank[y];
	}
}


int kruskal(bool imp){
	int ret = 0;
	for(int i=0;i<M;++i){
		if(mark[i]) continue;
		int temp = adj[i].first;
		int u = adj[i].second.first, v = adj[i].second.second;
		if(sameset(u,v)) continue;
		ret += temp;
		if(imp) mst.push_back(i);
		else mst2.push_back(i);
		unionset(u,v);
	}
	return ret;
}

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &N, &M);
		initset(N);
		dset = 0;
		adj = vector<pair<int, pair<int,int> > > ();
		for(int i=0;i<M;++i){
			int u,v,w;
			scanf("%d %d %d", &u, &v, &w);
			adj.push_back(make_pair(w, make_pair(u,v)));
		}
		sort(adj.begin(), adj.end());
		mst.clear();
		for(int i=0;i<M;++i){
			mark[i] = 0;
		}
		int ans = kruskal(true);
		int ans2 = 2000000000;
		int check = mst.size();
		for(int i=0;i<mst.size();++i){
			mst2.clear();
			mark[mst[i]] = 1;
			initset(N);
			int temp = kruskal(false);
			//printf("%d %d\n", mst.size(), mst2.size());
			//if(mst2.size() == mst.size()) {
			if(mst2.size() == check){
				ans2 = min(ans2, temp );
			}
			mark[mst[i]] = 0;
		}
		printf("%d %d\n", ans, ans2);
	}
	return 0;
}
