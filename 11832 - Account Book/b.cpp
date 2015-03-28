#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

/* STILL TLE */

int a[50];
int dp[50][80010];
int dprev[50][80010];
int can[50][80010];
int X = 40000;
int N, F;
int s[2] = {1, -1};

void solve() {
	string ans = "";
	for(int i=0;i<=N+1;++i){
		for(int j=0;j<80010;++j){
			dp[i][j] = 0;
			dprev[i][j]= 0;
			can[i][j] = 0;
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
	int ON = 1;
	for(int k=1;k<=N;++k){
		int mark[2] = {0, 0};
		if(k > N/2) {
			for(int j=0;j<=80000;++j){
				can[k-1][j] = (dp[k-1][j] ? ON : 0);
			}
			for(int i=k-1;i<N;++i){
				for(int j=0;j<=80000;++j){
					int next = j + a[i+1];
					if(next>=0 && next <= 80000) can[i+1][next] = max(can[i][j], can[i+1][next]);
					if(i+1!=k){
						next = j - a[i+1];
						if(next>=0 && next<=80000) can[i+1][next] = max(can[i][j], can[i+1][next]);
					}
				}
			}
			if(can[N][F+X] == ON) mark[0] = 1;
			for(int j=0;j<=80000;++j){
				int next = j - 2*a[k];
				if(next >= 0 && next <= 80000) can[N+1][next] = max(can[N+1][next], can[N][j]);
			}
			if(can[N+1][F+X] == ON) mark[1] = 1;
		} else {
			for(int j=0;j<=80000;++j){
				can[k+1][j] = (dprev[k+1][j] ? ON : 0);
			}
			for(int i=k+1;i>1;--i){
				for(int j=0;j<=80000;++j){
					int next = j + a[i-1];
					if(next>=0 && next <= 80000) can[i-1][next] = max(can[i][j], can[i-1][next]);
					if(i-1!=k){
						next = j - a[i-1];
						if(next>=0 && next<=80000) can[i-1][next] = max(can[i][j], can[i-1][next]);
					}
				}
			}
			if(can[1][F+X] == ON) mark[0] = 1;
			for(int j=0;j<=80000;++j){
				int next = j - 2*a[k];
				if(next >= 0 && next <= 80000) can[0][next] = max(can[0][next], can[1][j]);
			}
			if(can[0][F+X] == ON) mark[1] = 1;
		}
		if(mark[0] && mark[1]) ans += "?";
		else if(mark[0]) ans += "+";
		else ans += "-";
		++ON;
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