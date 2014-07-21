#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int N;
string str;
int main(){
	int TC,tc=1;
	scanf("%d",&TC);
	for(tc=1;tc<=TC;++tc){
		printf("Case %d: ",tc);
		scanf("%d",&N);
		cin >> str;
		int i=0,k=0;
		while(i < N){
			if(str[i] == '.'){
				++k;
				i += 3;
			} else {
				++i;
			}
		}
		printf("%d\n",k);
	}
	return 0;
}