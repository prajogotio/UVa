#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int coor[20][2];
double dp[1<<16];
int N;

void solve() {
	dp[0] = 0;
	int K = 2*N;
	for(int b=1;b<(1<<K);++b){
		dp[b] = 12345678;
		for(int i=0;i<K;++i){
			if(b & (1<<i)) {
				for(int j=i+1;j<K;++j){
					if(b & (1<<j)) {
						double dx = coor[i][0] - coor[j][0];
						double dy = coor[i][1] - coor[j][1];
						double dist = sqrt(dx*dx + dy*dy);
						dp[b] = min(dp[b], dp[(b ^ (1<<i))^(1<<j)] + dist);
					}
				}
			}
		}
	}
	printf("%.2lf\n", dp[(1<<K)-1]);
}

int main(){
	string s;
	int tc = 1;
	while(scanf("%d",&N), N!=0){
		printf("Case %d: ", tc++);
		for(int i=0;i<2*N;++i){
			cin >> s;
			scanf("%d%d",&coor[i][0], &coor[i][1]);
		}
		solve();
	}
	return 0;
}