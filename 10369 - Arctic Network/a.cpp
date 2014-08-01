#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

int x[503], y[503];
priority_queue<pair<double, pair<int, int> > >dist;
vector<double> ans;
int par[503], rank[503];
int N,S;

void initset(int N){
	for(int i=0;i<N;++i){
		par[i] = i;
		rank[i] = 0;
	}
}

int findset(int i){ return (par[i] == i) ? i : (par[i] = findset(par[i])); }
bool sameset(int i, int j) { return findset(i) == findset(j); }
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

void prep(){
	dist = priority_queue<pair<double, pair<int, int> > >();
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			double tmp = sqrt(dx*dx + dy*dy);
			dist.push(make_pair(-tmp, make_pair(i,j)));
		}
	}
}

void kruskal(){
	while(!dist.empty()){
		double tmp = -dist.top().first;
		int u = dist.top().second.first, v = dist.top().second.second;
		dist.pop();
		if(sameset(u,v)) continue;
		unionset(u,v);
		ans.push_back(tmp);
	}
}

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &S, &N);
		ans.clear();
		initset(N);
		for(int i=0;i<N;++i){
			scanf("%d %d", &x[i], &y[i]);
		}
		prep();
		kruskal();
		printf("%.2lf\n", ans[N-1 - S]);
	}
	return 0;
}