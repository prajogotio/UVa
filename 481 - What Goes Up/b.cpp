#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> par;
vector<int> dp;
vector<int> num;

void printout(int idx){
	if(idx == -1) return;
	printout(par[idx]);
	printf("%d\n", num[idx]);
}

int main(){
	int N,cur=0;
	while(scanf("%d", &N) != EOF){
		num.push_back(N);
		if(dp.empty()){
			dp.push_back(cur);
			par.push_back(-1);
			++cur;
			continue;
		}
		
		int lo = 0, hi = dp.size()-1, mid;
		while(lo <= hi){
			mid = (hi+lo)/2;
			if(num[dp[mid]] < N){
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}
		int it = lo;
		if(it == dp.size()){
			par.push_back(dp[it-1]);
			dp.push_back(cur);
		} else {
			if(it > 0) par.push_back(dp[it-1]);
			else par.push_back(-1);
			dp[it] = cur;
		}

		++cur;
	}
	cout << dp.size() << endl;
	printf("-\n");
	printout(dp[dp.size()-1]);
	return 0;
}
