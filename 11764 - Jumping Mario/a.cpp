#include <cstdio>

int main(){
	int TC;
	scanf("%d",&TC);
	for(int T=0;T<TC;++T){
		int N;
		scanf("%d",&N);
		int prev;
		int up=0,down=0;
		scanf("%d",&prev);
		for(int i=1;i<N;++i){
			int cur;
			scanf("%d",&cur);
			if(prev<cur)
				++up;
			if(prev>cur)
				++down;
			prev=cur;
		}
		printf("Case %d: %d %d\n",T+1,up,down);
	}
	return 0;
}