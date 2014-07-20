#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N,M,mlen;
int arr[503][503];
vector<vector<int> > p;

void bsearch(int i,int j,int k){
	int lim = min(N-1-i, M-1-i);
	int lo=0, hi=lim;
	int left,right;
	int mid;
	while(lo <= hi){
		mid = (lo + hi)/2;
		if(arr[i][i+mid] < j){
			lo = mid + 1;
		} else {
			hi = mid-1;
		}
	}
	left = lo; //check again
	if(left == lim+1)return;
	lo =0, hi=min(N-1-i,M-1-i);
	while(lo <= hi){
		mid = (lo+hi)/2;
		if(arr[i][i+mid] < k+1){
			lo = mid+1;
		} else {
			hi = mid-1;
		}
	}
	right = lo-1;
	if(right == -1)return;
	if(right - left + 1 >mlen) mlen = right - left + 1;
}

int main(){
	while(scanf("%d %d",&N,&M), N!=0 && M!=0){
		p.clear();
		mlen = -1;
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
		for(int i=0; i<=M;++i){

		int K;
		scanf("%d",&K);
		while(K--){
			int m,n;
			scanf("%d %d",&m,&n);
			for(int i=0;i<N;++i)
				bsearch(i,m,n);
			printf("%d\n",mlen);
		}
		printf("-\n");
	}
	return 0;
}