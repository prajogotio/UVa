//choose NCr, NCr-1, NCr-2, ... if not divisible, return 0

#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

int num[203];
int d[203];
ll dp[23][11][203];
int D;
ll comb(int N, int r){
	ll ret = 1;
	for(int i=0;i<r;++i){
		ret *= N-i;
		ret /= (i+1);
	}
	return ret;
}

ll ks(int i, int M, int S){
	if(M < 0) return 0;
	if(M == 0){
		if(S % D == 0) return 1;
		else return 0;
	}
	if(i < 0) return 0;
	if(dp[i][M][S] != -1) return dp[i][M][S];
	ll temp = 0;
	for(int j=0;j<=d[i];++j){
		temp += comb(d[i], j) * ks(i-1, M-j, (S + j*i)%D);
	}
	dp[i][M][S] = temp;
	return temp;
}

int main(){
	int N,Q,M,tc=1;
	while( scanf("%d %d", &N, &Q), N!=0 && Q!=0){
		printf("SET %d:\n", tc++);
		for(int i=0;i<N;++i){
			scanf("%d", &num[i]);
		}
		for(int q=0;q<Q;++q){
			scanf("%d %d", &D, &M);
			for(int i=0;i<D;++i) d[i] = 0;

			for(int i=0;i<23;++i)
				for(int j=0;j<11;++j)
					for(int k=0;k<203;++k)
						dp[i][j][k] = -1;
			for(int i=0;i<N;++i){
				int idx = num[i]%D;
				if(idx < 0) idx += D;
				++d[idx];
			}
			ll ans = ks(D-1, M, 0);
			printf("QUERY %d: %lld\n", q+1, ans);
		}
	}
	return 0;
}