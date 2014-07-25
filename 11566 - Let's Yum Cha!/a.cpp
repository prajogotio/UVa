#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int intmax = (int) 1e9;
int N, x, T, K;
int dp[103][23][1005];
int p[105];
int f[105];

int ks(int i, int n, int S){
	int trail = S + (N+1)*T;
	trail = ceil((double) trail * 1.1L); // hmmmmm
	if(trail > (N+1)*x || n > 2*(N+1) ) return -intmax;
	if(trail == (N+1)*x || i < 0 || n == 2*(N+1)) return 0;
	if(dp[i][n][S] != -1) return dp[i][n][S];
	int temp = max( f[i] + ks(i-1, n+1, S + p[i]), max( 2*f[i] + ks(i-1, n+2, S+2*p[i]), ks(i-1,n,S)));
	dp[i][n][S] = temp;
	return temp;
}

int main(){
	while(scanf("%d%d%d%d",&N,&x,&T,&K), N+x+T+K != 0){
		for(int i=0;i<K;++i){
			scanf("%d", &p[i]);
			int tot = 0;
			for(int j=0;j<N+1;++j){
				int f;
				scanf("%d",&f);
				tot += f;
			}
			f[i] = tot;
		}

		for(int i=0;i<103;++i)
			for(int j=0;j<23;++j)
				for(int k=0;k<1005;++k)
					dp[i][j][k] = -1;
		int ans = ks(K-1, 0, 0);
		printf("%.2lf\n", (double) ans / (double) (N+1));
	}
	return 0;
}