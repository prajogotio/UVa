#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<string> a;
vector<string> b;

int main(){
	int m,n;
	while(scanf("%d%d",&n,&m), m||n){
		a.clear(),b.clear();
		int M=m,N=n;
		string s;
		while(N--){
			cin>>s;
			a.push_back(s);
		}
		while(M--){
			cin>>s;
			b.push_back(s);
		}
		int i=0;
		while(i<4){
			if(i!=0){
				printf(" ");
				vector<string> c;
				for(int j=0;j<m;++j){
					string str;
					for(int k=0;k<m;++k){
						str+=b[m-1-k][j];
					}
					c.push_back(str);
				}
				b=c;
			}
			/*
			printf("\n");
			for(int p=0;p<m;++p){
				for(int q=0;q<m;++q)
					printf("%c",b[p][q]);
				printf("\n");
			}
			*/
			int K=0;
			for(int j=0;j<=n-m;++j){
				for(int k=0;k<=n-m;++k){
					bool same=true;
					for(int p=j;p<j+m;++p){
						for(int q=k;q<k+m;++q){
							if(a[p][q]!=b[p-j][q-k]){
								same=false;
								break;
							}
						}
						if(!same)break;
					}
					if(same)++K;
				}
			}
			printf("%d",K);
			++i;
		}
		printf("\n");
	}
	return 0;
}