#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int choice[43] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,24,26,27,28,30,32,33,34,36,38,39,40,42,45,48,50,51,54,57,60};

int main(){
	int N;
	while(scanf("%d",&N), N>0){
		int comb=0,perm=0;
		for(int i=0;i<43;++i){
			int val = 3*choice[i];
			if(val == N){
				++comb;
				++perm;
			}
		}
		for(int i=0;i<43;++i){
			for(int j=0;j<43;++j){
				if(i==j)continue;
				int val = 2*choice[i] + choice[j];
				if(val == N){
					++comb;
					perm += 3;
				}
			}
		}
		for(int i=0;i<43;++i){
			for(int j=i+1;j<43;++j){
				for(int k=j+1;k<43;++k){
					int val = choice[i] + choice[j] + choice[k];
					if(val == N){
						++comb;
						perm += 6;
					}
				}
			}
		}
		if(comb == 0){
			printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", N);
		} else {
			printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\nNUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", N, comb, N, perm);
		}
		printf("**********************************************************************\n");
	}
	printf("END OF OUTPUT\n");
}
