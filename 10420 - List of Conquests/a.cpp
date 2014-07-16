#include <cstdio>
#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	getchar();
	string names[2007];
	for(int i=0;i<N;++i){
		getline(cin,names[i]);
	}
	sort(names,names+N);
	string prev;int ctr=0;
	for(int i=0;i<N;++i){
		int j=0;
		while(isalpha(names[i][j])) ++j;
		string cur=names[i].substr(0,j);
		if(prev == cur){
			++ctr;
		}else{
			if(i!=0) printf("%s %d\n",prev.c_str(), ctr);
			ctr=1;
			prev=cur;
		}
	}
	printf("%s %d\n",prev.c_str(), ctr);
	return 0;
}