#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int maxi = (int) 1e9;
int dist[53][53];
int s[14];
int si[14];
int dp[13][1<<13];
int N,M,P;

void fw(){
	for(int i=0;i<N;++i) dist[i][i] = 0;
	for(int k=0;k<N;++k){
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
	} } }
}


int cost(int pos, int mask){
  //printf("%d %d\n", pos, mask);
	if(mask == ((1<<P) - 1)) {
		//printf("%d\n", dist[si[pos]][0]);
		return -dist[si[pos]][0];
	}
	if(dp[pos][mask] != -maxi-1) return dp[pos][mask];
	int ans = -maxi-1, temp = -1-maxi;
	for(int i=0;i<P;++i){
		if(mask & (1<<i)) continue;
		//printf("%d\n", s[i] - dist[si[pos]][si[i]]);
		temp = max( s[i] - dist[si[i]][si[pos]] + cost(i, mask|(1<<i)) , cost(pos, mask|(1<<i)));
		ans = max(ans, temp);
	}
	//printf("%d %d\n", temp, si[pos]);
	dp[pos][mask] = ans;
	return ans;
}

int main(){
	int Tc;
	scanf("%d", &Tc);
	while(Tc--){
		scanf("%d %d", &N, &M);
		++N;

		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				dist[i][j] = maxi;

		for(int i=0;i<13;++i)
			for(int j=0;j<(1<<13);++j)
				dp[i][j] = -maxi-1;

		for(int i=0;i<M;++i){
			int u, v;
			int c, d;
			scanf("%d %d %d.%d",&u,&v,&c,&d);
			dist[u][v] = min(100*c + d, dist[u][v]);
			dist[v][u] = min(100*c + d, dist[v][u]);
		}
		fw();

		scanf("%d",&P);
		/*
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j)
				printf(" %d", dist[i][j]);
			printf("\n");
		}
		*/
		
		for(int i=0;i<P;++i){
			int a;
			int b, c;
			scanf("%d %d.%d", &a, &b, &c);
			s[i] = 100*b + c;
			si[i] = a;
		}

		int ans = -maxi;
		for(int i=0;i<P;++i){
			//printf("%d\n", ans);
			ans = max(ans ,  s[i] - dist[0][si[i]] + cost(i, (1<<i) ));
		}
		if(ans > 0) printf("Daniel can save $%d.%02d\n", ans/100, ans%100);
		else printf("Don't leave the house\n");

	}
	return 0;

}