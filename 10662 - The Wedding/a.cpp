#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int T[21], R[21], H[21], tr[21][21], rh[21][21], ht[21][21];
int t, r, h;
int main(){
	int ans, temp, ai, aj, ak;
	while(scanf("%d %d %d", &t, &r, &h) != EOF){
		for(int i=0;i<t;++i){
			scanf("%d", &T[i]);
			for(int j=0;j<r;++j){
				scanf("%d", &tr[i][j]);
			}
		}
		for(int i=0;i<r;++i){
			scanf("%d", &R[i]);
			for(int j=0;j<h;++j){
				scanf("%d", &rh[i][j]);
			}
		}
		for(int i=0;i<h;++i){
			scanf("%d", &H[i]);
			for(int j=0;j<t;++j){
				scanf("%d", &ht[i][j]);
			}
		}
		ans = (int) 1e9;

		for(int i=0;i<t;++i)
			for(int j=0;j<r;++j)
				for(int k=0;k<h;++k)
				{
					//printf("%d %d %d\n%d %d %d\n\n", i, j, k, tr[i][j], rh[j][k], ht[k][i]);
					if(!tr[i][j] && !rh[j][k] && !ht[k][i]){
						temp = T[i] + R[j] + H[k];
						if(ans > temp){
							ans = temp;
							ai = i; aj = j; ak = k;
						} 
					}
				}

		if(ans == (int) 1e9) printf("Don't get married!\n");
		else printf("%d %d %d:%d\n", ai, aj, ak, ans);
	}
	return 0;

}