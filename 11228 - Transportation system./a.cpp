#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

vector<pair<int,int> > pts;
vector<pair<double,pair<int,int> > > len;
int par[1003], rank[1003];
int N, R, state;
double road, rail;

void initset(int N){ 
	for(int i=0;i<=N;++i){
		par[i] = i;
		rank[i] = 0;
	}
}
int findset(int i){ return (par[i] == i) ? i : (par[i] = findset(par[i])); }
bool sameset(int i, int j) { return findset(i) == findset(j); }
void unionset(int i, int j) {
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
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			int dx = pts[i].first - pts[j].first;
			int dy = pts[i].second - pts[j].second;
			double dist = sqrt(dx*dx + dy*dy);
			len.push_back(make_pair(dist, make_pair(i,j)));
		}
	}
	sort(len.begin(), len.end());
}

void kruskal(){
	int sz = len.size();
	for(int i=0;i<sz;++i){
		double dist = len[i].first;
		int u = len[i].second.first, v = len[i].second.second;
		if(sameset(u,v)) continue;
		unionset(u,v);
		if( ceil(dist) <= R) road += dist;
		else {
			rail += dist;
			++state;
		}
	}
}

int roundit(double x){
	int ret = (int) x;
	if(x - ret >= 0.5) ++ret;
	return ret;
}

int main(){
	int TC, T=1;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &N, &R);
		pts.clear();
		len.clear();
		road = rail = state = 0;
		for(int i=0;i<N;++i){
			int x,y;
			scanf("%d %d", &x, &y);
			pts.push_back(make_pair(x,y));
		}
		initset(N);
		prep();
		kruskal();
		printf("Case #%d: %d %d %d\n", T++, state+1, roundit(road), roundit(rail));
	}
	return 0;
}
