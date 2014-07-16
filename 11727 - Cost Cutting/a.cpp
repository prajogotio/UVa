#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int TC;
	scanf("%d",&TC);
	for(int T=0;T<TC;++T){
		int a[3];
		scanf("%d%d%d",&a[0],&a[1],&a[2]);
		sort(a,a+3);
		printf("Case %d: %d\n",T+1,a[1]);
	}
	return 0;
}