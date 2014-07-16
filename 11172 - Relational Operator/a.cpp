#include <cstdio>

int main(){
	int tc;
	scanf("%d",&tc);
	for(int t=0;t<tc;++t){
		int n,m;
		scanf("%d%d",&n,&m);
		if(n>m)printf(">\n");
		else if(n<m)printf("<\n");
		else printf("=\n");
	}
	return 0;
}