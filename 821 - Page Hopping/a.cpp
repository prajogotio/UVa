#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int maxint = (int) 1e8;
int got[103];
int dist[103][103];
double ans;

void floyd(){
	for(int k=1;k<=100;++k)
		for(int i=1;i<=100;++i)
			for(int j=1;j<=100;++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

void solve(){
	ans = 0;
	int temp = 0;
	int N = 0;
	for(int i=1;i<=100;++i){
		if(!got[i]) continue;
		++N;
		for(int j=1;j<=100;++j){
			if(!got[j]) continue;
			temp += dist[i][j];
		}
	}
	N = (N*(N-1));
	ans = ((double) temp) / ((double) N);
}

int main(){
	int u,v, T=1;
	while(scanf("%d %d", &u, &v), u+v!=0){
		for(int i=1;i<=100;++i)
			for(int j=1;j<=100;++j)
				dist[i][j] = maxint;
		for(int i=1;i<=100;++i){
			got[i] = 0;
			dist[i][i] = 0;
		}
		dist[u][v] = 1;
		got[u] = 1; got[v] = 1;
		while(scanf("%d %d", &u,&v), u+v!=0){
			dist[u][v] = 1;
			got[u] = 1; got[v] = 1;
		}
		//for(int i=1;i<=100;++i) printf("%d ", got[i]); printf("\n");
		floyd();
		solve();
		printf("Case %d: average length between pages = %.3lf clicks\n", T++, ans);
	}
	return 0;
}
