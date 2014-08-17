#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
//RUNNING TIME?
//WRONG APPROACH a = b+c+d can be negative
typedef long long llong;

llong S[1005];
int N;

int main(){
	llong R, K, L;
	bool finish;
	while(scanf("%d", &N),  N!=0){
		finish = false;
		for(int i=0;i<N;++i) {scanf("%lld", &S[i]);}
		sort(S, S+N);
		for(int i=N-1;i>=0;--i){
			R = S[i];
			for(int j=i-1;j>=0;--j){
				if(S[j]*3 - 3 < R) break;
				K = R - S[j];
				for(int k=j-1;k>=0;--k){
					if(S[k]*2 - 1 < K) break;
					L = K - S[k];
					for(int m=k-1;m>=0;--m){
						if(S[m] < L) break;
						if(L - S[m] == 0) {
							finish = true;
							printf("%lld\n", S[i]);
							break;
						}
					}
					if(finish) break;
				}
				if(finish) break;
			}
			if(finish) break;
		}
		if(!finish) printf("no solution\n");
	}
	return 0;
}