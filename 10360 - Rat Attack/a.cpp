#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int m[1025][1025];
pair<int,int> p[20003];
int val[20003];
int D, M;

void clr(){
	for(int i=0;i<1025;++i)
		for(int j=0;j<1025;++j)
			m[i][j] = 0;
}

int main(){
	int TC, x, y, pop, x1, x2, y1, y2, ans;
	scanf("%d", &TC);
	while(TC--){
		scanf(" %d %d", &D, &M);
		clr();
		for(int i=0;i<M;++i){
			scanf("%d %d %d", &x, &y, &pop);
			p[i] = make_pair(x,y);
			val[i] = pop;
		}

		for(int i=0;i<M;++i){
			x = p[i].first; y = p[i].second; pop = val[i];
			x1 = x - D; if (x1<0) x1 = 0;
			x2 = x + D; if (x2>1024) x2 = 1024;
			y1 = y - D; if (y1<0) y1 = 0;
			y2 = y + D;	if (y2>1024) y2 = 1024;
			for(int j=x1; j<=x2; ++j)
				for(int k=y1; k<=y2; ++k)
					m[j][k] += pop;
		}
		ans = 0;
		for(int i=0;i<1024;++i)
			for(int j=0;j<1024;++j)
				if(ans < m[i][j]){
					ans = m[i][j];
					x = i; y = j;
				}
		printf("%d %d %d\n", x, y, ans);
	}

	return 0;
}