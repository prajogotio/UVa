#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int V, Vo;

double D(double v){
	return 0.3 * sqrt(v - (double) Vo);
}

int main(){
	while(scanf("%d %d", &V, &Vo), V+Vo != 0){
		int ans = 0, ctr = 0;
		double mlen = -1;
		int lim = (V/Vo);
		for(int i=1;i<=lim;++i){
			double v = (double) V / (double) i;
			if( fabs(v-Vo) < 1e-12 || v < Vo) continue;
			double tlen = D(v) * (double) i;
			//cout << tlen << " " << mlen << endl;
			if( fabs(tlen-mlen) < 1e-12) {
				++ctr;
			} else if (tlen > mlen){
				mlen = tlen;
				ans = i;
				ctr = 0;
			}
		}
		if(ctr >= 1) ans = 0;
		printf("%d\n", ans);
	}
	return 0;
}