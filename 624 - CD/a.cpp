#include <iostream>
#include <cstdio>
using namespace std;

int track[25], N, T;
int choice, sum;

void dfs(int p, int idx, int val){
	printf("%d %d %d\n", p, idx, val);
	if(val > N) return;
	if(val > sum){
		sum = val;
		choice = p;
	}
	for(int i = idx; i < T; ++i){
		dfs((p | (1<<i)), i+1, val+track[i]);
	}
}

int main(){
	while(scanf("%d %d", &N, &T) != EOF){
		choice = 0, sum = 0;
		for(int i=0;i<T;++i){
			scanf("%d",&track[i]);
		}
		dfs(0,0,0);
		for(int i=0;i<T;++i){
			if(choice & (1<<i)){
				printf("%d ", track[i]);
			}
		}
		printf("sum:%d\n", sum);
	}
	return 0;
}