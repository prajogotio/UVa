#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
//1 5 10 25 50
int N;
int d[5] = {1,5,10,25,50};
ll dp[5][30003];
//ll dp1[30003];
/*
ll rec(int S, int i){
	if(i == 0) return 1;
	if(dp[i][S] != -1) return dp[i][S];
	ll temp=0;
	for(int j=0;j<=(S/d[i]); ++j){
		temp += rec(S-(d[i]*j), i-1);
	}
	dp[i][S] = temp;
	return temp;
}
*/
/*
ll rec1(int S, int ){
	if(S < 0) return 0;
	if(S == 0) return 1;
	if(dp1[S] != -1) return dp1[S];
	ll temp = 0;
	for(int i=0;i<5;++i){
		temp += rec1(S-d[i]);
	}
	dp1[S] = temp;
	return temp;
}
*/

ll rec2(int i, int S){
	if(S < 0 || i < 0) return 0; //cannot use type i < 0
	if(S == 0) return 1; //only one way to use type i of sum 0 ==> dont use any
	if(dp[i][S] != -1) return dp[i][S];
	ll temp = rec2(i-1, S) + rec2(i, S-d[i]); //ignore type i, or use type i
	dp[i][S] = temp;
	return temp;
}

int main(){
	//don't need to reset, why? subproblems in every N overlaps
	for(int i=0;i<5;++i)
		for(int j=0;j<30003;++j)
			dp[i][j] = -1;
	while(scanf("%d", &N)!=EOF){
		
		//for(int i=0;i<N+1; ++i) dp1[i] = -1;
		//ll ans = rec(N, 4);
		//ll ans = rec1(N);
		ll ans = rec2(4, N);
		if(ans != 1) printf("There are %lld ways to produce %d cents change.\n", ans, N);
		else printf("There is only 1 way to produce %d cents change.\n", N);
	}
	return 0;
}