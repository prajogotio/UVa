#include <cstdio>

int main(){
	int N;
	while(scanf("%d",&N) != EOF){
		if(N==0)break;
		int nS=N/4;
		if(N%4!=0)++nS;
	 	int a[105][2]={0};
	 	printf("Printing order for %d pages:\n",N);
	 	if(N==1){
	 		printf("Sheet 1, front: Blank, 1\n");
	 		continue;
	 	}
	 	for(int i=0;i<nS*2;++i){
	 		if(1+i>N)break;
	 		a[i][(i+1)%2]=i+1;
	 	}
	 	for(int i=0;i<nS*2;++i){
	 		if(i+1+nS*2>N)continue;
	 		a[2*nS-i-1][(i+1)%2]=i+1+nS*2;
	 	}
	 	for(int i=0;i<nS*2;++i){
	 		int pg=i/2+1;
	 		char side[2][30] = {"front" , "back "};
	 		printf("Sheet %d, %s:",pg, side[i%2]);
	 		if(a[i][0]!=0)
	 			printf(" %d",a[i][0]);
	 		else printf(" Blank");
	 		
	 		if(a[i][1]!=0)
	 			printf(", %d\n",a[i][1]);
	 		else printf(", Blank\n");
	 	}
	}
	return 0;
}