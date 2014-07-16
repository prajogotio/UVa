#include <vector>
#include <cstdio>
using namespace std;

int main(){
	while(1){
		int k;
		scanf("%d",&k);
		if(k==0)break;

		for(int m=1;m<100000000;++m){
			vector<int> v;
			for(int i=0;i<2*k;++i)v.push_back(i);
			int i=-1;
			int b=k;
			int N=2*k;
			bool found=false;
			//printf("%d\n",m);
			while(1){
				i=(i+m)%(N);
				if(v[i]<k){
					if(b==0)
						found = true;
					break;
				}
				--b;
				v.erase(v.begin()+i);
				--N;
				--i;
			//	for(int i=0;i<N;++i)printf("%d ",v[i]);printf("\n");
			}
			if(found){
				printf("%d\n",m);
				break;
			}
		}
	}
	return 0;
}