#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

string s;
int w[25][3];
int T = 24;
int main(){
	int N;
	while(scanf("%d",&N),N!=0){
		int cnt = 0;
		int tot = 0;
		for(int i=0;i<N;++i){
			cin >> s;
			if(s == "Canada") {
				scanf("%d%d%d",&w[T][0],&w[T][1],&w[T][2]);
				tot += w[T][0] + w[T][1] + w[T][2];
			} else {
				scanf("%d%d%d",&w[cnt][0],&w[cnt][1],&w[cnt][2]);
				tot += w[cnt][0] + w[cnt][1] + w[cnt][2];
				++cnt;
			}
		}
		bool completed = false;
		for(int i=1;i<=3;++i){
			for(int j=1;j<=3;++j){
				for(int k=1;k<=3;++k){
					int a[3];
					a[0] =a[1]=a[2]= 1;
					for(int x=0;x<i;++x){
						a[0] *= tot;
					}
					for(int x=0;x<j;++x){
						a[1] *= tot;
					}
					for(int x=0;x<k;++x){
						a[2] *= tot;
					}
					int cmp = a[0]*w[T][0] + a[1]*w[T][1] + a[2]*w[T][2];
					bool ok = true;
					for(int c=0;c<cnt;++c){
						int cur = a[0]*w[c][0] + a[1]*w[c][1] + a[2]*w[c][2];
						if(cur > cmp) {
							ok = false;
							break;
						}
					}
					if(ok){
						printf("Canada wins!\n");
						completed = true;
						break;
					}
				}
				if(completed)break;
			}
			if(completed)break;
		}
		if(!completed){
			printf("Canada cannot win.\n");
		}
	}
	return 0;
}