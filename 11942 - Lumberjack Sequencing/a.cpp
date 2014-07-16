#include <cstdio>

int main(){
	int N;
	scanf("%d",&N);
	printf("Lumberjacks:\n");
	for(int t=0;t<N;++t){
		bool nondec=true;
		bool noninc=true;
		int prev;
		scanf("%d",&prev);
		for(int i=1;i<10;++i){
			int cur;
			scanf("%d",&cur);
			if(prev<cur){
				noninc=false;
			}
			if(prev>cur){
				nondec=false;
			}
			prev=cur;
		}
		if(nondec||noninc){
			printf("Ordered\n");
		}else{
			printf("Unordered\n");
		}
	}
	return 0;
}