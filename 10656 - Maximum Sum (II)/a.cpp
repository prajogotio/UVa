#include <iostream>
#include <cstdio>
using namespace std;
int N;
int k;
int arr[1005];
int main(){
	while(scanf("%d",&N), N!=0){
		k=0;
		for(int i=0;i<N;++i){
			int v;
			scanf("%d",&v);
			if(v!=0){
				arr[k] = v;
				++k;
			}
		}
		if(k==0)printf("0");
		for(int i=0;i<k;++i){
			if(i!=0)printf(" ");
			printf("%d",arr[i]);
		}
		printf("\n");
	}
	return 0;
}