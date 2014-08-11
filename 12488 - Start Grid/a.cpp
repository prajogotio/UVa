#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int s[26];
int f[26];
int pos[26];
int N;
int main(){
	while( cin >> N){
		for(int i=1;i<=N;++i){
			scanf("%d", &s[i]);
			pos[s[i]] = i;
		}
		for(int i=1;i<=N;++i){
			scanf("%d", &f[i]);
		}
		int tot = 0;
		for(int i=1;i<=N;++i){
			int k = pos[f[i]];
			for(int j=k; j>i;--j){
				int u = s[j];
				int v = s[j-1];
				pos[v] = j;
				pos[u] = j-1;
				swap(s[j], s[j-1]);
				++tot;
			}
		}
		//for(int i=1;i<=N;++i) printf("%d ", s[i]); printf("\n");
		printf("%d\n", tot);
	}
	return 0;
}