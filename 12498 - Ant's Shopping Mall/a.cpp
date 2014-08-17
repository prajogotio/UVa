#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int m[53][53];
int M, N;
int main(){
	int TC, temp, low, T=1;
	scanf("%d", &TC);
	while(TC--){
		printf("Case %d: ", T++);

		scanf("%d %d", &M, &N);
		for(int i=0;i<M;++i)
			for(int j=0;j<N;++j)
				scanf("%1d", &m[i][j]);
		/*
		for(int i=0;i<M;++i){
			for(int j=0;j<N;++j)
				printf("%d", m[i][j]);
			printf("\n");
		}
		*/
		low = (int) 1e9;
		for(int i=0;i<N;++i){
			temp = 0;
			for(int j=0;j<M;++j){
				if(m[j][i] == 1){
					int right = (int) 1e9;
					for(int k=i+1;k<N;++k){
						if(m[j][k] == 0){
							right = k-i;
							break;
						}
					}
					int left = (int) 1e9;
					for(int k=i-1;k>=0;--k){
						if(m[j][k] == 0){
							left = i-k;
							break;
						}
					}
					temp += min(left, right);
					if(temp >= (int) 1e9) break;
				}
			}
			low = min(low, temp);
		}
		if(low == (int) 1e9) printf("-1\n");
		else printf("%d\n", low);
	}
	return 0;
}