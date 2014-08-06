//i think this problem is not easy AT ALL
//Floyd Warshall extension
//D[i][j][k][s]
//if D[i][k][k-1][s-1] * D[k][j][k-1][1] bigger, relax
//why s-1 and 1? because:
//assume i -> k -> m -> j for some m != j
//if m > k, then m is not in 1 ... k-1, which will be considered by outer loop later
//if m < k : 
//that means i-> m -> j  >  i -> k -> j, hence wont relax in the first place!!
//hence k == m, thus k->j is of length 1

//requires FW for path construction
//total O(N^4)
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

double arb[23][23][23];
int par[23][23][23];
int N;

void floyd(){
	for(int s=1;s<N;++s){ //0 indexed
		for(int k=0;k<N;++k){
			for(int i=0;i<N;++i){
				for(int j=0;j<N;++j){
					double temp = arb[i][k][s-1]*arb[k][j][0];
					if(temp > arb[i][j][s]){
						arb[i][j][s] = temp;
						par[i][j][s] = k; //since par[k][j][0] = k
					}
				}
			}
		}
	}
}

void check(){
	for(int s=0;s<N;++s){ //0 indexed
		printf("s = %d\n", s);
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				
				printf("%lf ", arb[i][j][s]);
			}
			printf("\n");
		}
	}
}	

void printout(int i, int j, int s){
	if(s == 0){
		printf("%d", i+1);
		return;
	}
	printout(i, par[i][j][s], s-1);
	printf(" %d", par[i][j][s]+1);
}

int main(){
	double v;
	while(cin >> N){
		//printf("%d\n", N);
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				for(int s=0;s<N;++s){
					par[i][j][s] = i;
					if(i == j) par[i][j][s] = -1;
					arb[i][j][s] = 0;
				}
			}
		}
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(i==j) {
					arb[i][j][0] = 1;
					continue;
				}
				scanf("%lf", &v);
				arb[i][j][0] = v;
			}
		}
		floyd();
		//check();
		int idx=-1, step = -1;
		for(int s=1;s<N;++s){
			for(int i=0;i<N;++i){
				if(arb[i][i][s] > 1.01){
					idx = i;
					step = s;
					break;
				}
			}
			if(idx != -1) break;
		}
		//printf("%d %d\n", idx, step);
		if(idx == -1) printf("no arbitrage sequence exists\n");
		else {
			printout(idx, idx, step);
			printf(" %d\n", idx+1);
		}
	}
	return 0;
}