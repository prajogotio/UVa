#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int a[3005];
	while(scanf("%d",&n)!=EOF){
		int N=n;
		fill(a,a+3005,0);
		int prev,cur;
		scanf("%d",&prev);
		while(--n){
			scanf("%d",&cur);
			int diff = cur-prev;
			diff=max(diff,-diff);
			a[diff]=1;
			prev=cur;
		}
		bool jolly=true;
		for(int i=1;i<N;++i){
			if(a[i]==0){
				jolly=false;
				break;
			}
		}
		if(jolly)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
	return 0;
}