#include <cstdio>

int main(){
	int TC;
	scanf("%d",&TC);
	for(int T=0;T<TC;++T){
		int N;
		scanf("%d",&N);
		int R = (63*N+7492)*5-498;
		if(R<0)R*=-1;
		printf("%d\n",(R/10)%10);
	}
	return 0;
}
