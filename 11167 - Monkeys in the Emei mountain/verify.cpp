#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

int interval[50003];

int main(){
	//check for yes, one test case only
	FILE* problem = fopen("t.in", "r");
	FILE* answer = fopen("t.out", "r");
	int N, M;
	int n;
	int u,v;
	int _n, _u, _v;
	fscanf(problem, "%d %d", &N, &M);
	fscanf(answer, " Case %d: Yes\n", &n);
	for(int i=0;i<N;++i){
		printf("monkey: %d\n", i);
		fscanf(problem, "%d %d %d", &_n, &_u, &_v);
		printf("to drink:%d, [%d,%d]\n", _n, _u, _v);
		fscanf(answer, "%d", &n);
		printf("answer: %d", n);
		int ctr = 0;
		for(int i=0;i<n;++i){
			fscanf(answer," (%d,%d)", &u,&v);
			printf(" (%d,%d)", u, v);
			assert(u < v);
			assert(_u <= u);
			assert(v <= _v);
			for(int j=u;j<v;++j){
				interval[j]++;
				++ctr;
				assert(interval[j] <= M);
			}
		}
		printf("\n");
		assert(ctr == _n);
	}
	printf("OK\n");
	return 0;
}