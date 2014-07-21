#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

int main(){
	ll N,U,L,ans;
	while(scanf("%lld %lld %lld",&N,&L,&U)!=EOF){
		ans = 0;
		for(int i=0;i<=32;++i){
			ll state = (N & (1L<<(32-i)));
			//printf("%lld\n", state);
			//printf("%lld\n", ans);
			if(state){
				//if the bit is set
				//if not setting this bit can still fulfill the constraint
				ll temp = state -1;
				temp |= ans;
				if(temp < L){
					ans |= state;
				}
			} else {
				//if not set, should set if fulfill constraint
				ll temp = ans;
				temp |= (1L<<(32-i));
				if(temp <= U){
					ans = temp;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}