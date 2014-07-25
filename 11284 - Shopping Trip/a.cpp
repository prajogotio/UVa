#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
double maxd = 1e20;
double dist[53][53];
double s[14];
int si[14];
double dp[13][4097];
int N,M,P;

void fw(){
	for(int i=0;i<N;++i) dist[i][i] = 0;
	for(int k=0;k<N;++k){
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
	} } }
}

double cost(int pos, int mask){
//	printf("%d %d\n", pos, mask);
	if(mask == (1<<P) - 1) {
		return -dist[si[pos]][0];
	}
	if(dp[pos][mask] > -3*maxd) return dp[pos][mask];
	double temp = maxd;
	for(int i=0;i<P;++i){
		if(mask & (1<<i)) continue;
		//printf("%lf %lf \n", s[i], dist[si[pos]][si[i]]);
		temp = max( s[i] - dist[si[pos]][si[i]] + cost(i, mask|(1<<i)) , cost(pos, mask|(1<<i)));
	}
	//printf("%lf %d\n", temp, si[pos]);
	dp[pos][mask] = temp;
	return temp;
}

int main(){
	int Tc;
	scanf("%d", &Tc);
	while(Tc--){
		scanf("%d %d", &N, &M);
		++N;
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				dist[i][j] = maxd;
		for(int i=0;i<13;++i)
			for(int j=0;j<4097;++j)
				dp[i][j] = -3*maxd;
		for(int i=0;i<M;++i){
			int u, v;
			double c;
			scanf("%d %d %lf",&u,&v,&c);
			dist[u][v] = min(c, dist[u][v]);
			dist[v][u] = min(c, dist[v][u]);
		}
		fw();
		scanf("%d",&P);
		/*
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j)
				printf(" %lf", dist[i][j]);
			printf("\n");
		}
		*/
		
		for(int i=0;i<P;++i){
			int a;
			double b;
			scanf("%d %lf", &a, &b);
			s[i] = b;
			si[i] = a;
		}
		double ans = -maxd;
		for(int i=0;i<P;++i){
			ans = max(ans, s[i] - dist[0][si[i]] + cost(i, (1<<i)));
		}
		if(ans > 0) printf("Daniel can save $%.2lf\n", ans);
		else printf("Don't leave the house\n");

	}
	return 0;

}