#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[105];
int b[105];

int n,d,r;
int main(){
	while(scanf("%d %d %d", &n, &d, &r), n!=0 && d!=0 && r!=0){
		for(int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;++i){
			scanf("%d",&b[i]);
		}
		sort(a, a+n);
		sort(b, b+n);
		int tot = 0;
		for(int i=0;i<n;++i){
			if(a[i] + b[n-i-1] > d)
				tot += a[i] + b[n-i-1] - d;
		}
		printf("%d\n",tot*r);
	}
	return 0;
}