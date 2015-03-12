#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;


long long dp[1003][1003];
int val[1003][2];
int num[1003][1003];
string bank[1003][2];
int N, M;


void testAndSet(int i, int j, long long cur, int n) {
	if(dp[i][j] < cur) {
		dp[i][j] = cur;
		num[i][j] = n;
	} else if(dp[i][j] == cur) {
		if(num[i][j] > n) num[i][j] = n;
	}
}

void solve(){
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			dp[i][j] = 0;
			num[i][j] = 0;
			long long cur = 0;
			int n = 0;
			if(bank[i][0] == bank[j][1]) {
				cur = (i > 0 && j > 0 ? dp[i-1][j-1] : 0) + val[i][0] + val[j][1];
				n = (i > 0 && j > 0 ? num[i-1][j-1] : 0) + 1;
			}
			if(i>0)testAndSet(i, j, dp[i-1][j], num[i-1][j]);
			if(j>0)testAndSet(i, j, dp[i][j-1], num[i][j-1]);
			testAndSet(i, j, cur, n);
		}
	}
	printf("%lld %d\n", dp[N-1][M-1], num[N-1][M-1]);
}



int main(){
	int TC;
	scanf("%d",&TC);
	string s, t;
	while(TC--){
		scanf("%d",&N);
		for(int i=0;i<N;++i){
			cin >> s >> t;
			bank[i][0] = t;
			scanf("%d",&val[i][0]);
		}
		scanf("%d",&M);
		for(int i=0;i<M;++i){
			cin >> s >> t;
			bank[i][1] = t;
			scanf("%d",&val[i][1]);
		}
		if(N == 0 || M == 0) {printf("0 0\n");}
		else solve();
	}
}