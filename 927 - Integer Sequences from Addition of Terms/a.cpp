#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int c[30];

int main(){
	int C;
	scanf("%d",&C);
	while(C--){
		int N;
		scanf("%d",&N);
		N = N+1;
		for(int i=0;i<N;++i){
			scanf("%d",&c[i]);
		}
		ll d,k;
		scanf("%lld %lld",&d,&k);
		ll x=0;
		while((x*(x+1)*d)/2 < k){
			++x;
		}
		ll ans=0;
		for(int i = 0; i<N;++i){
			ans *= x;
			ans += c[N-1-i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
