#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

int main(){
	int TC;
	scanf("%d",&TC);
	for(int T=1;T<=TC;++T){
		printf("Case #%d:\n",T);
		string str[10];
		int a[10];
		int M=0;
		for(int i=0;i<10;++i){
			char s[50];
			scanf("%s%d",s,&a[i]);
			str[i]=s;
			if(M<a[i])M=a[i];
		}
		for(int i=0;i<10;++i){
			if(a[i]==M){
				printf("%s\n",str[i].c_str());
			}
		}
	}
	return 0;
}