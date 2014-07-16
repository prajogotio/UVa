#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int N;
	int i=0;
	vector<int> a;
	while(scanf("%d",&N)!=EOF){
		++i;
		a.push_back(N);
		if(i%2==1){
			nth_element(a.begin(), a.begin()+i/2,a.end());
			printf("%d\n",a[i/2]);
		}else{
			int tot=0;
			nth_element(a.begin(), a.begin()+i/2,a.end());
			tot+=a[i/2];
			nth_element(a.begin(), a.begin()+i/2-1,a.end());
			tot+=a[i/2-1];
			printf("%d\n",tot/2);
		}
	}
	return 0;
}