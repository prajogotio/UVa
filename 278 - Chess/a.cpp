#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	getchar();
	for(int t=0;t<T;++t){
		char c = getchar();
		int m,n;
		scanf("%d%d",&m,&n);
		getchar();
		int nk = m*n/2;
		int nK = 1;
		int nQ = min(m,n);
		int nR = min(m,n);
		if(m%2!=0 && n%2!=0)++nk;
		if(m%2==1)nK*=(m/2+1);else nK*=m/2;
		if(n%2==1)nK*=(n/2+1);else nK*=n/2;
		if(m==3&&n==3)nQ=2;
		if(c=='k')printf("%d\n",nk);
		if(c=='K')printf("%d\n",nK);
		if(c=='Q')printf("%d\n",nQ);
		if(c=='r')printf("%d\n",nR);
	}
	return 0;
}