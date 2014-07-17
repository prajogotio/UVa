#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> num;
int main(){
	int TC;
	scanf("%d",&TC);
	while(TC--){
		int N;
		scanf("%d",&N);
		num.clear();
		int tot=0;
		while(N--){
			int val;
			scanf("%d",&val);
			for(int i=0;i<num.size();++i){
				if(num[i] <= val) ++tot;
			}
			num.push_back(val);
		}
		printf("%d\n", tot);
	}
	return 0;
}