#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string p[6];
string q[6];
vector<vector<char> > pcode;
int comb[5];
void dfs(int idx, int k){
	if(idx == 5){
		return;
	}
	int tot = 1;
	for(int i = idx+1; i < 5; ++i){
		tot *= pcode[i].size();
	}
	for(int i = 1; i<= pcode[idx].size()+1; ++i){
		if(tot * i >= k){
			comb[idx] = i;
			dfs(idx+1, k-tot*(i-1));
			return;
		}
	}
}

int main(){
	int TC,K;
	scanf("%d",&TC);
	while(TC--){
		scanf("%d",&K);
		pcode.clear();
		pcode.assign(6,vector<char>());
		for(int i=0;i<6;++i){
			cin>>p[i];
		}
		for(int i=0;i<6;++i){
			cin>>q[i];
		}
		for(int i=0;i<5;++i){
			for(int j=0;j<6;++j){
				for(int k=0;k<6;++k){
					if(p[k][i] == q[j][i]){
						if(find(pcode[i].begin(), pcode[i].end(), q[j][i]) == pcode[i].end()){
							pcode[i].push_back(q[j][i]);
							//cout << q[j][i] << endl;
						}
						break;
					}
				}
			}
		}
		int mtot = 1;
		for(int i=0;i<5;++i){
			mtot *= pcode[i].size();
			sort(pcode[i].begin(), pcode[i].end());
		}
		if (mtot < K) {
			printf("NO\n");
			continue;
		}
		dfs(0,K);
		for(int i=0;i<5;++i){
			//cout << pcode[i].size();
			//cout << comb[i];
			cout << pcode[i][comb[i]-1];
		}
		printf("\n");
	}
	return 0;
}