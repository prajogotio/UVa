#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int N,M;
ll K,p[105][105];
int main(){
	int TC,tc=1;
	scanf("%d",&TC);
	while(TC--){
		printf("Case #%d: ", tc++);
		scanf("%d %d %lld",&N,&M,&K);
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				ll val;
				scanf("%lld",&val);
				if(i>0) val += p[i-1][j];
				if(j>0) val += p[i][j-1];
				if(i>0 && j>0) val -= p[i-1][j-1];
				p[i][j] = val;
			}
		}
		int max_a = -1;
		ll min_c = 4000000000000LL;
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				for(int a=i;a<N;++a){
					for(int b=j;b<M;++b){
						int cur_a = (a-i+1) * (b-j+1);
						if(cur_a < max_a) continue;
						ll cost = p[a][b];
						if(i>0) cost -= p[i-1][b];
						if(j>0) cost -= p[a][j-1];
						if(i>0 && j>0) cost += p[i-1][j-1];
						if(cur_a == max_a){
							if(cost < min_c) min_c = cost;
						} else {
							if(cost <= K){
								min_c = cost;
								max_a = cur_a;
							}
						}
		}	}	}	}
		if(max_a == -1 || min_c == 4000000000000LL) printf("0 0\n");
		else printf("%d %lld\n", max_a, min_c);
	}
	return 0;
}