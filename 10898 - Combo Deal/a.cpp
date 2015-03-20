#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int dp[10][10][10][10][10][10];
int order[6];
int K, N;
int prices[20];
int tuples[20][6];

void precompute() {
	dp[0][0][0][0][0][0] = 0;
	for(int i1=0;i1<10;++i1){
		for(int i2=0;i2<10;++i2){
			for(int i3=0;i3<10;++i3){
				for(int i4=0;i4<10;++i4){
					for(int i5=0;i5<10;++i5){
						for(int i6=0;i6<10;++i6){
							if(i1+i2+i3+i4+i5+i6 == 0) continue;
							dp[i1][i2][i3][i4][i5][i6] = 12345678;
							for(int j=0;j<N;++j){
								if(i1>=tuples[j][0] && i2>=tuples[j][1] && i3 >= tuples[j][2] && i4 >= tuples[j][3] && i5 >= tuples[j][4] && i6 >= tuples[j][5]) {
									dp[i1][i2][i3][i4][i5][i6] = min(dp[i1][i2][i3][i4][i5][i6], dp[i1-tuples[j][0]][i2-tuples[j][1]][i3-tuples[j][2]][i4-tuples[j][3]][i5-tuples[j][4]][i6-tuples[j][5]] + prices[j]);
								}
							}
						}
					}
				}
			}
		}
	}
}

int main() {
	while(scanf("%d",&K)!=EOF) {
		for(int i=0;i<K;++i){
			scanf("%d",&prices[i]);
			for(int j=0;j<6;++j){
				tuples[i][j] = (i==j ? 1 : 0);
			}
		}
		scanf("%d",&N);
		for(int i=0;i<N;++i){
			for(int j=0;j<6;++j){
				if(j<K) scanf("%d",&tuples[i+K][j]);
				else tuples[i+K][j] = 0;
			}
			scanf("%d",&prices[i+K]);
		}
		N += K;
		precompute();
		int x, y;
		scanf("%d",&x);
		for(int i=0;i<x;++i){
			for(int j=0;j<6;++j){
				if(j<K)scanf("%d",&order[j]);
				else order[j]=0;
			}
			printf("%d\n",dp[order[0]][order[1]][order[2]][order[3]][order[4]][order[5]]);
		}
	}
	return 0;
}