#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int arr[205];
int p[23];
int dp[23][15];
int N, Q, M, D;

ll comb(int N, int r){
	ll temp = 1;
	for(int i=0;i<r;++i){
		temp *= (ll) (N-i);
		temp /= (ll) (i+1);
	}
	return temp;
}

ll ks(int d, int m){
	if(m > 0 && d < 0) return 0;
	if(m == 0) return 1;
	if(m < 0) return 0;
	if(dp[d][m] != -1) return dp[d][m];
	ll temp = 0;
	for(int i=0;i<=p[d] && i <= m;++i){
		temp += comb(p[d], i) * ks(d-1, m-i);
	}
	dp[d][m] = temp;
	return dp[d][m];
}

int main(){
	int tc=1;
	while(scanf("%d %d", &N, &Q), N!=0 && Q!=0){
		printf("SET %d:\n", tc++);
		for(int i=0;i<N;++i){
			scanf("%d",&arr[i]);
		}
		for(int q=0;q<Q;++q){
			printf("QUERY %d:\n", q+1);
			scanf("%d %d", &D, &M);
			for(int i=0;i<D;++i)
				for(int j=0;j<M;++M)
					dp[i][j] = -1;
			for(int i=0;i<D;++i) p[i] = 0;
			for(int i=0;i<N;++i){
				++p[arr[i] % D];
			}
			ll temp = ks(D-1, M);
			printf("%lld\n", temp);
		}
	}

	return 0;
}