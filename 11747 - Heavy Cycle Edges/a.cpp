#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

priority_queue<pair<int, pair<int,int> > > pq;
vector<int> st;
int par[1005], rank[1004];
int N, M;

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
		if(rank[x] == rank[y]) ++rank[y];
	}
}

void kruskal(){
	while(!pq.empty()){
		int w = -pq.top().first;
		int u = pq.top().second.first, v = pq.top().second.second;
		pq.pop();
		if(sameset(u, v)) {
			st.push_back(w);
			continue;
		}
		unionset(u,v);
	}
}

int main(){
	while(scanf("%d %d", &N, &M), N+M!=0){
		st.clear();
		pq = priority_queue<pair<int, pair<int,int> > >();
		initset(N);
		int u,v,w;
		for(int i=0;i<M;++i){
			scanf("%d %d %d", &u, &v, &w);
			pq.push(make_pair(-w, make_pair(u,v)));
		}
		kruskal();
		if(st.empty()) {
			printf("forest\n");
			continue;
		}
		for(int i=0;i<st.size();++i){
			if(i != 0) printf(" ");
			printf("%d", st[i]);
		}
		printf("\n");
	}
	return 0;
}
