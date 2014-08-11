#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int N, K;
string name;

int main(){
	int TC, tot, T=1;
	scanf("%d", &TC);
	while(TC--){
		printf("Case %d: ", T++);
		scanf("%d %d", &N, &K);
		cin >> name;
		tot = 0;
		for(int i=0;i<N;++i){
			for(int j=i-1;j>=0 && j >= i-K; --j){
				if(name[i] == name[j]){
					++tot;
					break;
				}
			}
		}
		printf("%d\n", tot);
	}
	return 0;
}