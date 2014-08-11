#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int s[504];

int main(){
	int TC, N;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d", &N);
		for(int i=0;i<N;++i){
			scanf("%d", &s[i]);
		}
		int dist = (int) 1e9;
		for(int i=0;i<N; ++i){
			int temp = 0;
			for(int j=0;j<N;++j){
				temp += abs(s[j] - s[i]);
			}
			dist = min(temp, dist);
		}
		printf("%d\n", dist);
	}
	return 0;
}