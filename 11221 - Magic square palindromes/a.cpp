#include <cstdio>
#include <string>
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	getchar();
	for(int TC=1;TC<=T;++TC){
		printf("Case #%d:\n",TC);
		string str;
		getline(cin,str);
		string dstr;
		int len=str.size();
		for(int i=0;i<len;++i){
			if(isalpha(str[i]))
				dstr+=str[i];
		}
		//cout<<dstr<<endl;
		int x=dstr.size();
		int K=0;
		while(K*K<x){
			++K;
		}
		//printf("%d %d\n",K,x);
		if(K*K!=x){
			printf("No magic :(\n");
			continue;
		}
		bool got_magic=true;
		for(int i=0;i<K;++i){
			for(int j=0;j<K;++j){
				int ri = K-i-1,rj = K-j-1;
				if(dstr[i*K+j]!=dstr[i+j*K]
					|| dstr[ri*K+rj] != dstr[ri+rj*K]
					|| dstr[ri*K+rj] != dstr[i*K+j]){
					printf("No magic :(\n");
					got_magic=false;
					break;
				}
			}
			if(!got_magic)break;;
		}
		if(!got_magic)continue;
		printf("%d\n",K);
	}
	return 0;
}
