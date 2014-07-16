#include <cstdio>

int a[] = {0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881,13482720};


int main(){
	while(1){
		int k;
		scanf("%d",&k);
		if(k==0)break;
		printf("%d\n",a[k]);
	}
	return 0;
}