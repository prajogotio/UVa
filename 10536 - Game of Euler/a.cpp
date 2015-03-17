#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int dp[1<<16];
string s[4];
void precompute() {
	dp[0] = 1;
	for(int b=1;b<(1<<16);++b){
		dp[b] = 0;
		for(int i=0;i<4;++i){
			for(int j=0;j<4;++j){
				int k = 4 * i + j;
				if(b & (1<<k)) {
					dp[b] |= dp[b ^ (1<<k)] ^ 1;
				}
			}
		}
		for(int i0=0;i0<4;++i0){
			int i1 = i0 + 4;
			int i2 = i0 + 8;
			int i3 = i0 + 12;
			if(b & (1 << i0)) {
				if(b & (1 << i1)) {
					int _b = (1<<i0) | (1<<i1);
					dp[b] |= dp[b ^ (_b)] ^ 1;
					if(b & (1 << i2)) {
						_b |= (1 << i2);
						dp[b] |= dp[b ^ (_b)] ^ 1;
					}
				}
			}
			if(b & (1 << i3)) {
				if(b & (1 << i2)) {
					int _b = (1<<i3) | (1<<i2);
					dp[b] |= dp[b ^ (_b)] ^ 1;
					if(b & (1 << i1)) {
						_b |= (1 << i1);
						dp[b] |= dp[b ^ (_b)] ^ 1;
					}
				}
			}
		}
		for(int i0=0;i0<16;i0 += 4){
			int i1 = i0 + 1;
			int i2 = i0 + 2;
			int i3 = i0 + 3;
			if(b & (1 << i0)) {
				if(b & (1 << i1)) {
					int _b = (1<<i0) | (1<<i1);
					dp[b] |= dp[b ^ (_b)] ^ 1;
					if(b & (1 << i2)) {
						_b |= (1 << i2);
						dp[b] |= dp[b ^ (_b)] ^ 1;
					}
				}
			}
			if(b & (1 << i3)) {
				if(b & (1 << i2)) {
					int _b = (1<<i3) | (1<<i2);
					dp[b] |= dp[b ^ (_b)] ^ 1;
					if(b & (1 << i1)) {
						_b |= (1 << i1);
						dp[b] |= dp[b ^ (_b)] ^ 1;
					}
				}
			}
		}
	}
}

void solve() {
	int b = 0;
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			if (s[i][j] == '.') {
				int k = i * 4 + j;
				b |= (1<<k);
			}
		}
	}
	if(dp[b]) printf("WINNING\n");
	else printf("LOSING\n");
}

int main(){
	precompute();
	int TC;
	scanf("%d",&TC);
	while(TC--){
		for(int i=0;i<4;++i) cin >> s[i];
		solve();
	}
	return 0;
}