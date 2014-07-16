#include <cstdio>

int left[100005] = {0};
int right[100005] = {0};

int main(){
	int s,b;
	while(scanf("%d%d",&s,&b)!=EOF, s||b){
		for(int i=1;i<=s;++i){
			left[i]=i-1;
			right[i]=i+1;
		}
		right[s]=0;
		int l,r;
		while(b--){
			scanf("%d%d",&l,&r);
			if(left[l]==0)printf("*");
			else printf("%d", left[l]);
			if(right[r]==0)printf(" *\n");
			else printf(" %d\n", right[r]);
			right[left[l]] = right[r];
			left[right[r]] = left[l];
		}
		printf("-\n");
	}
	return 0;
}