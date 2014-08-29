#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;

int main(){
	int TC, ans, S, K, temp;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &N);
		ans = (int) 1e9;
		for(int i=1;i<=N;++i){
			S = N/i;
			if( S * i != N) continue;
			if( i*i > N) break;
			for(int j=1; j<=S; ++j){
				K = S/j;
				if( K * j != S) continue;
				if( j*j > S ) break;
				temp = 2 * (i*j + j*K + K*i);
				ans = min(temp, ans);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}