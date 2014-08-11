#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int can[63];
double loc[8];
int G[8], Y[8], R[8];
int N;

bool pass(int i, double temp){
	int T = (int) temp;
	double diff = temp - T;
	/*
	if( fabs(diff - 1) < 1e-9 ) {
		diff = 0;
		T++;
	}
	*/
	//printf("%d %.3lf %d %lf \n", i, temp, T, diff);
	int period = G[i] + Y[i] + R[i];
	int rem = T % period;
	double rrem = (double) rem + diff;
	return (rrem < (double)(G[i] + Y[i]) || (fabs(rrem - (double) (G[i] + Y[i])) < 1e-9) );
}

int main(){
	int tc = 1;
	/*
	for(int i=30;i<=60;++i){
		printf("%2d ", i);
	}
	printf("\n");
	*/
	while(scanf("%d", &N), N != -1){
		printf("Case %d: ", tc++);
		for(int i=0;i<N;++i){
			scanf("%lf %d %d %d", &loc[i], &G[i], &Y[i], &R[i]);
		}
		for(int i=30;i<=60;++i){
			can[i] = 1;
			for(int j=0;j<N;++j){
				double temp = ((loc[j] * 3600 ) / (double) i);
				if(!pass(j, temp)){
					can[i] = 0;
					break;
				}
				//cout << i << " " << temp << " " << T << endl;

			}
		}
		int ctr = 0;
		bool state2 = 0;
		bool state = 0;
		int prev;
		for(int i=30;i<=60;++i){
			if(can[i] && state == 0){
				state2 = 1;
				state = 1;
				prev = i;
			} else if( (can[i] == 0 && state == 1)){
				++ctr;
				if(ctr > 1) printf(", ");
				state = 0;
				if(i-1 == prev){
					printf("%d", prev);
				} else {
					printf("%d-%d", prev, i-1);
				}
			}
		}
		if(!state2) printf("No acceptable speeds.");
		else if(state == 1) {
			if(ctr >= 1) printf(", ");
			if(prev == 60) printf("60");
			else printf("%d-60", prev);
		}
		printf("\n");
	}
	return 0;
}
