#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

string sym;
int val[6];
vector<int> stack;

bool check(){
	int sz = 1 << 5;
	int len = sym.size();
	int a,b,c;
	for(int i=0;i<sz;++i){
		for(int j=0;j<5;++j){
			if(i & (1<<j)) val[j] = 1;
			else val[j] = 0;
		}
		for(int j=len-1; j>=0; --j){
			if(sym[j] == 'K' || sym[j] == 'A' || sym[j] == 'C' || sym[j] == 'E'){
				a = stack.back(); stack.pop_back();
				b = stack.back(); stack.pop_back();
				if(sym[j] == 'K'){
					if( a == 1 && b == 1) c = 1;
					else c = 0;
				} else if(sym[j] == 'A'){
					if( a == 1 || b == 1) c = 1;
					else c = 0;
				} else if(sym[j] == 'C'){
					if( a == 1 && b == 0) c = 0;
					else c = 1;
				} else if(sym[j] == 'E'){
					if( (a == b) ) c = 1;
					else c = 0;
				}
				stack.push_back(c);
			} else if(sym[j] == 'N'){
				a = stack.back();
				a = (a+1)%2;
				stack[stack.size()-1] = a;
			} else {
				stack.push_back(val[sym[j] - 'p']);
			}
		}
		if(stack.back() == 0){
			return false;
		}
		stack.pop_back();
	}
	return true;
}

int main(){
	while(cin >> sym){
		if(sym[0] == '0') break;
		stack.clear();
		if( check() ) printf("tautology\n");
		else printf("not\n");
	}
	return 0;
}
				