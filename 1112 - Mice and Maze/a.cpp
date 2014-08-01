#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
ll maxll = (ll) 2e13;

ll vis[103][103];
int N, E, T, M;

void floyd(){
	for(int k=1;k<=N;++k){
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				vis[i][j] = min(vis[i][j], vis[i][k] + vis[k][j]);
			}
		}
	}
}

int main(){
	int TC;
	bool flag = false;
	scanf("%d", &TC);
	while(TC--){
		if(flag) printf("\n");
		scanf(" %d %d %d", &N, &E, &T);
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				vis[i][j] = maxll;
		for(int i=1;i<=N; ++i) vis[i][i] = 0;
		scanf("%d", &M);
		for(int i=0;i<M;++i){
			int u,v;
			ll w;
			scanf("%d %d %lld", &u, &v, &w);
			vis[u][v] = w;
		}
		floyd();
		int ans = 0;
		for(int i=1;i<=N;++i){
			if(vis[i][E] <= T) ++ans;
		}
		printf("%d\n", ans);
		flag = true;
	}
	return 0;
}