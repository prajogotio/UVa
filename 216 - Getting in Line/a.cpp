#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
double maxd = 1e9;

int x[9];
int y[9];

double dp[9][1024];
int par[9][1024];
int N;

double dist(int i, int j){
	double dx = x[i] - x[j];
	double dy = y[i] - y[j];
	return sqrt(dx*dx + dy*dy) + 16;
}

double tsp(int pos, int choice){
	if(choice == (1 << N) - 1) return 0;
	if(dp[pos][choice] >= 0) return dp[pos][choice];
	double temp = maxd;
	int tpar = -1;
	for(int i=0;i<N;++i){
		if(choice & (1<<i)) continue;
		double val = tsp(i, choice | (1<<i)) + dist(pos, i);
		if( temp >  val ){
			temp = val;
			tpar = i;
		}
	}
	dp[pos][choice] = temp;
	par[pos][choice] = tpar;
	return temp;
}

int main(){
	int tc = 1;
	while(scanf("%d", &N), N!=0){
		printf("**********************************************************\n");
		printf("Network #%d\n", tc++);
		for(int i=0;i<9;++i)
			for(int j=0;j<1024;++j)
				dp[i][j] = -1;

		for(int i=0;i<N;++i){
			scanf("%d %d", &x[i], &y[i]);
		}
		double minval = maxd;
		int idx = -1;
		for(int i=0;i<N;++i){
			double val = tsp(i, (1<<i));
			if(val < minval){
				minval = val;
				idx = i;
			}
		}
		int bitset = 0;
		double tot = 0;
		while(--N){
			bitset |= (1<<idx);
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", x[idx], y[idx], x[par[idx][bitset]], y[par[idx][bitset]], dist(idx, par[idx][bitset]) );
			idx = par[idx][bitset];			
		}
		printf("Number of feet of cable required is %.2lf.\n",minval);
	}
	return 0;
}