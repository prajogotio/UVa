#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int N;
	int i=0;
	vector<int> a;
	while(scanf("%d",&N)!=EOF){
		++i;
		a.push_back(N);
		sort(a.begin(),a.end());
		if(i%2==0){
			printf("%d\n",(a[i/2]+a[i/2-1])/2);
		} else
			printf("%d\n",a[i/2]);
	}
	return 0;
}