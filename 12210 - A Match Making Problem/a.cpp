#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int b[100005];
int main(){
	int n,m,tc=1;
	while(scanf("%d %d",&n,&m), n!=0 && m!=0){
		printf("Case %d: ",tc++);
		for(int i=0;i<n;++i){
			scanf("%d",&b[i]);
		}
		int k;
		for(int i=0;i<m;++i){
			scanf("%d",&k);
		}
		sort(b, b+n);
		int d = n-m;
		if(d <= 0){
			printf("0\n");
		} else {
			printf("%d %d\n", d,b[0]);
		}
	}
	return 0;
}