#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
vector<ll> nums;
ll pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};

void build(int n, int c, int way, ll num){
	if(n == 0){
		nums.push_back(num);
		return;
	}
	for(int i=0;i<10;++i){
		if(i == 0 && n == c) continue;
		if(way & (1<<i)) continue;
		build(n-1, c, way | (1<<i), num + i* pow10[n-1]);
	}
}

void gen(){
	nums.clear();
	for(int i=1;i<10;++i){
		build(i, i, 0, 0);
	}
}

int main(){
	gen();
	int TC;
	ll N;
	scanf("%d", &TC);
	bool flag = false;
	while(TC--){
		if(flag) printf("\n");
		scanf("%lld", &N);
		ll lim = 9876543210/N;
		int i = 0;
		while(nums[i] <= lim){
			ll ch = nums[i] * N;
			int way = 0;
			bool yes = true;
			while(ch){
				int temp = ch % 10;
				if( way & ( 1 << temp ) ) {
					yes = false;
					break;
				}
				way |= (1<<temp);
				ch /= 10;
			}
			if(yes) printf("%lld / %lld = %lld\n", nums[i] * N, nums[i], N);
			++i;
		}
		flag = true;
	}

	return 0;
}