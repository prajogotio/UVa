#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector<vector<int> > stree;
vector<int> arr;

void build(int i, int j, int p){
	if(i == j){
		vector<int> v(5);
		v[0] = arr[i];
		v[1] = 1;
		v[2] = arr[i];
		v[3] = 1;
		v[4] = 1;
		stree[p] = v;
		return;
	}
	int mid = (i+j)/2;
	build(i, mid, 2*p);
	build(mid+1, j, 2*p+1);
	vector<int> left = stree[2*p];
	vector<int> right = stree[2*p+1];
	vector<int> tmax(5);
	tmax[0] = left[0];
	tmax[1] = left[1];
	tmax[2] = right[2];
	tmax[3] = right[3];
	tmax[4] = max(left[4],right[4]);
	if (left[2] == right[0]){
		int vlr = left[3] + right[1];
		if(vlr > tmax[4]) tmax[4] = vlr;
	}
	if (left[0] == right[0]){
		tmax[1] = tmax[1] + right[1];
	}
	if (left[2] == right[2]){
		tmax[3] = tmax[3] + left[3];
	}
	stree[p] = tmax;
}

vector<int> rmq(int i, int j, int L, int R, int p){
	if(R < i || j < L) return vector<int>();
	if(i <= L && R <= j) return stree[p];
	int mid = (L+R)/2;
	vector<int> left = rmq(i,j,L,mid,2*p);
	vector<int> right = rmq(i,j,mid+1,R, 2*p+1);
	if(left.empty()) return right;
	if(right.empty()) return left;
	vector<int> tmax(5);
	tmax[0] = left[0];
	tmax[1] = left[1];
	tmax[2] = right[2];
	tmax[3] = right[3];
	tmax[4] = max(left[4], right[4]);
	//printf("p = %d, maxfreq = %d, left,val = %d,%d, right,val = %d,%d\n",p,tmax[4],tmax[0],tmax[1],tmax[2],tmax[3]);

	if(left[2] == right[0]){
		int vlr = left[3] + right[1];
		if(vlr > tmax[4]) tmax[4] = vlr;
	}
	if (left[0] == right[0]){
		tmax[1] = tmax[1] + right[1];
	}
	if (left[2] == right[2]){
		tmax[3] = tmax[3] + left[3];
	}
	return tmax;
}

int main(){
	int N,M;
	while(scanf("%d", &N), N!=0){
		scanf("%d",&M);
		stree = vector<vector<int> >(4*N);
		arr.clear();
		for(int i=0;i<N;++i){
			int k;
			scanf("%d",&k);
			arr.push_back(k);
		}
		build(0,N-1,1);
		for(int i=0;i<M;++i){
			int a,b;
			scanf("%d %d",&a,&b);
			vector<int> v = rmq(a-1,b-1,0,N-1,1);
			cout << v[4] << endl;
			//printf("i = %d, maxfreq = %d, left,val = %d,%d, right,val = %d,%d\n",i,v[4],v[0],v[1],v[2],v[3]);
		}
		/*
		for(int i=1;i<4*N;++i){
			vector<int> v = stree[i];
			if(v.empty())continue;
			printf("p = %d, maxfreq = %d, left,val = %d,%d, right,val = %d,%d\n",i,v[4],v[0],v[1],v[2],v[3]);
		}
		*/
	}
	return 0;
}