#include <cstdio>

int main(){
	int sz;
	long long p;
	while(scanf("%d%lld",&sz,&p), sz||p){
		if(p==1){
			printf("Line = %d, column = %d.\n",(sz+1)/2,(sz+1)/2);
			continue;
		}
		int k=0;
		int lo=0,hi=100000;
		while(lo<=hi){
			int mid = (lo+hi)/2;
			long long llmid = mid;
			long long comp = (2*llmid+1) * (2*llmid+1);
			if(comp <= p){
				lo = mid+1;
			} else {
				hi = mid -1;
			}
		}
		k = lo;
		if( (2*(long long)k-1) * (2*(long long)k -1) == p){
			printf("Line = %d, column = %d.\n",(sz+1)/2+k-1,(sz+1)/2+k-1);
			continue;
		}
		long long d = 2*(long long)k;
		long long m = p - (2*(long long)k -1) * (2*(long long)k -1);
		int a = int(m/d);
		int  b = int(m%d);
		if(a==0){
			printf("Line = %d, column = %d.\n",(sz+1)/2+k,(sz+1)/2+k-b);
		} else if( a == 1){
			printf("Line = %d, column = %d.\n",(sz+1)/2+k-b,(sz+1)/2-k);
		} else if( a == 2){
			printf("Line = %d, column = %d.\n",(sz+1)/2-k,(sz+1)/2-k+b);
		} else {
			printf("Line = %d, column = %d.\n",(sz+1)/2-k+b,(sz+1)/2+k);
		}
	}
	return 0;
}
