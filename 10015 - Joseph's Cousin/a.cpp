#include <cstdio>
#include <vector>
using namespace std;

int main(){
	int a[100005]={0};
	for(int i=2;i<=350;++i){
		for(int j=2;j<=100000/i;++j){
			a[i*j]=1;
		}
	}
	int prime[5000];
	int k=2;
	for(int i=0;i<4000;++i){
		while(a[k]==1)++k;
		prime[i]=k;
		++k;
	}
	/*for(int i=0;i<4000;++i){
		printf("%d\n",prime[i]);
	}*/
	int N;
	while(1){
		scanf("%d",&N);
		if(N==0)break;
		vector<int> p;
		for(int i=1;i<=N;++i)p.push_back(i);
		int cur=-1,nP=N;
		for(int i=0;i<N-1;++i){
			cur=(cur+prime[i])%nP;
			p.erase(p.begin()+cur);
			--cur;
			--nP;
		}
		printf("%d\n",p[0]);
	}
	return 0;
}