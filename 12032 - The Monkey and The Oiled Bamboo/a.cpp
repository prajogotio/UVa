#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100005];
int diff[100005];

int main(){
	int TC,N;
	scanf("%d",&TC);
	for(int T=1;T<=TC;++T){
		printf("Case %d: ", T);
		arr[0] = 0;
		scanf("%d",&N);
		for(int i=1;i<=N;++i){
			scanf("%d",&arr[i]);
			diff[i-1] = arr[i] - arr[i-1];
		}
		int lo=0, hi = 100000001,mid;
		while(lo<=hi){
			mid = (hi+lo)/2;
			int k = mid;
			bool possible = true;
			for(int i=0;i<N;++i){
				if(diff[i] > k){
					possible = false;
					break;
				} else if(diff[i] == k){
					--k;
				}
			}
			if(possible){
				hi = mid-1;
			} else {
				lo = mid+1;
			}
		}
		printf("%d\n", lo);
	}
	return 0;
}