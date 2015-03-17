#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int dp[1<<12];
string s;
void precalculate() {
	dp[0] = 0;
	for(int k=1;k<=12;++k){
		for(int b=1;b<(1<<12);++b){
			int cnt = 0;
			for(int i=0;i<12;++i){
				if(b & (1<<i)) cnt++;
			}
			if(cnt!=k)continue;
			dp[b] = cnt;
			for(int i=0;i<12;++i){
				if(b & (1<<i)) {
					if(i-2>=0 && ((b & (1<<(i-2))) == 0) && (b & (1<<(i-1)))) {
						dp[b] = min(dp[b], dp[b ^ (7 << (i-2))]);
					}
					if(i+2<12 && ((b & (1<<(i+2))) == 0) && (b & (1<<(i+1)))) {
						dp[b] = min(dp[b], dp[b ^ (7 << i)]);
					}
				}
			}
		}
	}
}

void solve() {
	int b = 0;
	for(int i=0;i<12;++i){
		if(s[i] == 'o') b |= (1 << i);
	}
	printf("%d\n",dp[b]);
}

int main(){
	precalculate();
	int TC;
	scanf("%d",&TC);
	while(TC--){
		cin >> s;
		solve();
	}
	return 0;
}