#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int ll;

ll arr[1000005];
ll sum[1000005];
int N,M;
ll minimax;

int main(){
	while(scanf("%d %d", &M, &N)!=EOF){
		sum[0] = 0;
		minimax=2000000000000;
		for(int i=0;i<M;++i){
			scanf("%lld",&arr[i]);
			sum[i+1] = arr[i] + sum[i];
		}
		ll lo=0,hi=1000000000001,mid;
		while(lo <= hi){
			mid = (lo+hi)/2;
			if(mid > sum[M]) {
				hi = mid-1;
				continue;
			}
			bool found = true;
			ll S = mid;
			int K = N;
			int i=0;
			while(K && i != M){
				int j = upper_bound(sum+i+1, sum+M+1, S + sum[i]) - sum;
				--j;
				if(j == -1){
					found = false;
					break;
				}
				//printf("%d %d %d\n", K, i, j);
				i = j;
				--K;
			}
			if(i != M) found = false;
			if(found){
				hi = mid-1;
				//if(minimax > mid) minimax = mid;
			} else {
				lo = mid+1;
			}
			//printf("mid: %lld\n",mid);
		}
		printf("%lld\n", lo);
	}
	return 0;
}