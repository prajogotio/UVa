#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;


int a[50];
int dp[50][80010];
int dprev[50][80010];
int X = 40000;
int N, F;
int s[2] = {1, -1};

void solve() {
	string ans = "";
	for(int i=0;i<=N+1;++i){
		for(int j=0;j<80010;++j){
			dp[i][j] = 0;
			dprev[i][j]= 0;
		}
	}

	dp[0][X] = 1;
	for(int i=0;i<N;++i){
		for(int j=0;j<=80000;++j){
			int next = j + a[i+1];
			if(next>=0 && next <= 80000) dp[i+1][next] = max(dp[i][j], dp[i+1][next]);
			next = j - a[i+1];
			if(next>=0 && next<=80000) dp[i+1][next] = max(dp[i][j], dp[i+1][next]);
		}
	}
	dprev[N+1][X] = 1;
	for(int i=N+1;i>1;--i){
		for(int j=0;j<=80000;++j){
			int next = j + a[i-1];
			if(next>=0 && next <= 80000) dprev[i-1][next] = max(dprev[i][j], dprev[i-1][next]);
			next = j - a[i-1];
			if(next>=0 && next<=80000) dprev[i-1][next] = max(dprev[i][j], dprev[i-1][next]);
		}
	}
	if(dp[N][X+F] == 0) {
		printf("*\n");
		return;
	}
	for(int k=1;k<=N;++k){
		int mark[2] = {0, 0};
		for(int j=0;j<=80000;++j){
			if(dp[k-1][j]) {
				int something = F + 2*X - a[k] - j;
				if(0<=something && something<=80000) mark[0] = max(mark[0], dprev[k+1][something]);
				something = F + 2*X + a[k] - j;
				if(0<=something && something<=80000) mark[1] = max(mark[1], dprev[k+1][something]);
			}
		}

		if(mark[0] && mark[1]) ans += "?";
		else if(mark[0]) ans += "+";
		else if(mark[1]) ans += "-";
		else ans += "F";
	}
	cout << ans << endl;
}

int main(){
	while(scanf("%d%d",&N,&F), N+F!=0) {
		for(int i=1;i<=N;++i)scanf("%d",&a[i]);
		solve();
	}
	return 0;
}