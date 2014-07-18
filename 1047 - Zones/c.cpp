#include <iostream>
#include <cstdio>
#include <utility>
using namespace std;

pair<int,int> common[15];
int tower[25];
int R,choice;

int main(){
	int P,T,M, tc=1;
	while(scanf("%d %d",&P,&T), P!=0 && T!=0){
		choice = 0; R = -1;
		for(int i=0;i<P;++i){
			scanf("%d",&tower[i]);
		}
		scanf("%d",&M);
		for(int m=0;m<M;++m){
			int nM,key=0,val;
			scanf("%d",&nM);
			for(int i=0;i<nM;++i){
				int j; scanf("%d", &j);
				key |= (1<<(j-1));
			}
			scanf("%d",&val);
			common[m] = make_pair(key,val);
		}

		int lim = 1<<P;
		for(int i=0;i<lim;++i){
			int k=0;
			for(int j=0; j<P;++j){
				if(i & (1<<j))
					++k;
			}
			if(k != T) continue;
			int ret = 0;
			for(int j=0;j<P;++j){
				if(i & (1<<j)){
					ret += tower[j];
				}
			}

			for(int j=0;j<M;++j){
				int intersect = (common[j].first & i);
				int ctr=0;
				for(int c=0;c<P;++c){
					if(intersect & (1<<c))
						++ctr;
				}
				if(ctr <= 1) continue;
				//count how many intersect, and substract accordingly
				ret -= (ctr-1)*common[j].second;
			}
			if(ret > R){
				R = ret;
				choice = i;
			} else if( ret == R){
				for(int j=0;j<P;++j){
					int a = (i & (1<<j));
					int b = (choice & (1<<j));
					if(a != b){
						if( a>0 ){
							R = ret;
							choice = i;
						}
						break;
					}
				}
			}
		}
		printf("Case Number  %d\n", tc++);
		printf("Number of Customers: %d\n", R);
		printf("Locations recommended:");
		for(int i=0;i<P;++i){
			if(choice & (1<<i)){
				printf(" %d", i+1);
			}
		}
		printf("\n\n");
	}
	return 0;
}

