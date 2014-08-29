#include <iostream>
#include <cstdio>
using namespace std;

int vis[15];
int par[15];
int adj[15][15];
int N, D;
bool nopath;

void printpath(int u){
	if(par[u] == -1){
		printf("(%d", u);
		return;
	}
	printpath(par[u]);
	printf(",%d", u);
}

void dfs(int u, int len){
	if(len == D){
		nopath = false;
		printpath(u);
		printf(")\n");
		return;
	}
	for(int i=1;i<=N;++i){
		if(adj[u][i] && !vis[i]){
			vis[i] = 1;
			par[i] = u;
			dfs(i, len+1);
			vis[i] = 0;
			par[i] = -1;
		}
	}
}

int main(){
	bool flag = false;
	for(int i=0;i<15;++i){
		par[i] = -1;
		vis[i] = 0;
	}
	vis[1] = 1;
	while(scanf("%d %d", &N, &D) != EOF){
		if(flag) printf("\n");
		nopath = true;
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				scanf("%d", &adj[i][j]);
			}
		}
		dfs(1, 0);
		if(nopath) printf("no walk of length %d\n", D);
		scanf("%d",&N);
		flag = true;
	}
	return 0;
}