#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int maxint = (int) 1e9;
int young[29][29];
int old[29][29];
int ans[29];
int u,v;
int tot, N;
void floyd(){
	for(int k=0;k<26;++k)
		for(int i=0;i<26;++i)
			for(int j=0;j<26;++j){
				young[i][j] = min(young[i][j], young[i][k]+young[k][j]);
				old[i][j] = min(old[i][j], old[i][k]+old[k][j]);
			}
}

void solve(){
	tot = maxint;
	N = 0;
	for(int i=0;i<26;++i){
		if(young[u][i] == maxint || old[v][i] == maxint) continue;
		tot = min(tot, young[u][i] + old[v][i]);
	}
	if(tot == maxint) return;
	for(int i=0;i<26;++i){
		int temp = young[u][i] + old[v][i];
		if(temp == tot){
			ans[N] = i;
			++N;
		}
	}
}

int main(){
	int M;
	while(scanf("%d", &M), M!=0){
		for(int i=0;i<26;++i)
			for(int j=0;j<26;++j){
				young[i][j] = maxint;
				old[i][j] = maxint;
			}
		for(int i=0;i<26;++i){
			young[i][i] = 0;
			old[i][i] = 0;
		}
		for(int i=0;i<M;++i){
			char a,b,c,d;
			int dist;
			scanf(" %c %c %c %c %d", &a,&b,&c,&d,&dist);
			int x = c-'A';
			int y = d-'A';
			if(a == 'Y'){
				young[x][y] = min(young[x][y], dist);
				if(b=='B'){
					young[y][x] = min(young[y][x], dist);
				}
			} else {
				old[x][y] = min(old[x][y], dist);
				if(b=='B'){
					old[y][x] = min(old[y][x], dist);
				}
			}
		}
		char s, t;
		scanf(" %c %c", &s, &t);
		u = s-'A';
		v = t-'A';
		floyd();
		solve();
		if(N == 0) printf("You will never meet.\n");
		else {
			printf("%d", tot);
			for(int i=0;i<N;++i){
				printf(" %c", 'A'+ans[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
