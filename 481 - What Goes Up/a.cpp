#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> par;
vector<int> num;
vector<int> dp;

void print_out(int idx){
	if(idx == -1) return;
	print_out(par[idx]);
	printf("%d\n", num[idx]);
}

int main(){
	int N,curr=0,max_dp=0,idx=-1;
	while(scanf("%d",&N)!=EOF){
		num.push_back(N);
		par.push_back(-1);
		dp.push_back(1);
		for(int i=curr-1;i>=0;--i){
			if(num[i] < N && dp[i] + 1 > dp[curr]){
				dp[curr] = dp[i] + 1;
				par[curr] = i;
			}
		}
		if(dp[curr] >= max_dp){
			max_dp = dp[curr];
			idx = curr;
		}
		++curr;
	}
	printf("%d\n-\n", max_dp);
	print_out(idx);
	return 0;
}
