#include <cstdio>
#include <algorithm>
using namespace std;

int a[6] = {0,1,2,3,4,5};

int main(){
	printf("012345 012345\n");
	while(next_permutation(a, a+6)){
		printf("012345 ");
		for(int i=0;i<6;++i){
			printf("%d", a[i]);
		}
		printf("\n");
	}
	return 0;
}