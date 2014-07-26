#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string ship[105];
int vis[105][105];
int alive[10002];
int N, ff;

void dfs(int i, int j){
	if(i < 0 || j < 0 || i >=N || j >= N || vis[i][j] != -1) return;
	if(ship[i][j] == '.') return;
	vis[i][j] = ff;
	if(ship[i][j] == 'x'){
		alive[ff] = 1;
	}
	dfs(i+1, j);
	dfs(i-1, j);
	dfs(i, j+1);
	dfs(i, j-1);
}

int main(){
	int TC, T=1;
	scanf("%d",&TC);
	while(TC--){
		printf("Case %d: ", T++);
		scanf("%d",&N);
		ff = 0;
		for(int i=0;i<N;++i){
			cin >> ship[i];
		}
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j){
				vis[i][j] = -1;
			}
		for(int i=0;i<10002;++i)
			alive[i] = 0;

		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j){
				if(vis[i][j] == -1 && ship[i][j] != '.'){
					++ff;
					dfs(i, j);
				}
			}
		int ans = 0;
		for(int i=1;i<=ff;++i){
			if(alive[i] == 1) ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}