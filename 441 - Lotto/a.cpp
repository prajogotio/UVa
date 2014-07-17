#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> mset;
int k;

void dfs(int n, int ctr, vector<int> stack){
	if(ctr == 6){
		for(int i=0;i<6;++i){
			if(i != 0) printf(" ");
			printf("%d",stack[i]);
		}
		printf("\n");
		return;
	}
	if(n == k-1){
		return;
	}
	for(int i = n+1; i<k;++i){
		stack.push_back(mset[i]);
		dfs(i, ctr+1, stack);
		stack.pop_back();
	}
}

int main(){
	bool flag = false;
	while(scanf("%d",&k), k != 0){
		if(flag) printf("\n");
		mset.clear();
		for(int i=0;i<k;++i){
			int num;
			scanf("%d",&num);
			mset.push_back(num);
		}
		dfs(-1,0,vector<int>());
		flag = true;
	}
	return 0;
}