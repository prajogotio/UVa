#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int h[10003];

int main(){
	int L,H,R;
	int s=999999, e=0;
	for(int i=0;i<10003;++i) h[i] = 0;
	while(scanf("%d %d %d", &L, &H, &R) != EOF){
		s = min(s, L);
		e = max(e, R);
		for(int i=L;i<R;++i)
			h[i] = max(h[i], H);
	}
	/*
	for(int i=s;i<=e;++i)
		printf("%d ", h[i]);
	printf("\n");
	*/
	int prev = h[s];
	printf("%d %d ", s, h[s]);
	for(int i=s+1;i<e;++i){
		if(prev != h[i]){
			//if(h[i] > prev) 
			printf("%d %d ", i, h[i]);
			//else printf("%d %d ", i-1,h[i]);
			prev = h[i];
		}
	}
	printf("%d 0\n", e);
	return 0;
}