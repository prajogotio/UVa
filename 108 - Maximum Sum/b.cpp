#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[103][103];
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			int k;
			scanf("%d",&k);
			int sum = 0;
			if(i > 0) sum += a[i-1][j];
			if(j > 0) sum += a[i][j-1];
			if(i > 0 && j > 0) sum -= a[i-1][j-1];
			sum += k;
			a[i][j] = sum;
		}
	}
	/*
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	*/
	int max_sum=-1;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			for(int k=i;k<N;++k){
				for(int l=j;l<N;++l){
					int temp = a[k][l];
					if(i > 0) temp -= a[i-1][l];
					if(j > 0) temp -= a[k][j-1];
					if(i > 0 && j > 0) temp += a[i-1][j-1];
					//printf("%d %d %d %d %d\n",i,j,k,l,temp);
					max_sum = max(max_sum, temp);
				}
			}
		}
	}
	printf("%d\n", max_sum);
	return 0;
}
