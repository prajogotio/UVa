#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;


int dp[1<<20];
int val[1<<20];
int a[23];
int N;


void solve() {
	sort(a, a+N);
	for(int b=0, sz=(1<<N);b<sz;++b){
		val[b] = -1;
		dp[b] = 0;
	}
	int sum = 0;
	val[0] = 0;
	for(int i=0;i<N;++i){
		sum += a[i];
		val[1<<i] = a[i];
	}
	int X = sum/4;
	if(sum % 4 != 0) {
		printf("no\n");
		return;
	}
	for(int b=0, sz=(1<<N);b<sz;++b){
		if(val[b] != -1) continue;
		int msb = b & (-b);
		val[b] = val[msb] + val[b ^ msb];
	}
	for(int b=0, sz=(1<<(N-1));b<sz;++b){
		int bm = (b << 1) | 1;
		for(int i=0;i<N-1;++i){
			if(b & (1<<i)) {
				dp[b] = max(dp[b], dp[b ^ (1<<i)]);
			}
		}
		if(val[bm] == (dp[b]+1) * X) dp[b]++;
	}
	if(dp[(1<<(N-1))-1] == 4) {
		printf("yes\n");
	} else {
		printf("no\n");
	}
}

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d",&N);
		for(int i=0;i<N;++i) scanf("%d",&a[i]);
		solve();
	}
	return 0;
}