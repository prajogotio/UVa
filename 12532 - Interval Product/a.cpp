//wrong leh
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
#define LSB(i) ( (i) & (-(i)) )
// 1 pos, 2 pos zero, -1 neg, -2 neg zero
vector<int> ftree;
vector<int> arr;
int N;

void update(int i, int val){
	int k = (val > 0) ? 1 : -1;
	if(k == 1) return;
	if(val == 0) k = 0;
	ftree[i] = k;
	i += LSB(i);
	while(i <= N){
		ftree[i] *= k;
		i += LSB(i);
	}
}

int rsq(int i){
	if(i <= 0) return 1;
	int ret = 1;
	while(i > 0){
		ret *= ftree[i];
		i -= LSB(i);
	}
	return ret;
}

void build(){
	for(int i = 0;i < N;++i){
		update(i+1, arr[i]);
	}
}

int main(){
	int K,i,j;
	while( scanf("%d %d", &N,&K) != EOF){
		ftree.assign(N+1,1);
		arr.assign(N+1,0);
		for(int k=0;k<N;++k){
			scanf(" %d",&arr[k]);
		}
		build();
		for(j=1;j<N+1;++j) printf("%d ", ftree[j]); printf("\n");
		string str;
		while(K--){
			cin >> str;
			cin >> i >> j;
			if(str[0] == 'C'){
				update(i+1, j);
			}else{
				int prod = 1;
				int k = rsq(j+1);
				int l = rsq(i);
				if( l == 0 ) prod = k;
				else prod = k*l;
				if(prod == 0) printf("0");
				else if(prod == 1) printf("+");
				else printf("-");
			}
		}
		printf("\n");
	}
	return 0;
}
