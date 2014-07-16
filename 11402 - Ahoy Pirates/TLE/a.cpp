#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

string str;
string temp;
vector<int> stree;
bool ap[1024005];
bool aq[1024005];


void build(int i, int j, int p){
	if(i==j){
		stree[p] = (str[i] == '1') ? 1 : 0;
		return;
	}
	int mid = (i+j)/2;
	build(i, mid, 2*p);
	build(mid+1, j, 2*p+1);
	int left = stree[2*p];
	int right = stree[2*p+1];
	stree[p] = left+right;
}

int rmq(int i, int j, int L, int R, int p){
	if(i > R || j < L) return -1;
	if(i <= L && R <= j) return stree[p];
	int mid = (L+R)/2;
	int left = rmq(i,j,L,mid,2*p);
	int right = rmq(i,j,mid+1,R,2*p +1);
	if(left == -1) return right;
	if(right == -1) return left;
	return left+right;
}

void update(int i, int L, int R, int p, int val){
	if(val == 0) return;
	if(L == R){
			stree[p] += val;
			return;
	}
	//printf("%d %d %d %d %d\n",i,L,R,p,val);
	stree[p] += val;
	int mid = (L+R)/2;
	if(mid >= i) return update(i,L,mid,2*p,val);
	else
	 return update(i,mid+1,R,2*p+1,val);
}

int main(){
	int TC,R;
	scanf("%d",&TC);
	for(int T=1;T<=TC;++T){
		str.clear();
		printf("Case %d:\n", T);
		int M,Q,q=0,s,t;
		cin>>M;
		string pq;
		for(int m=0;m<M;++m){
			cin>>R;
			cin>>pq;
			for(int i=0;i<R;++i)
				str += pq;
		}
		int N = str.size();
		stree = vector<int>(4*N,0);
		build(0, N-1, 1);
		//cout << str << endl;
		//for(int i=1;i<4*N;++i) printf("%d ",stree[i]); printf("\n");
		for(int i=0;i<N;++i){
			int k = (str[i] == '1') ? 1 : 0;
			ap[i] = 1;
			aq[i] = 0;
		}
		cin>>Q;
		string query;
		//temp = str;
		int l=999999999,r=-1;
		for(int k=1;k<=Q;++k){
			cin >> query;
			cin >> s >> t;
			if(query[0] == 'F'){
				//change to 1
				for(int i=s; i<=t;++i){
					//temp[i] = '1';
					aq[i] = 1;
				}
			} else if (query[0] == 'E') {
				//change to 0
				for(int i=s; i<=t; ++i){
					//temp[i] = '0';
					aq[i] = 0;
				}
			} else if (query[0] == 'I') {
				//change to inverse
				for(int i=s;i<=t;++i){
					//temp[i] = (temp[i] == '1') ? '0' : '1';
					aq[i] = (aq[i] == 1) ? 0 : 1;
				}
			} else {
				//return number of 1
				//cout<<temp<<endl;
				for(int i=l;i<=r;++i){
				//	int dif = temp[i] - str[i];
				//	printf("i = %d, dif = %d\n", i, dif);
					int dif = aq[i] - ap[i];
					if(dif != 0){
						ap[i] = aq[i];
					}
					update(i,0,N-1,1,dif);
				}
				//for(int i=1;i<4*N;++i) printf("%d ",stree[i]); printf("\n");
				printf("Q%d: ", ++q);
				cout << rmq(s,t,0,N-1,1) <<endl;
				/*
				cout << "Linear count: ";
				int tot = 0;
				for(int i=s; i <=t; ++i){
					if(aq[i] == 1) ++tot;
				}
				cout << tot << endl;
				*/
				//str = temp;
				l = 999999999;
				r = -1;
				continue;
			}
			if(l > s) l = s;
			if(r < t) r = t;
		}
		//cout << str << endl;
	}
	cout<< ((double)clock() / CLOCKS_PER_SEC)<<endl;
	return 0;
}