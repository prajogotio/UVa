#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int adj[3002][3002];
vector<pair<int,int> > edge;
int N, M;

int main(){
	int TC;
	int u,v;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &N, &M);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				adj[i][j] = 0;

		edge.clear();
		for(int i=0;i<M;++i){
			scanf("%d %d", &u, &v);
			adj[u][v] = 1;
			adj[v][u] = 1;
			if(u > v) swap(u,v);
			edge.push_back(make_pair(u,v));
		}
		sort(edge.begin(), edge.end());
		int tot = 0, ctr = 0;
		for(int i=0;i<M;++i){
			u = edge[i].first; v = edge[i].second;
			ctr = 0;
			for(int j=v+1;j<=N;++j){
				if(adj[v][j] && adj[j][u]){
					++tot;
					++ctr;
				}
				if(ctr == 2) break;
			}
		}
		printf("%d\n", tot);

	}
	return 0;
}