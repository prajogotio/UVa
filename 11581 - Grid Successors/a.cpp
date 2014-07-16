#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int tc;
	int a[10000][5][5] = {0};
	scanf("%d",&tc);
	while(tc--){
		int k=0;
		for(int i=1;i<=3;++i)
			for(int j=1;j<=3;++j)
				scanf("%1d",&a[k][i][j]);
/*
		for(int i=1;i<=3;++i){
			for(int j=1;j<=3;++j)
				printf("%d",a[k][i][j]);
			printf("\n");
		}
		*/
		bool found = false;
		while(k<9999){
			for(int i=1;i<=3;++i)
				for(int j=1;j<=3;++j)
					a[k+1][i][j] = (a[k][i-1][j] + a[k][i+1][j] + a[k][i][j-1] + a[k][i][j+1])%2;

			int idx;
			for(int p=0;p<k;++p){
				bool same = true;
				for(int q=1;q<=3;++q){
					for(int r=1;r<=3;++r){
						if(a[p][q][r]!=a[k+1][q][r]){
							same= false;
							break;
						}
					}
					if(!same) break;
				}
				if(same) {
					found = true;
					idx = p;
					break;
				}
			}
			if(found){
				printf("%d\n",idx-1);
				break;
			}
			++k;
		}
	}
	return 0;
}
