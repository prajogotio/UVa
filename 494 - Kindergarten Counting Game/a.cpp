#include <cstdio>
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main(){
	string str;
	while(getline(cin,str)){
		int len=str.size();
		int i=0,word=0;
		bool inword=false;
		while(i<len){
			if(isalpha(str[i]) && !inword){
				++word;
				inword=true;
			}else if(!isalpha(str[i]) && inword){
				inword=false;
			}
			++i;
		}
		printf("%d\n",word);
	}
	return 0;
}