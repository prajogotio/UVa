#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
using namespace std;

string str;
string temp;
vector<int> ftree;
int maxval;
int p[1024005];
int q[1024005];

int lsb(int n){
	return n & (-n);
}

int cf(int i){
	if( i <= 0) return 0;
	int ret = 0;
	while (i > 0){
		ret += ftree[i];
		i -= lsb(i);
	}
	return ret;
}

void upd(int i,int val){
	if(val == 0) return;
	while(i <= maxval){
		//printf("%d %d\n", i, val);
		ftree[i] += val;
		i += lsb(i);
	}
}

void build(int N){
	ftree = vector<int>(N+3, 0);
	maxval = N;
	for(int i=1;i<=N;++i){
		if(str[i-1] == '1'){
			upd(i, 1);
		}
	}
}

void ptree(){
	for(int i = 1; i <= maxval; ++i)
		printf("%d ", ftree[i]);
	printf("\n");
}

int main(){
	int TC,M,rep,Q;
	string ins;
	scanf("%d",&TC);
	for(int T=1;T<=TC;++T){
		str.clear(); temp.clear();
		printf("Case %d:\n",T);
		scanf("%d",&M);
		for(int m=0;m<M;++m){
			cin >> rep;
			cin >> ins;
			for(int r=0;r<rep;++r){
				str += ins;
			}
		}
		int sz = str.size();
		build(sz);
		cin >> Q;
		int qq = 0, a, b, l=999999999, r=-1;
		//temp = str;
		for(int i=0;i<sz;++i){
			int k = (str[i] == '1') ? 1 : 0;
			p[i] = q[i] = k;
		}
		//cout << str << endl;
		//ptree();
		for(int k=0;k<Q;++k){
			cin>>ins;
			cin>>a>>b;
			if(ins[0] == 'F'){
				for(int i=a; i<= b; ++i){
					//temp[i] = '1';
					q[i] = 1;
				}
			} else if(ins[0] == 'E'){
				for(int i=a; i<= b; ++i){
					//temp[i] = '0';
					q[i] = 0;
				}
			} else if(ins[0] == 'I'){
				for(int i=a; i<= b;++i){
					//temp[i] = (temp[i] == '1') ? '0' : '1';
					q[i] = (q[i] == 1) ? 0 : 1;
				}
			} else {
				//cout << temp << endl;
				for(int i=l; i <= r; ++i){
					/*
					int diff = temp[i] - str[i];
					if(diff != 0){
						str[i] = temp[i];
					}
					*/
					int diff = q[i] - p[i];
					if( diff != 0){
						p[i] = q[i];
					}
					upd(i+1, diff);
				}
				//ptree();
				printf("Q%d: ", ++qq);
				cout << cf(b+1) - cf(a) << endl;
				/*
				cout << "Linear count: ";
				int tot = 0;
				for(int i=a; i <=b; ++i){
					if(q[i] == 1) ++tot;
				}
				cout << tot << endl;
				*/
				l = 999999999;
				r = -1;
			}
			if(l > a) l = a;
			if(r < b) r = b;
		}
	//	cout << str << endl;
	}
	//cout<< ((double)clock() / CLOCKS_PER_SEC)<<endl;

	return 0;
}

