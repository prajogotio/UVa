#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int maxint = (int) 2e9;
int adj[103][103];
int N, S, Q;

void floyd(){
	for(int k=1;k<=N;++k){
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				adj[i][j] = min( max(adj[i][k], adj[k][j]), adj[i][j]);
			}
		}
	}
}

int main(){
	int T=1;
	bool flag = false;
	while(scanf("%d %d %d", &N, &S, &Q), N+S+Q!=0){
		if(flag) printf("\n");
		printf("Case #%d\n", T++);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				adj[i][j] = maxint;

		for(int i=0;i<S;++i){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			adj[u][v] = w;
			adj[v][u] = w;
		}

		floyd();

		for(int i=0;i<Q;++i){
			int u, v;
			scanf("%d %d", &u, &v);
			if(adj[u][v] == maxint) printf("no path\n");
			else printf("%d\n", adj[u][v]);
		}
		flag = true;
	}
	return 0;
}