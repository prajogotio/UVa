#include <cstdio>

int rec(int N){
	if(N<10) return N;
	int M=0;
	while(N!=0){
		M+=N%10;
		N/=10;
	}
	return rec(M);
}

int main(){
	int N;
	scanf("%d",&N);
	while(N){
		printf("%d\n",rec(N));
		scanf("%d",&N);
	}
	return 0;
}