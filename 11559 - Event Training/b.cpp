#include <cstdio>

int main(){
	int N,B,H,W;
	while(scanf("%d%d%d%d",&N,&B,&H,&W) != EOF){
		int R=1000000000;
		for(int i=0;i<H;++i){
			int P;
			scanf("%d",&P);
			bool can=false;
			for(int j=0;j<W;++j){
				int b;
				scanf("%d",&b);
				if(b>=N)can=true;
			}
			if(can){
				if(R>P*N)R=P*N;
			}
		}
		if(R==1000000000 || R>B)printf("stay home\n");
		else printf("%d\n",R);
	}
	return 0;
}
