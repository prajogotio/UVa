#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
map<int,int> bag;
map<int,int>::iterator it;
vector<vector<int> > pack;
int N;
int main(){
	bool flag = false;
	while(scanf("%d",&N), N!=0){
		if(flag) printf("\n");
		bag.clear();
		pack.clear();
		int maxsz=0,idx = 0;
		for(int i=0;i<N;++i){
			int k;
			scanf("%d",&k);
			++bag[k];
			if(maxsz < bag[k]) maxsz = bag[k];
		}
		pack.assign(maxsz, vector<int>());
		for(it = bag.begin(); it!=bag.end(); ++it){
			for(int i=0;i< it->second;++i){
				pack[idx].push_back(it->first);
				idx = (idx+1)%maxsz;
			}
		}
		printf("%d\n", maxsz);
		for(int i=0;i<maxsz;++i){
			for(int j=0;j<pack[i].size();++j){
				if(j!=0) printf(" ");
				printf("%d", pack[i][j]);
			}
			printf("\n");
		}
		flag = true;
	}
	return 0;
}