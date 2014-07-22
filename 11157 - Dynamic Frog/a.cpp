//Greedy choice: choose alternating S rocks
//Intuition: when u choose a set of rocks from 1 2 3 4 5 6 7
//eg 2 4 6  and 1 3 5 7
//will reduce to finding a way to minimize subsequent distances

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > small;
vector<int> big;
int N, end;
int main(){
	int TC;
	scanf("%d",&TC);
	for(int T=1;T<=TC;++T){
		printf("Case %d: ",T);
		big.clear();
		small.clear();
		scanf("%d %d",&N,&end);
		big.push_back(0);
		small.push_back(vector<int>());
		int itv = 0;
		for(int i=0;i<N;++i){
			char state;
			int M;
			scanf(" %c-%d", &state, &M);
			if(state == 'B'){
				small.push_back(vector<int>());
				big.push_back(M);
				++itv;
			} else {
				small[itv].push_back(M);
			}
		}
		big.push_back(end);
		int mleap=-1;
		for(int i=0;i<=itv;++i){
			int sz = small[i].size();
			int temp = -1;
			for(int j=2;j<sz;++j)
					temp = max(small[i][j]-small[i][j-2], temp);
			if(sz <= 1)
				temp = max(big[i+1] - big[i], temp);
			if(sz > 1){
				temp = max(small[i][1] - big[i], temp);
				temp = max(big[i+1] - small[i][sz-2], temp);
			}
			mleap = max(mleap, temp);
		}
		printf("%d\n", mleap);
	}
	return 0;
}