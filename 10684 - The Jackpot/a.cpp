//classical max sum subsequence
//trail + a[i] negative, reset trail
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N,trail,maxi;
	while(scanf("%d",&N), N!=0){
		trail = 0; maxi=-1;
		for(int i=0;i<N;++i){
			int k;
			scanf("%d",&k);
			if(trail + k < 0) {
				maxi = max(maxi,k);
				trail = 0;
			} else {
				trail += k;
				maxi = max(trail, maxi);
			}
		}
		if(maxi > 0) printf("The maximum winning streak is %d.\n", maxi);
		else printf("Losing streak.\n");
	}
	return 0;
}

