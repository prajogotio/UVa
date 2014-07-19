#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
//ONLY BLACK CANNOT BE ADJACENT, WHITE CAN!
//WRONG
int N,M;
vector<vector<int> > adj;
int vis[105];
int color[105];
int invert[105];
pair<int,int> comp[105];
int ff;

void dfs(int u, int col){
	printf("%d %d\n", u, col);
	vis[u] = ff;
	color[u] = col;
	for(int i=0;i<adj[u].size();++i){
		int v = adj[u][i];
		if(!vis[v]){
			dfs(v, (col+1)%2);
		}
	}
}

int main(){
	int TC;
	scanf("%d",&TC);
	while(TC--){
		scanf("%d %d",&N, &M);
		for(int i=1;i<=N;++i)vis[i] = 0;
		adj.assign(N+1, vector<int>());

		for(int i=0;i<M;++i){
			int u,v;
			scanf("%d %d",&u,&v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		ff = 0;
		for(int i=1;i<=N;++i){
			if(!vis[i]){
				++ff;
				dfs(i, 0);
			}
		}
		for(int i=1;i<=ff;++i){
			comp[i].first = 0;
			comp[i].second = 0;
		}

		for(int i=1;i<=N;++i){
			++(comp[vis[i]].second);
			if(color[i] == 1) ++(comp[vis[i]].first);
		}
		int tot = 0;
		for(int i=1;i<=ff;++i){
			int A = comp[i].first;
			int B = comp[i].second;
			if(A >= (B-A)){
				invert[i] = 0;
				tot+=A;
			} else {
				invert[i] = 1;
				tot+= (B-A);
			}
		}
		printf("%d\n", tot);
		bool flag = false;
		for(int i=1;i<=N;++i){
			int col = color[i];
			if(invert[vis[i]]) col = (col + 1)%2;
			if(col){
				if(flag) printf(" ");
				printf("%d", i);
				flag = true;
			}
		}
		printf("\n");
	}
	return 0;
}
