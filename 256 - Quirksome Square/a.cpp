#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	for(int i=0;i<=99999999;++i){
		int a = i % 10000;
		int b = i/10000;
		long long c = a+b;
		c = c*c;
		if( c == (long long) i){
			printf("%d\n", i);
		}
	}
	return 0;
}