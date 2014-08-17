#include <iostream>
#include <cstdio>
using namespace std;

char m[103][103];
int M, N, Q;

bool check(int i, int j, int k){
	//printf("%d %d %d\n", i, j, k);
	char a = m[i][j];
	if(i-k < 0 || i+k >= M || j-k < 0 || j+k >= N) return false;	
	for(int y=j-k; y <= j+k; ++y){
		if(m[i-k][y] != a || m[i+k][y] != a) return false;
	}
	for(int x=i-k; x<= i+k;++x){
		if(m[x][j-k] != a || m[x][j+k] != a) return false;
	}
	return true;
}

int main(){
	int TC;
	int a,b;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d %d", &M, &N, &Q);
		printf("%d %d %d\n", M, N, Q);
		for(int i=0;i<M;++i){
			for(int j=0;j<N;++j){
				scanf(" %c", &m[i][j]);
			}
		}
		for(int i=0;i<Q;++i){
			scanf("%d %d", &a, &b);
			int ans = 0;
			while(check(a,b,ans)) ++ans; 
			printf("%d\n", 2*(ans-1)+1);
		}
	}
	return 0;
}