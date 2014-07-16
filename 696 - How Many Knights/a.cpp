#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int M,N;
	scanf("%d%d",&M,&N);
	while(M!=0||N!=0){
		int K;
		if(M==1||N==1){
			K=max(M,N);
		}else if((M==2 && N>=2) || (M>=2 && N==2)){
			int C=max(M,N);
			K=(C/4)*4;
			if(C%4==1){K+=2;}
			if(C%4==2 || C%4==3){K+=4;}
		}else{
			K=(M*N)/2;
			if(M%2==1 && N%2==1)++K;
		}
		printf("%d knights may be placed on a %d row %d column board.\n",K,M,N);
		scanf("%d%d",&M,&N);
	}
	return 0;
}
