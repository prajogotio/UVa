#include <cstdio>
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m), n||m){
		bool a[1000003] = {0};
		int i=n,j=m;
		bool gconf=false;
		while(i--){
			int p,q;
			scanf("%d%d",&p,&q);
			if(gconf)continue;
			bool conf = false;
			for(int k=p;k<q;++k){
				if(a[k]==1){
					conf=true;
					printf("CONFLICT\n");
					break;
				}
				a[k]=1;
			}
			if(conf){
				gconf=true;
				continue;
			}
		}
		while(j--){
			int p,q,r;
			scanf("%d%d%d",&p,&q,&r);
			if(gconf) continue;
			bool conf = false;
			for(int k=0;p+k*r<=1000000;++k){
				for(int e=p+k*r;e<q+k*r && e<=1000000;++e){
					if(a[e]==1){
						printf("CONFLICT\n");
						conf=true;
						break;
					}
					a[e]=1;
				}
				if(conf)break;
			}
			if(conf){
				gconf = true;
				continue;
			}
		}
		if(gconf)continue;
		printf("NO CONFLICT\n");
	}
	return 0;
}

