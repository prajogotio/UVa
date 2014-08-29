#include <iostream>
#include <cstdio>
using namespace std;

int p[50003];
int val[50003][3];
int main(){
	int u;
	for(int i=0;i<50003;++i) p[i] = 0;
	for(int i=0;i<=50000;++i){
		if( 3*i*i > 50000 ) break;
		for(int j=i;j<=50000;++j){
			if(i*i + 2*j*j > 50000) break;
			for(int k=j;k<=50000;++k){
				u = i*i + j*j + k*k;
				if(u > 50000) break;
				if(p[u]) continue;
				p[u] = 1;
				val[u][0] = i;
				val[u][1] = j;
				val[u][2] = k;
	}}}
	
	int TC, N;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &N);
		if(p[N]) printf("%d %d %d\n", val[N][0], val[N][1], val[N][2]);
		else printf("-1\n");
	}
	return 0;
}