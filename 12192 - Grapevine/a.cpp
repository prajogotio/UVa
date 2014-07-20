#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int> > h(505, vector<int>(505));
vector<vector<int> > v(505, vector<int>(505));
vector<int>::iterator it;
int N,M;

int main(){
	while(scanf("%d %d", &N, &M), N!=0 && M!=0){
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				int k;
				scanf("%d",&k);
				h[i][j] = k;
				v[j][i] = k;
			}
		}
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				printf("%d ",h[i][j]);
			}
			printf("\n");
		}
		for(int i=0;i<M;++i){
			for(int j=0;j<N;++j){
				printf("%d ",v[i][j]);
			}
			printf("\n");
		}
		
		int K;
		scanf("%d",&K);
		while(K--){
			int L,U;
			scanf("%d %d",&L,&U);
			int min_v=-1,min_h=-1,max_v=99999,max_h=99999;
			for(int i=0;i<N;++i){
				int temp = 0;
				temp = lower_bound(h[i].begin(), h[i].begin()+M, L) - h[i].begin();
				min_h = max(min_h, temp);
				//printf("%d-%d\n",i, temp);
				temp = upper_bound(h[i].begin(), h[i].begin()+M, U) - h[i].begin();	
				--temp;
				//printf("%d--%d\n",i, temp);
				max_h = min(max_h, temp);
			}
			for(int i=min_h;i<max_h;++i){
				int temp = 0;
				temp = lower_bound(v[i].begin(), v[i].begin()+N, L) - v[i].begin();
				min_v = max(min_v, temp);
				printf("%d-%d\n",i,temp);

				temp = upper_bound(v[i].begin(), v[i].begin()+N, U) - v[i].begin();	
				--temp;
				printf("%d--%d\n",i,temp);
				
				max_v = min(max_v, temp);
			}
			printf("min_h: %d, max_h: %d, min_v: %d, max_v: %d\n", min_h, max_h, min_v, max_v);
		}
		printf("-\n");
	}
	return 0;
}
