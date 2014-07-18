#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int choice[10];
int board[10][10];

int main(){
	int TC;
	scanf("%d",&TC);
	while(TC--){
		int N;
		scanf("%d",&N);
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				scanf("%d",&board[i][j]);
			}
		}
		int maximin = 0;
		for(int i=0;i<N;++i){
			choice[i] = i;
			maximin += board[i][i];
		}
		while(next_permutation(choice, choice+N)){
			int temp = 0;
			for(int i=0;i<N;++i){
					temp += board[i][choice[i]];
			}
			if(temp < maximin) maximin = temp;
		}
		printf("%d\n", maximin);
	}
	return 0;
}