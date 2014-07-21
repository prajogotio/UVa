#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N,M;
int d[20005];
int k[20005];

int main(){
	while(scanf("%d %d",&N,&M), N!=0 && M!=0){
		for(int i=0;i<N;++i)
			scanf("%d",&d[i]);
		for(int i=0;i<M;++i)
			scanf("%d", &k[i]);
		sort(d,d+N);
		sort(k,k+M);
		int i=0,j=0;
		long long sum=0;
		if(N > M){
			printf("Loowater is doomed!\n");
			continue;
		}
		while(i<N && j<M){
			if(d[i] <= k[j]){
				sum += (long long) k[j];
				++i;
				++j;
			} else {
				++j;
			}
		}
		if(i == N)
			printf("%lld\n", sum);
		else
			printf("Loowater is doomed!\n");
	}
	return 0;
}