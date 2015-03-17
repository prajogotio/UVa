#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
using namespace std;

/*
	dp[62][14][1000]
	
	dp[k][i][val] = 1 if can form summation of i elements using the last k primes = val
	dp[k][i][val] = max(dp[k+1][i][val], dp[k+1][i-1][val-p[k]], dp[k+1][i-2][val-p[k]*2])
*/

int mark[305];
int dp[70][20][1010];
vector<int> primes;
int N, T;
int K;

void lexicalSort() {
	vector<pair<string,int> > st;
	vector<int> b;
	for(int i=0;i<primes.size();++i){
		b.clear();
		int val = primes[i];
		while(val) {
			b.push_back(val%10);
			val /= 10;
		}
		string s = "";
		for(int j=b.size()-1;j>=0;--j){
			s += '0' + b[j];
		}
		st.push_back(make_pair(s, primes[i]));
	}
	sort(st.begin(), st.end());
	for(int i=0;i<primes.size();++i){
		primes[i] = st[i].second;
	}
}

void solve() {
	if(dp[0][T][N]) {
		int val = N;
		int t = T;
		vector<int> st;
		for(int k=0;k<K;++k){
			if(primes[k]!=2 && t-2>=0 && val-primes[k]*2 >=0 && dp[k+1][t-2][val-primes[k]*2]) {
				st.push_back(primes[k]);
				st.push_back(primes[k]);
				t -= 2;
				val -= primes[k]*2;
			} else if(t-1>=0 && val-primes[k] >=0 && dp[k+1][t-1][val-primes[k]]) {
				st.push_back(primes[k]);
				--t;
				val -= primes[k];
			}
			if(t == 0 && val == 0) break;
		}
		for(int i=0;i<st.size();++i){
			if(i!=0)printf("+");
			printf("%d",st[i]);
		}
		printf("\n");
	} else {
		printf("No Solution.\n");
	}
}

int main(){
	for(int i=2;i*i<305;++i){
		for(int j=i;j*i<305;++j){
			mark[j*i] = 1;
		}
	}
	for(int i=2;i<=300;++i){
		if(mark[i])continue;
		primes.push_back(i);
	}
	K = primes.size();
	lexicalSort();

	for(int i=0;i<70;++i){
		for(int j=0;j<20;++j){
			for(int k=0;k<=1000;++k){
				dp[i][j][k] = 0;
			}
		}
	}
	for(int k=0;k<=K;++k){
		dp[k][0][0] = 1;
	}
	for(int k=K-1;k>=0;--k){
		for(int i=1;i<=14;++i){
			for(int val=1;val<=1000;++val){
				dp[k][i][val] = dp[k+1][i][val];
				if(val-primes[k] >= 0) dp[k][i][val] = max(dp[k][i][val], dp[k+1][i-1][val-primes[k]]);
				if(primes[k]!=2 && i-2>=0 && val-primes[k]*2 >= 0) dp[k][i][val] = max(dp[k][i][val], dp[k+1][i-2][val-primes[k]*2]);
			}
		}
	}

	int tc = 1;
	while(scanf("%d%d",&N,&T), N+T!=0){
		printf("CASE %d:\n",tc++);
		solve();
	}
	return 0;
}