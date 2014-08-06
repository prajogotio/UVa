#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

double arb[23][23];
int seq[23][23][23];
int nseq[23][23];
int N;

void printout(){
		for(int i=0;i<N;++i){
		for(int j=0;j<N;++j)
			printf("%lf ", arb[i][j]);
		printf("\n");
	}
}

void floyd(){

	for(int k=0;k<N;++k){
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j){
				double temp = arb[i][k] * arb[k][j];
				if(temp > arb[i][j]){
					arb[i][j] = temp;
					seq[i][j][nseq[i][j]] = k+1;
					++nseq[i][j];
				}
			}
	}
}

int main(){
	while(cin>>N){
		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j)
				nseq[i][j] = 0;
		double v;
		for(int i=0;i<N;++i){
			arb[i][i] = 1;
			for(int j=0;j<N;++j){
				if(j==i) continue;
				scanf("%lf", &v);
				arb[i][j] = v;
			}
		}
		floyd();
		printout();
		int length = 10000, idx = -1;
		for(int i=0;i<N;++i){
			if(arb[i][i] - 1 > 0.01 && nseq[i][i] < length){
				idx = i;
				length = nseq[i][i];
			}
		}
		if(idx == -1) printf("no arbitrage sequence exists\n");
		else {
			printf("%d", idx+1);
			for(int i=0;i<nseq[idx][idx];++i){
				printf(" %d", seq[idx][idx][i]);
			}
			printf(" %d\n", idx+1);
		}
	}
	return 0;
}
