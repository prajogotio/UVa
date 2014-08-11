#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int,int> > col;

int main(){
	int N, a, b;
	int d[] = {0,1,2,3,4,5,6,7,8,9};
	int pow10[] = {1,10,100,1000,10000,100000};
	col.push_back(make_pair(1234, 56789));
	while(next_permutation(d, d+10)){
		a = 0, b = 0;
		for(int i=0;i<5;++i){
			a += pow10[4-i] * d[i];
			b += pow10[4-i] * d[i+5];
		}
		if(a > b) continue;
		col.push_back(make_pair(a,b));
	}
	int sz = col.size();
	bool flag = 0;
	while(scanf("%d", &N), N != 0){
		if(flag) printf("\n");
		bool state = 0;
		for(int i=0;i<sz;++i){
			a = col[i].second;
			b = col[i].first;
			if(b*N == a){
				printf("%05d / %05d = %d\n", a, b, N);
				state = 1;
			}
		}
		if(!state) printf("There are no solutions for %d.\n", N);
		flag = 1;
	}
	return 0;
}