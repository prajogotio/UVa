#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

set<vector<int> > mset;
vector<int> num(15);
int N,T;

void dfs(vector<int> s, int sum, int i){
	if(sum > N || i > T) return;
	if(sum == N){
		sort(s.begin(), s.end());
		reverse(s.begin(), s.end());
		mset.insert(s);
		return;
	}
	for(int j=i; j<T;++j){
		s.push_back(num[j]);
		dfs(s, sum+num[j], j+1);
		s.pop_back();
	}
}

int main(){
	while(scanf("%d %d", &N, &T), N!=0 && T!=0){

		for(int i=0;i<T;++i){
			scanf("%d",&num[i]);
		}
		printf("Sums of %d:\n",N);
		mset.clear();
		dfs(vector<int>(), 0, 0);
		set<vector<int> >::iterator it;
		if(!mset.size()){
			printf("NONE\n");
			continue;
		}
		set<vector<int> >::iterator end = (mset.begin());
		set<vector<int> >::iterator beg = --(mset.end());
		for(it = beg; it != end; --it){
			int sz = (*it).size();
			for(int i=0;i<sz;++i){
				if(i != 0) printf("+");
				printf("%d", (*it)[i]);
			}
			printf("\n");
		}
		int sz = (*it).size();
		for(int i=0;i<sz;++i){
			if(i != 0) printf("+");
			printf("%d", (*it)[i]);
		}
		printf("\n");
	}
	return 0;
}