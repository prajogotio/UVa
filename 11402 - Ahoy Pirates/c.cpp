#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> pirates;
vector<int> lazy;
vector<int> stree;
int N;

int build(int i, int j, int p){
	if(i==j){
		stree[p] = pirates[i];
		return stree[p];
	}
	int mid = (i+j)/2;
	int left = build(i, mid, 2*p);
	int right = build(mid+1, j, 2*p +1);
	stree[p] = left+right;
	return stree[p];
}

void propagate(int L, int R, int p){
	if(lazy[p] != 0){
		stree[p] += lazy[p];
		if(L != R){
			lazy[2*p] += lazy[p];
			lazy[2*p+1] += lazy[p];
		}
		lazy[p] = 0;
	}
}

int rmq(int i, int j, int L, int R, int p){
	propagate(L,R,p);
	if(j < L || i > R) return 0;
	if(i <= L && R <= j)return stree[p];
	int mid = (L+R)/2;
	int left = rmq(i,j,L, mid, 2*p);
	int right = rmq(i,j,mid+1, R, 2*p+1);
	return left+right;
}

int lazy_update(int i, int j, int L, int R, int p, int val){
	propagate(L,R,p);
	if(j < L || i > R) return 0;
	if(i <= L && R <= j){
		stree[p] += (L-R+1)*val;
		if(L != R){
			lazy[2*p] += ((L+R)/2 - L + 1) * val;
			lazy[2*p+1] += (R - (L+R)/2) * val;
		}
		return stree[p];
	}
	int mid = (L+R)/2;
	int left = lazy_update(i,j,L,mid,2*p, val);
	int right = lazy_update(i,j,mid+1, R, 2*p+1, val);
	stree[p] = left + right;
	return stree[p];
}

void printout(){
	for(int i=0;i<pirates.size();++i){
		printf("%d ", pirates[i]);
	}
	printf("\n");
}

int main(){
	int TC,M,R;
	string str;
	scanf("%d",&TC);
	for(int T=1;T<=TC;++T){
		printf("Case %d:\n", T);
		pirates.clear();
		scanf("%d",&M);
		for(int m=0;m<M;++m){
			cin>>R;
			cin>>str;
			vector<int> c(str.size());
			for(int i = 0; i<str.size(); ++i){
				c[i] = (str[i] == '1') ? 1 : 0;
			}
			for(int i=0;i < R; ++i){
				pirates.insert(pirates.end(), c.begin(), c.end());
			}
		}
		N = pirates.size();

		printout();

		stree = vector<int>(4*N, 0);
		lazy = vector<int>(4*N, 0);
		build(0, N-1, 1);
		int Q,q=0,s,t,prev = 0;
		cin>>Q;
		for(int k=0;k<Q;++k){
			cin>>str;
			cin>>s>>t;
			if(str[0] == 'F' || str[0] == 'E'){
				int to = (str[0] == 'F') ? 1 : 0;
				int dif = (to == 1) ? 1 : -1;
				bool ins = (pirates[s] == to) ? false : true;
				prev = s;
				for(int i=s+1; i<=t; ++i){
					if(pirates[i] == to){
						if(ins == true){
							
							lazy_update(prev, i-1, 0, N-1, 1, dif);
							ins = false;
						}
					} else {
						if(ins == false){
							prev = i;
							ins = true;
						}
						pirates[i] = to;
					}
				}
				//if still in streak
				if(ins){
					lazy_update(prev, t, 0, N-1, 1, dif);
				}
			}	else if(str[0] == 'I'){
				int prev_to = (pirates[s] == 1) ? 0 : 1;
				int to;
				int idx=s;
				pirates[s] = prev_to;
				for(int i = s+1; i<= t+1; ++i){
					if(i == t+1){
						int dif = (prev_to == 1) ? 1 : -1;
						lazy_update(idx, i-1, 0, N-1, 1, dif);
						break;
					}
					to = (pirates[i] == 1) ? 0 : 1;
					if(to != prev_to){
						int dif = (prev_to == 1) ? 1 : -1;
						lazy_update(idx, i-1, 0, N-1, 1, dif);
						prev_to = to;
						idx = i;
					}
					pirates[i] = to;
				}
			} else {
				int ans = rmq(s, t, 0, N-1, 1);
				printf("Q%d: %d\n", ++q, ans);
			}

			printout();

		}
	}
	return 0;
}
