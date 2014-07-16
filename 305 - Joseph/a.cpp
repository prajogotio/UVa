#include <cstdio>

int main(){
	int k;
	while(1){
		scanf("%d",&k);
		if(k==0)break;
		for(int m=1;m<10000000;++m){
			int a[30]={0};
			bool found=false;
			int b=k;
			int i=0,ctr=0;
			//printf("%d\n", m);
			while(1){
				if(a[i]==0)
					++ctr;
				if(ctr==m){
					a[i]=1;
					ctr=0;
					if(i<k){
						if(b==0)found=true;
						break;
					}else{
						--b;
						if(b==0){
							found=true;
							break;
						}
					}
				}
				//for(int j=0;j<2*k;++j)printf("%d",a[j]);printf("\n");
				i=(i+1)%(2*k);
			}
			if(found){
				printf("%d\n",m);
				break;
			}
		}
	}
	return 0;
}