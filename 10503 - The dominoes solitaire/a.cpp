//backtrack on dominoes
#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
pair<int,int> dom[20];
pair<int,int> beg;
pair<int,int> end;
int M,N;
bool possible = false;
void dfs(int rem, int way, int prev){
	if(possible) return;
	if(rem == 0){
		if(prev == end.first){
			possible = true;
		}
		return;
	}
	for(int i=0;i<M;++i){
		if(way & (1<<i))continue;
		if(prev == dom[i].first){
			dfs(rem-1, way|(1<<i), dom[i].second);
		} else if(prev == dom[i].second){
			dfs(rem-1, way|(1<<i), dom[i].first);
		}
	}
}

int main(){
	while(scanf("%d",&N), N!=0){
		scanf("%d",&M);
		possible = false;
		scanf("%d %d", &(beg.first), &(beg.second));
		scanf("%d %d", &(end.first), &(end.second));
		for(int i=0;i<M;++i){
			scanf("%d %d", &(dom[i].first), &(dom[i].second));
		}
		dfs(N, 0, beg.second);
		if(possible) printf("YES");
		else printf("NO");
		printf("\n");
	}
	return 0;
}