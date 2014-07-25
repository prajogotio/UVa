#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int coins[105];
int dp[50002][105];

int ks(int S, int i){
	if(S < 0) return -2000000000;
	if(S == 0 || i < 0) return 0;
	//printf("%d %d %d\n", S, i, coins[i]);
	if(dp[S][i] != -1) return dp[S][i];
	int temp = 0;
	temp = max(coins[i] + ks(S-coins[i], i-1), ks(S, i-1));
	//printf("%d %d\n", i, temp);
	dp[S][i] = temp;
	return dp[S][i];
}

int main(){
	int TC;
	scanf("%d",&TC);
	while(TC--){
		scanf("%d", &N);
		int sum =0;
		for(int i=0;i<N;++i){
			scanf("%d",&coins[i]);
			sum+= coins[i];
		}
		for(int i=0;i<sum+1;++i){
			for(int j=0;j<N;++j){
				dp[i][j] = -1;
			}
		}
		int S = sum/2;
		if(sum%2 == 1) ++S;
		int val = ks(S,N-1);
		//printf("%d %d\n",sum, val);
		int dif = 2*val - sum;
		if(dif < 0 ) dif = -dif;
		printf("%d\n", dif);

	}
	return 0;
}