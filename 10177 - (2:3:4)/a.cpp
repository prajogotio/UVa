#include <iostream>
#include <cstdio>
using namespace std;

typedef long long llong;


int main(){
	int N;
	llong s2,s3,s4,tot;
	while(cin >> N){
		s2=s3=s4=0;
		tot = (N*(N+1))/2;
		for(llong i=1;i<=N;++i){
			s2 += i*i;
			s3 += i*i*i;
			s4 += i*i*i*i;
		}
		printf("%lld %lld %lld %lld %lld %lld\n", s2, tot*tot - s2, s3, tot*tot*tot - s3, s4, tot*tot*tot*tot - s4);
	}
	return 0;
}