#include <cstdio>

int main(){
	int TC;
	scanf("%d",&TC);
	for(int T=0;T<TC;++T){
		int f, a[30][3];
		scanf("%d",&f);
		for(int i=0;i<f;++i){
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		}
		int ans=0;
		for(int i=0;i<f;++i){
			ans+=a[i][2]*a[i][0];
		}
		printf("%d\n",ans);
	}
	return 0;
}