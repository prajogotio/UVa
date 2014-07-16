#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> lazy; //1 set, 2 clear, 3 invert
vector<int> pirates;
vector<int> stree;
int N;
int tset(int,int,int,int,int);
int tclear(int,int,int,int,int);
int tinv(int,int,int,int,int);

int build(int i,int j,int p){
	//printf("%d %d %d\n", i, j, p);
	if(i == j){
		stree[p] = pirates[i];
		return stree[p];
	}
	int mid = (i+j)/2;
	int left = build(i, mid, 2*p);
	int right = build(mid+1, j, 2*p+1);
	stree[p] = left+right;
	return stree[p];
}

void propagate(int p, int L, int R){
		if(lazy[p] != 0){
		if(lazy[p] == 1){
			stree[p] = R-L + 1;
			if(L!= R){
				lazy[2*p] = 1;
				lazy[2*p+1] = 1;
			}
		} else if(lazy[p] == 2){
			stree[p] = 0;
			if(L!=R){
				lazy[2*p] = 2;
				lazy[2*p+1] = 2;
			}
		} else if(lazy[p] = 3){
			stree[p] = (R-L+1) - stree[p];
			if(L!=R){
				if(lazy[2*p] == 1){
					lazy[2*p] = 2;
				} else if(lazy[2*p] == 2){
					lazy[2*p] = 1;
				} else if(lazy[2*p] == 3){
					lazy[2*p] = 0;
				} else{
					lazy[2*p] = 3;
				}

				if(lazy[2*p+1] == 1){
					lazy[2*p+1] = 2;
				} else if(lazy[2*p+1] == 2){
					lazy[2*p+1] = 1;
				} else if(lazy[2*p+1] == 3){
					lazy[2*p+1] = 0;
				} else {
					lazy[2*p+1] = 3;
				}
			}
		}
		lazy[p] = 0;
	}
}

int rmq(int i, int j, int L, int R, int p){
	//printf("%d %d %d %d %d\n", i, j, L, R, p);
	propagate(p,L,R);
	if(j < L || i > R) return 0;
	if(i <= L && R <= j){
		return stree[p];
	}
	int mid = (L+R)/2;
	int left = rmq(i,j,L, mid, 2*p);
	int right = rmq(i,j,mid+1,R,2*p+1);
	return left + right;
}


int tset(int i, int j, int L, int R, int p){
	propagate(p,L,R);
	//printf("set %d %d %d %d %d\n", i,j,L,R,p);
	//set does not need to check lazy array since it will override the effect
	if(j < L || R < i) return stree[p];
	if(i <= L && R <= j){
		stree[p] = (R-L+1);
		if (L != R){
			lazy[2*p] = 1;
			lazy[2*p+1] = 1;
		}
		return stree[p];
	}
	int mid = (L+R)/2;
	int left = tset(i, j, L, mid, 2*p);
	int right = tset(i, j, mid+1, R, 2*p + 1);
	stree[p] = left + right;
	return left + right;
}

int tclear(int i, int j, int L, int R, int p){
	propagate(p,L,R);
	//printf("clear %d %d %d %d %d\n", i,j,L,R,p);
	if(j < L || R < i) return stree[p];
	if(i <= L && R <= j){
		stree[p] = 0;
		if(L != R){
			lazy[2*p] = 2;
			lazy[2*p+1] = 2;
		}
		return stree[p];
	}
	int mid = (L+R)/2;
	int left = tclear(i,j,L,mid,2*p);
	int right = tclear(i,j,mid+1,R,2*p+1);
	stree[p] = left + right;
	return stree[p];
}

int tinv(int i, int j, int L, int R, int p){
	//printf("inv %d %d %d %d %d\n", i,j,L,R,p);
	propagate(p,L,R);
	if(j < L || i > R) return stree[p];
	if(i <= L && R <= j){
		stree[p] = (R-L+1) - stree[p];
		if(L != R){
			if(lazy[2*p] == 1){
				lazy[2*p] = 2;
			} else if(lazy[2*p] == 2){
				lazy[2*p] = 1;
			} else if(lazy[2*p] == 3){
				lazy[2*p] = 0;
			} else{
				lazy[2*p] = 3;
			}

			if(lazy[2*p+1] == 1){
				lazy[2*p+1] = 2;
			} else if(lazy[2*p+1] == 2){
				lazy[2*p+1] = 1;
			} else if(lazy[2*p+1] == 3){
				lazy[2*p+1] = 0;
			} else {
				lazy[2*p+1] = 3;
			}

		}
		return stree[p];
	}
	int mid = (L+R)/2;
	int left = tinv(i,j,L,mid,2*p);
	int right = tinv(i,j,mid+1,R,2*p+1);
	stree[p] = left + right;
	return stree[p];
}

void printout(int K = 28){
	for(int i=1;i<K;++i)
		printf("%2d ", i);
	printf("\n");
	for(int i=1;i<K;++i)
		printf("%2d ", stree[i]);
	cout<<endl;
	for(int i=1;i<K;++i)
		printf("%2d ", lazy[i]);
	cout<<endl;
}

int main(){
	int TC,M,rep,s,t;
	string str;

	scanf("%d",&TC);
	for(int T=1; T<= TC; ++T){
		printf("Case %d:\n", T);
		pirates.clear();
		cin>>M;
		for(int m=0;m<M;++m){
			cin >> rep;
			cin >> str;
			vector<int> c(str.size());
			for(int i=0; i < str.size(); ++i){
				c[i] = (str[i] == '1') ? 1 : 0;
			}
			for(int i=0;i<rep; ++i){
				for(int j=0;j<c.size(); ++j){
					pirates.push_back(c[j]);
				}
			}
		}
		//for(int i=0;i<pirates.size(); ++i) printf("%d ", pirates[i]); printf("\n");
		N = pirates.size();
		stree.assign(4*N,0);
		lazy.assign(4*N,0);
		build(0, N-1, 1);
		//printout();
		int Q,q=0;
		scanf("%d",&Q);
		//for(int i=0;i<N;++i) printf("%d ", pirates[i]); printf("\n");
		for(int k=0;k<Q;++k){
			cin>>str;
			cin>>s>>t;
			if(str[0] == 'F'){
				tset(s, t, 0, N-1, 1);
			} else if ( str[0] == 'E'){
				tclear(s,t,0,N-1,1);
			} else if(str[0] == 'I'){
				tinv(s,t,0,N-1,1);
			} else {
				printf("Q%d: %d\n", ++q, rmq(s,t,0,N-1,1));
			}
			//cout<<str << " " << s << "," << t <<endl;
			//printout();
		}
	}
	return 0;
}