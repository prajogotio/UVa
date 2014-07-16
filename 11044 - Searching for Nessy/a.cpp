#include <cstdio>

int main(){
	int tc;
	scanf("%d",&tc);
	for(int t=0;t<tc;++t){
		int n,m;
		scanf("%d%d",&n,&m);
		int N=(n-2)/3;
		if((n-2)%3!=0)++N;
		int M=(m-2)/3;
		if((m-2)%3!=0)++M;
		printf("%d\n",M*N);
	}
	return 0;
}
