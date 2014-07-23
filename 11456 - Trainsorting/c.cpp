//a_0 is either accepted or not. if accepted, all cars less than itself will be behind, while all cars larger will be after.
//so LDS or LIS
//otherwise, a_0 is not accepted, we solve for S_k-1 (repeat)
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int c[2005];
int dp[2][2005];
int N;
int main(){
	int TC;
	scanf("%d",&TC);
	while(TC--){
		scanf("%d",&N);
		if(N==0){
			printf("0\n");
			continue;
		}
		for(int i=0;i<N;++i){
			scanf("%d",&c[i]);
		}
		int max_sum = -1;
		for(int i=N-1;i>=0;--i){
			dp[0][i] = 1;
			dp[1][i] = 1;
			for(int j=i+1;j<N;++j){
				if(c[i] < c[j])
					dp[0][i] = max(dp[0][j]+1, dp[0][i]);
				if(c[i] > c[j])
					dp[1][i] = max(dp[1][j]+1, dp[1][i]);
			}
			max_sum = max(dp[0][i] + dp[1][i] - 1, max_sum);

		}
		printf("%d\n",max_sum);
	}
	return 0;
}