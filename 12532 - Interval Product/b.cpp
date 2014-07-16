#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


vector<int> stree;
vector<int> arr;
int N;

void build(int i, int j, int p){
	if(i==j){
		stree[p] = arr[i];
		return;
	}
	int mid = (i+j)/2;
	build(i, mid, 2*p);
	build(mid+1, j, 2*p+1);
	stree[p] = stree[2*p] * stree[2*p+1];
}

int rpq(int i, int j, int L, int R, int p){
	if(i > R || j < L) return 1;
	if(i <= L && R <= j){
		return stree[p];
	}
	int left = rpq(i, j, L, (L+R)/2, 2*p);
	int right = rpq(i, j, (L+R)/2 + 1, R, 2*p+1);
	return left*right;
}

void update(int i, int j, int L, int R, int p, int val){
	if(i > R || j < L) return;
	if(L == R){
		stree[p] = val;
		return;
	}
	update(i, j, L, (L+R)/2, 2*p, val);
	update(i,j,(L+R)/2+1, R, 2*p+1, val);
	stree[p] = stree[2*p] * stree[2*p+1];
}

int main(){
	string str;
	int K, s,t;
	while(scanf("%d %d", &N,&K) != EOF){
		stree.assign(4*N,1);
		arr.assign(N+1,0);
		for(int i=0;i<N;++i){
			int k;
			scanf("%d",&k);
			if(k > 0) k = 1;
			else if(k < 0) k = -1;
			else k = 0;
			arr[i] = k;
		}
		build(0, N-1, 1);
		//for(int i =1;i<4*N;++i)printf("%d ",stree[i]); printf("\n");
		for(int k=0;k<K;++k){
			cin>>str;
			cin>>s>>t;
			if(str[0] == 'C'){
				if(t > 0) t = 1;
				else if (t < 0) t = -1;
				else t = 0;
				update(s-1, s-1, 0, N-1, 1, t);
				//for(int i =1;i<4*N;++i)printf("%d ",stree[i]); printf("\n");

			} else {
				int ans = rpq(s-1, t-1, 0, N-1, 1);
				if(ans == 0) printf("0");
				else if(ans == 1) printf("+");
				else printf("-");
			}
		}
		printf("\n");
	}
	return 0;
}

