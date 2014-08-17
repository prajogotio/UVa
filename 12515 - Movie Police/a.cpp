#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
string m[1003], c[503];
int main(){
	int M, C, mini, lim, sz, tmp, cur, minv;
	scanf("%d %d", &M, &C);

	for(int i=0;i<M;++i){
		cin >> m[i];
	}
	for(int i=0;i<C;++i){
		cin >> c[i];
	}
	for(int i=0;i<C;++i){
		mini=-1;
		minv = (int) 1e9;
		sz = c[i].size();
		for(int j=0;j<M;++j){
			if(m[j].size() < sz) continue;
			lim = m[j].size() - sz;
			cur = (int) 1e9;
			for(int k=0;k<= lim;++k){
				tmp = 0;
				for(int t=0;t<sz;++t){
					if(m[j][t+k] != c[i][t]) ++ tmp;
				}
				cur = min(cur, tmp);
			}
			if(minv > cur){
				minv=cur;
				mini=j;
			}
		}
		printf("%d\n", mini+1);
	}
	return 0;
}