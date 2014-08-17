#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int a[103][103];
int dp[103][103];
int N,M;

int main(){
	while(scanf("%d", &N), N!=0){
		scanf("%d", &M);
		for(int i=0;i<N;++i)
			for(int j=0;j<M;++j)
			{
				dp[i][j] = 0;
				scanf("%1d", &a[i][j]);
				dp[i][j] += a[i][j];

				if(i-1>=0) dp[i][j] += dp[i-1][j];
				if(j-1>=0) dp[i][j] += dp[i][j-1];
				if(i-1>=0 && j-1>=0) dp[i][j] -= dp[i-1][j-1];
			}
		/*
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j)
				printf("%d ", dp[i][j]);
			printf("\n");
		}
		*/
		int cnt = 0;
		for(int x1=0;x1<N;++x1)
			for(int y1=0;y1<M;++y1)
				for(int x2=x1;x2<N;++x2)
					for(int y2=y1;y2<M;++y2)
					{
						int temp = dp[x2][y2];
						if(x1 > 0) temp -= dp[x1-1][y2];
						if(y1 > 0) temp -= dp[x2][y1-1];
						if(x1 > 0 && y1 > 0) temp += dp[x1-1][y1-1];
						//printf("%d\n", temp);
						if(temp == (y2-y1+1) * (x2-x1+1) ) ++cnt;
					}
		//printf("=====\n");
		printf("%d\n", cnt);
	}
}
