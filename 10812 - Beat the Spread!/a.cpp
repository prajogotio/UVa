#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int TC;
	scanf("%d",&TC);
	for(int T=0;T<TC;++T){
		int s,d;
		scanf("%d%d",&s,&d);
		int x = (s+d);
		int y = (s-d);
		if(x<0||y<0 || (s%2 != d%2)){
			printf("impossible\n");
			continue;
		}
		if(x<y)swap(x,y);
		printf("%d %d\n",x/2,y/2);
	}
	return 0;
}