#include <cstdio>

int main(){
	int K;
	scanf("%d",&K);
	while(K){
		int M,N;
		scanf("%d%d",&M,&N);
		for(int t=0;t<K;++t){
			int X,Y;
			scanf("%d%d",&X,&Y);
			if(M==X||N==Y)printf("divisa\n");
			else if(X<M && Y<N)printf("SO\n");
			else if(X<M && Y>N)printf("NO\n");
			else if(X>M && Y<N)printf("SE\n");
			else  printf("NE\n");
		}
		scanf("%d",&K);
	}
	return 0;
}