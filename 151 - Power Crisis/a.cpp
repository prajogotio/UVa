#include <cstdio>

int main(){
	int N;
	scanf("%d",&N);
	while(N){
		for(int m=1;m<=500;++m){
			int arr[101]={0};
			//normalize 13 to 12
			int k=0;
			int p=0;
			int last=0;
			while(1){
				arr[k]=1;
				last=k;
				++p;
				if(p==N)break;
				int kc=0,ptr=(k+1)%N;
				while(1){
					if(arr[ptr]==0)++kc;
					if(kc==m)break;
					ptr=(ptr+1)%N;
				}
				k=ptr;
			}
			//printf("%d\n",last);
			if(last==12){
				printf("%d\n",m);
				break;
			}
		}
		scanf("%d",&N);
	}
	return 0;
}