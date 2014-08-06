//Send each soldiers to all building, and find the maximum time needed among all soldiers.
//you have to reach all building anyway
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int maxint = (int) 1e9;
int dist[103][103];
int deg[103];
int N;
int S, T;
int ans;


void floyd(){
	for(int k = 0; k<N;++k)
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

void solve(){
	ans = 0;
	for(int i=0;i<N;++i){
		//printf("%d %d\n", i, deg[i]);
		ans = max(dist[S][i] + dist[T][i], ans);
	}
}

int main(){
	int TC, R, tc=1;
	scanf("%d", &TC);
	while(TC--){
		printf("Case %d: ", tc++);
		scanf("%d", &N);
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j)
				dist[i][j] = maxint;
			dist[i][i] = 0;
			deg[i] = 0;
		}
		scanf("%d", &R);
		for(int i=0;i<R;++i){
			int u,v;
			scanf("%d %d", &u, &v);
			dist[u][v] = 1;
			dist[v][u] = 1;
			++deg[u];
			++deg[v];
		}
		scanf("%d %d", &S, &T);
		floyd();
		solve();
		printf("%d\n", ans);
	}
	return 0;
}