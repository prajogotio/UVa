#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

string m[23];
int M,N,X,Y;
int ff;
int sz[404];
int vis[23][23];
char landchar;

void dfs(int i,int j){
	if(i < 0 && i >= M) return;
	if(j < 0) j += N;
	if(j >= N) j -= N;
	if(vis[i][j] != -1 || m[i][j] != landchar) return;
	//printf("%d %d %d\n", i, j, ff);
	vis[i][j] = ff;
	++sz[ff];
	dfs(i-1,j);
	dfs(i+1,j);
	dfs(i,j-1);
	dfs(i,j+1);
}

int main(){
	while(scanf("%d %d", &M, &N) != EOF){
		for(int i=0;i<M;++i){
			cin>>m[i];
		}
		scanf("%d %d", &X, &Y);
		for(int i=0;i<M;++i)
			for(int j=0;j<N;++j){
				vis[i][j] = -1;
			}
		ff = 0;
		landchar = m[X][Y];
		for(int i=0;i<M;++i){
			for(int j=0;j<N;++j){
				if(vis[i][j] == -1 && m[i][j] == landchar){
					++ff;
					sz[ff] = 0;
					dfs(i,j);
				}
			}
		}
		int cc = vis[X][Y];
		int maxval = -1;
		for(int i=1;i<=ff;++i){
			if(i == cc) continue;
			maxval = max(maxval, sz[i]);
		}
		if(maxval == -1) maxval = 0;
		printf("%d\n", maxval);
	}
	return 0;
}