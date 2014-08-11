#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char bin[103][6];

void rd(int city, string str){
	int i=0;
	int sz = str.size();
	while(i < sz){
		char a = str[i], b = str[i+2];
		int k;
		if(a == 'r'){
			k=0;
		}else if(a == 'o'){
			k=1;
		}else if(a == 'y'){
			k=2;
		}else if(a == 'g'){
			k=3;
		}else if(a == 'b'){
			k=4;
		}
		bin[city][k] = b;
		i += 4;
	}
}

int main(){
	string str;
	int city, tot, minim, idx;
	while(getline(cin, str)){
		city = 0; minim = (int) 1e9;
		if(str[0] == '#') break;
		rd(city++, str);
		while(getline(cin, str)){
			if(str[0] == 'e') break;
			rd(city++, str);
		}
		for(int i=0;i<city;++i){
			tot = 0;
			for(int j=0;j<city;++j){
				if(i == j) continue;
				for(int k=0;k<5;++k){
					if(bin[i][k] != bin[j][k]) ++tot;
				}
			}
			if(tot < minim){
				idx = i;
				minim = tot;
			}
		}
		printf("%d\n", idx+1);
	}
	return 0;
}

