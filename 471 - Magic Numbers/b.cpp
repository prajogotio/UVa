#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int dig[] = {0,1,2,3,4,5,6,7,8,9};
vector<ll> choice;
ll gen(){
	ll ret = 0;
	for(int i=0;i<10;++i){
		ret *= 10;
		ret += dig[i];
	}
	return ret;
}
int main(){
	while(next_permutation(dig, dig+10)){
		if(dig[0] == 0) continue;
		choice.push_back(gen());
	}
	for(int i=0;i<choice.size();++i){
		printf("%lld\n", choice[i]);
	}
	return 0;
}