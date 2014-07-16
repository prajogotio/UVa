#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N;
	while(scanf("%d",&N)!=EOF){
		int i= 1<<N;
		vector<int> v;
		while(i--){
			int k;
			scanf("%d",&k);
			v.push_back(k);
		}
		vector<int> w;
		int lim = 1<<N;
		for(int k=0;k<lim;++k){
			int tot=0;
			for(int p=0;p<N;++p){
				int j = (k ^ (1<<p));
				tot+=v[j];
			}
			w.push_back(tot);
		}
		int R=0;
		for(int k=0;k<lim;++k){
			int temp=0;
			for(int p=0;p<N;++p){
				int j = (k ^ (1<<p));
				if(temp<w[j])temp=w[j];
			}
			temp+=w[k];
			if(R<temp)R=temp;
		}
		printf("%d\n",R);
	}
	return 0;
}