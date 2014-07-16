#include <algorithm>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	string str;
	while(cin>>str, str!="#"){
		if(next_permutation(str.begin(),str.end())){
			printf("%s\n",str.c_str());
		}
		else
			printf("No Successor\n");
	}
	return 0;
}