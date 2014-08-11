#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		int N, temp;
		scanf("%d", &N);
		int prev = -1, cur;
		int mdif = (int) -1e9;
		for(int i=0;i<N;++i){
			scanf("%d", &cur);
			if(i == 0) {
				prev = cur;
				continue;
			}
			int tdif = prev - cur;
			if( tdif > mdif) {
				mdif = tdif;
			}
			if(prev < cur){
				prev = cur;
			}

		}
		printf("%d\n", mdif);
	}
	return 0;
}