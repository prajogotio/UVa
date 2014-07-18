#include <iostream>
#include <cstdio>
using namespace std;
int t,N,p,bar[25];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&N);
		scanf("%d",&p);
		for(int i=0;i<p;++i){
			scanf("%d",&bar[i]);
		}
		int lim = 1<<p;
		bool found = false;
		for(int i=0;i<lim;++i){
			int tot = 0;
			for(int j=0;j<p;++j){
				if(i & (1<<j))
					tot += bar[j];
			}
			if(tot == N){
				printf("YES\n");
				found = true;
				break;
			}
		}
		if(!found) printf("NO\n");
	}
	return 0;
}