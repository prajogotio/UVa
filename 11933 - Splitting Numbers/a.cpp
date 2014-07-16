#include <cstdio>

int main(){
	long long N;
	while(scanf("%lld",&N), N!=0){
		long long k=0;
		int state=0;
		long long j=0,m;
		while(m = (1LL<<j), m <= N){
			if(N & m){
				if(state==0)
					k+=m;
				state = (state+1)%2;
			}
			++j;
		}
		printf("%lld %lld\n",k,N-k);
	}
	return 0;
}