#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int dp[55][5200];
int a[105];
int M, N;
int X = 2600;
void solve() {
	int sum = 0;
	for(int i=0;i<M+N;++i){
		sum += a[i];
	}
	for(int i=0;i<55;++i){
		for(int j=0;j<5200;++j){
			dp[i][j] = 0;
		}
	}
	dp[0][X] = 1;
	for(int k=0;k<M+N;++k){
		vector<pair<int,int> > st;
		for(int i=0;i<=k && i < M;++i){
			for(int j=0;j<5200;++j){
				if(dp[i][j]) {
					st.push_back(make_pair(i+1, j+a[k]));
				}
			}
		}
		for(int i=0;i<st.size();++i){
			dp[st[i].first][st[i].second] = 1;
		}
	}
	int maxans=-12345678, minans=12345678;
	for(int j=0;j<5200;++j){
		if(dp[M][j]) {
			maxans = max(maxans, (j-X) * (sum - j + X));
			minans = min(minans, (j-X) * (sum - j + X));
		}
	}
	printf("%d %d\n",maxans, minans);
}

int main() {
	while(scanf("%d%d",&M,&N) != EOF) {
		for(int i=0;i<M+N;++i) scanf("%d",&a[i]);
		solve();
	}
	return 0;
}