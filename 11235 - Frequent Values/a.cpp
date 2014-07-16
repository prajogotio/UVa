#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector<int> arr;
vector<pair<vector<int>, int> > stree;

vector<int> intersect(vector<int> a, vector<int> b){
	vector<int> ret;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	/*
	int i =0, j =0;
	while(i < a.size() && j < b.size()){
		if(a[i] == b[j]){	
			ret.push_back(a[i]);
			++i, ++j;
		} else if (a[i] > a[j]) {
			++j;
		} else 
			++i;
	}
	*/
	if(*(a.end() -1) == *(b.begin())){
		ret.push_back(*b.begin());
	} else if (*(a.begin()) == *(b.end()-1)){
		ret.push_back(*(a.begin()));
	}
	return ret;
}

int build(int i, int j, int p){
	//printf("%d %d %d\n", i, j, p);
	if(i == j) {
		stree[p] = make_pair(vector<int>(1,arr[i]), 1);
		return 1;
	}
	int mid = (i+j)/2;
	int left = build(i, mid, 2*p);
	int right = build(mid+1, j, 2*p + 1);
	vector<int> c = intersect(stree[2*p].first, stree[2*p+1].first);
	if(left == right){
		if(c.empty()){
			c = stree[2*p].first;
			c.insert(c.end(), stree[2*p+1].first.begin(), stree[2*p+1].first.end());
			stree[p] = make_pair(c, left);
			return left;
		} else {
			stree[p] = make_pair(c, left + right);
			return left+right;
		}
	} else {
		if(c.empty()){
			int freq = max(left, right);
			if(left > right){
				c = stree[2*p].first;
			} else {
				c = stree[2*p+1].first;
			}
			stree[p] = make_pair(c, freq);
			return freq;
		} else {
			stree[p] = make_pair(c, left+right);
			return left+right;
		}
	}
}

pair<vector<int>,int> rmq(int i, int j, int L, int R, int p){
	if(i > R || j < L){
		vector<int> v;
		return make_pair(v,-1);
	}
	if(i <= L && R <= j) return stree[p];
	int mid = (L+R)/2;
	pair<vector<int>, int> left = rmq(i,j,L,mid,2*p);
	pair<vector<int>, int> right = rmq(i,j,mid+1,R,2*p+1);
	if(left.first.empty()) return right;
	if(right.first.empty()) return left;
	vector<int> c = intersect(left.first, right.first);
	if(left.second == right.second){
		if(c.empty()){
			c = left.first;
			c.insert(c.begin(), right.first.begin(), right.first.end());
			return make_pair(c, left.second);
		} else {
			return make_pair(c, left.second + right.second);
		}
	} else {
		if(c.empty()){
			if(left.second > right.second){
				c = left.first;
			} else {
				c = right.first;
			}
			return make_pair(c, max(left.second, right.second));
		} else {
			return make_pair(c, left.second + right.second);
		}
	}
}
	


int main(){
	int N,Q;
	while(scanf("%d",&N), N != 0){
		scanf("%d",&Q);
		stree.clear();
		arr.clear();
		stree = vector<pair<vector<int>, int> >(4*N);
		for(int i=0;i<N;++i){
			int k;
			scanf("%d", &k);
			arr.push_back(k);
		}
		build(0, N-1, 1);
		for(int i=1;i<4*N;++i){
			vector<int> v = stree[i].first;
			printf("p = %d, maxfreq = %d\n", i, stree[i].second);
			printf("values:");
			for(int j=0;j<v.size();++j){
				printf(" %d", v[j]);
			}
			printf("\n");
		}
		for(int i=0;i<Q;++i){
			int a, b;
			scanf("%d %d", &a, &b);
			pair<vector<int>, int> ret = rmq(a,b,0,N-1,1);
			cout << ret.second << endl;
		}
	}
	return 0;
}
