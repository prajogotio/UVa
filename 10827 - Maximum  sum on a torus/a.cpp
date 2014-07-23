#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[80][80];
int dp[160][160];
int N;
int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &N);
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				scanf("%d", &a[i][j]);
			}
		}
		for(int i=0;i<2*N;++i){
			for(int j=0;j<2*N;++j){
				int val = a[i%N][j%N];
				if(i>0) val += dp[i-1][j];
				if(j>0) val += dp[i][j-1];
				if(i>0 && j>0) val -=dp[i-1][j-1];
				dp[i][j] = val;
			}
		}
		int max_sum = -2000000000;
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				for(int a=i; a<N+i;++a){
					for(int b=j; b<N+j;++b){
						int temp = dp[a][b];
						if(i>0) temp -= dp[i-1][b];
						if(j>0) temp -= dp[a][j-1];
						if(i>0 && j>0) temp += dp[i-1][j-1];
						max_sum = max(temp, max_sum);
		} } } }
		printf("%d\n", max_sum);
	}
	return 0;
}
