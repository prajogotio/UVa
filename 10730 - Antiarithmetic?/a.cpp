#include <iostream>
#include <cstdio>
using namespace std;
int p[10003];
int N;
int main(){
	int u, v, ctr, prev;
	while(scanf("%d:", &N), N!= 0){
		for(int i=0;i<N;++i){
			scanf("%d", &u);
			p[u] = i;
		}
		bool found = false;
		
		for(int d=1;d<=N/2;++d){
			for(int u=0;u<d;++u){
				if(u + 2*d >= N) break;
				ctr = 1;
				prev = p[u];
				v = u + d;
				while(v < N){
					if(prev < p[v]){
						++ctr;
					} else {
						ctr = 1;
					}
					if(ctr == 3){
						found = true;
						break;
					}
					prev = p[v];
					v += d;
				}
				if(found) break;
			}
			if(found) break;
		}
		if(found) printf("no\n");
		else printf("yes\n");
		
	}
	return 0;
}