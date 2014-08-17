#include <iostream>
#include <cstdio>
using namespace std;

int guess[13][4], c[13], d[13], a[4], state[4], used[4], ans[4];
int N;

int main(){
	int TC, cnt, curx, cury;
	bool can;
	scanf("%d", &TC);
	while( TC-- ){
		scanf("%d", &N);
		for(int i=0;i<N;++i){
			for(int j=0;j<4;++j){
				scanf(" %1d", &guess[i][j]);
			}
			scanf(" %d/%d", &c[i], &d[i]);
		}
		cnt = 0;
		for(a[0] = 0; a[0] <10;++a[0])
			for(a[1] = 0; a[1] < 10; ++a[1])
				for(a[2] = 0; a[2] < 10; ++a[2])
					for(a[3] = 0; a[3] <10; ++a[3])
					{
						can = true;
						for(int k=0;k<N;++k){
							for(int i=0;i<4;++i) {
								state[i] = 1;
								used[i] = 1;
							}
							curx = cury = 0;
							for(int i=0;i<4;++i){
								if(a[i] == guess[k][i]) {
									++ curx;
									state[i] = 0;
									used[i] = 0;
								}
							}

							for(int i=0;i<4;++i){
								for(int j=0;j<4;++j){
									if(state[i] && used[j]){
										if(a[i] == guess[k][j]){
											++cury;
											state[i] = 0;
											used[j] = 0;
										}
									}
								}
							}
							if(curx != c[k] || cury != d[k]) {
								can = false;
								break;
							}
						}
						if(can) {
							++cnt;
							for(int i=0;i<4;++i) ans[i] = a[i];
						}
					}
		if(cnt == 1) printf("%d%d%d%d\n", ans[0], ans[1], ans[2], ans[3]);
		else if (cnt == 0) printf("impossible\n");
		else printf("indeterminate\n");
	}
	return 0;
}
