#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string str;
	while(getline(cin,str)){
		int a[200]={0};
		int len = str.size();
		int M=0;
		for(int i=0;i<len;++i){
			if(isalpha(str[i])) ++a[str[i]-'A'];
		}
		for(int i=0;i<200;++i)
			M=max(a[i],M);
		for(int i=0;i<200;++i)
			if(a[i]==M)printf("%c",char('A'+i));
		printf(" %d\n",M);
	}
	return 0;
}