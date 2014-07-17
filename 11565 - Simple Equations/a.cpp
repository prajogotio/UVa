#include <cstdio>
#include <cmath>
typedef long long ll;
ll a[3];

int main(){
	int TC;
	scanf("%d",&TC);
	while(TC--){
		ll A,B,C;
		scanf("%lld %lld %lld",&A,&B,&C);
		if(C < 0){
			printf("No solution.\n");
			continue;
		}
		ll lim = sqrt((double)C) + 2;
		int idx = -1;
		for(ll x = -lim; x <=lim; ++x){
			if(2*x*x*x - 2*A*x*x + (A*A - C) * x - 2*B == 0){
				a[++idx] = x;
			}
		}
		if(idx == 2){
			printf("%lld %lld %lld\n", a[0], a[1], a[2]);
		} else {
			printf("No solution.\n");
		}
	}
	return 0;
}
