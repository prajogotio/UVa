#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int a[300];
	int TC;
	scanf("%d",&TC);
	while(TC--){
		fill(a,a+300,0);
		int L;
		scanf("%d",&L);
		getchar();
		while(L--){
			unsigned char c;
			int d;
			c=getchar();
			scanf("%d",&d);
			a[c]=d;
			//printf("%c %d\n",c,d);
			//printf("%d %d\n",int(c),a[c]);
			getchar();
		}
		int M;
		long long tot=0;
		scanf("%d",&M);
		getchar();
		while(M){
			unsigned char x = getchar();
			if(x== (unsigned char) '\n' 
				|| x== (unsigned char) EOF)
				--M;
			//printf("%d",M);
			tot+= (long long) a[x];
		}
		printf("%lld.%02lld$\n",tot/100,tot%100);
	}
	return 0;
}