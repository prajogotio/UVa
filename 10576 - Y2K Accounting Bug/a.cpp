#include <iostream>
#include <cstdio>
using namespace std;
int lim = 1<<12;

int main(){
	int s,d;
	while(scanf("%d %d", &s, &d)!=EOF){
		int max = -1;
		for (int i=0;i<lim;++i){
			int arr[12];
			for(int j=0;j<12;++j){
				if(i & (1<<j)){
					arr[j] = s;
				} else {
					arr[j] = -d;
				}
			}
			bool good = true;
			for(int j=4; j<12; ++j){
				int tot = arr[j] + arr[j-1] + arr[j-2] + arr[j-3] + arr[j-4];
				if (tot > 0) {
					good = false;
					break;
				}
			}
			if(!good) continue;
			int ret = 0;
			for(int j=0;j<12;++j){
				ret+=arr[j];
			}
			if (max < ret) max = ret;
		}
		if(max < 0){
			printf("Deficit\n");
		} else {
			printf("%d\n", max);
		}
	}
	return 0;
}