#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main(){
	ll N = 2000;
	for(ll a = 1; a<=N;++a){
		for(ll b = a; b<=N-a;++b){
			for(ll c = b; c<=N-a-b;++c){
				for(ll d = c; d<=N-a-b-c;++d){
					if(a*b*c*d == (a+b+c+d)*1000000LL){
						printf("%lld.%02lld %lld.%02lld %lld.%02lld %lld.%02lld\n", a/100, a%100, b/100, b%100, c/100, c%100, d/100, d%100);
	}	}	}	}	}
	return 0;
}