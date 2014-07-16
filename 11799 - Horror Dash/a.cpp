#include <cstdio>

int main(){
	int tc;
	scanf("%d",&tc);
	for(int t=0;t<tc;++t){
		int N;
		scanf("%d",&N);
		int m=-1;
		for(int i=0;i<N;++i){
			int n;
			scanf("%d",&n);
			if(m<n)m=n;
		}
		printf("Case %d: %d\n",t+1,m);
	}
	return 0;
}
