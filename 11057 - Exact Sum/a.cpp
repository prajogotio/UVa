#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int arr[10005];
int A, B;

int main(){
	int N,M;
	while(scanf("%d",&N) != EOF){
		for(int i=0;i<N;++i){
			scanf("%d", &arr[i]);
		}
		scanf("%d",&M);
		sort(arr, arr+N);
		A=0, B = 2000000000;
		for(int i=0;i<N;++i){
			int S = M - arr[i];
			int* p = NULL;
			if(S < arr[i]){
				if(i == 0) continue;
				p = lower_bound(arr, arr + i, S);
				if(*p != S) continue;
			} else {
				if(i == N-1) continue;
				p = lower_bound(arr+i+1, arr + N, S);
				if(*p != S) continue;
			}
			int T = *p, Q = arr[i];
			//printf("%d %d\n",T,Q);
			int d1 = (A-B > 0)? A-B:B-A;
			int d2 = (T-Q > 0)? T-Q:Q-T;
			if(d1 > d2){
				A = T;
				B = Q;
			}
		}
		if( A > B ) swap(A,B);
		printf("Peter should buy books whose prices are %d and %d.\n", A, B);
		printf("\n");
	}
	return 0;
}