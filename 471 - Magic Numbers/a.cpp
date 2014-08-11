#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
//max 9876543210
// s1 / s2 = N ==> s1 = N * s2  <= 9876543210
//pregenerate all 10! choices
typedef long long ll;
vector<ll> choice;

ll pow10(int n){
	ll ret = 1;
	for(int i=0;i<n;++i){
		ret *= 10LL;
	}
	return ret;
}
void bt(int n, int c, int way, ll num){
	if(n == 0) {
		choice.push_back(num);
		return;
	}
	for(int i=0;i<10;++i){
		if(n == c && i == 0) continue;
		if( way & (1 << i) ) continue;
		bt(n-1, c, way | (1 << i), num + i * pow10(n-1));
	}
}

void gen(){
	choice.clear();
	bt(10, 10, 0, 0);
	for(int i=0;i<choice.size();++i){
		printf("%lld\n", choice[i]);
	}
}

int main(){
	gen();
	return 0;
}