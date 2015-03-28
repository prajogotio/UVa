#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

/* TLE */

int a[50];
int dp[50][80010];
int X = 40000;
int N, F;
int s[2] = {1, -1};

void solve() {
	string ans = "";
	for(int i=0;i<=N;++i){
		for(int j=0;j<80010;++j){
			dp[i][j] = 0;
		}
	}
	int ON = 1;
	for(int k=1;k<=N;++k){
		bool mark[2] = {0, 0};
		for(int sign=0;sign<=1;++sign){

			dp[0][X] = ON;

			for(int i=0;i<N;++i){
				for(int j=0;j<=80000;++j){
					int next = j + s[sign]*a[i+1];
					if(next>=0 && next <= 80000) dp[i+1][next] = max(dp[i][j], dp[i+1][next]);
					if(i+1!=k) {
						next = j - s[sign]*a[i+1];
						if(next>=0 && next<=80000) dp[i+1][next] = max(dp[i][j], dp[i+1][next]);
					}
				}
			}

			if(dp[N][X+F] == ON) mark[sign] = 1; 

			++ON;

		}
		if(mark[0] && mark[1]) ans += "?";
		else if(mark[0]) ans += "+";
		else if(mark[1]) ans += "-";
		else {
			printf("*\n");
			return;
		}
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