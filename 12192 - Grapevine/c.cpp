#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N,M,mlen;
int arr[503][503];

void bsearch(int i,int j,int L, int U){
	int lim = min(N-i-1, M-j-1);
	int lo,hi,mid,left,right;

	lo = 0, hi = lim;
	while(lo <= hi){
		mid = (lo+hi)/2;
		if(arr[i+mid][j+mid] < L){
			lo = mid+1;
		} else {
			hi = mid-1;
		}
	}
	left = lo;
	if(left == lim+1)return;

	lo = 0, hi = lim;
	while(lo <= hi){
		mid = (lo+hi)/2;
		if(arr[i+mid][j+mid] < U+1){
			lo = mid+1;
		} else {
			hi = mid-1;
		}
	}
	right = lo-1;
	if(right == -1)return;

	mlen = max(right-left+1,mlen);
}

int main(){
	while(scanf("%d %d",&N,&M), N!=0 && M!=0){
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				cin>>arr[i][j];
			}
		}
		/*
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		*/

		int K;
		scanf("%d",&K);
		while(K--){
			int m,n;
			mlen = -1;
			scanf("%d %d",&m,&n);
			for(int i=0;i<N;++i)
				bsearch(i,0,m,n);
			for(int j=0;j<M;++j)
				bsearch(0,j,m,n);
			if(mlen == -1) mlen = 0;
			printf("%d\n",mlen);
		}
		printf("-\n");
	}
	return 0;
}