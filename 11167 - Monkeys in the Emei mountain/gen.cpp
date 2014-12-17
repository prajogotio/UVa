#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main(){
	srand(time(NULL));
	int N = 50, M = 3;
	printf("%d %d\n", N, M);
	for(int i=0;i<N;++i){
		int u, v, w;
		u = rand()%150;
		v = rand()%150;
		w = rand()%2 + 1;
		if(u>v) swap(u,v);
		if(v-u < w) ++v;
		printf("%d %d %d\n", w, u, v);
	}
	printf("0\n");
	return 0;
}