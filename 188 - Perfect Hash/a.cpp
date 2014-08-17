#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int w[15];
int N;

int main(){
	string str;
	int sz, ctr, C, next;
	while(getline(cin, str)){
		sz = str.size();
		for(int i=0;i<15;++i) w[i] = 0;
		N = 0;
		int state = 0;
		for(int i=0;i<sz;++i){
			if(isalpha(str[i])){
				state = 1;
				w[N] *= 32;
				w[N] += str[i] - 'a' + 1;
			} else if(state == 1){
				++N;
				state = 0;
			}
		}
		if(state == 1) ++N;
		C = (int) 1e9;
		for(int i=0;i<N;++i){
			C = min(C, w[i]);
		}
		while(1){
			next = -1;
			for(int i=0;i<N;++i){
				for(int j=0;j<N;++j){
					if(i == j) continue;
					if( (C/w[i]) % N == (C/w[j]) % N ){
						int temp = min( ((C/w[i]) + 1) * w[i], ( (C/w[j]) + 1 ) * w[j]);
						next = max(next, temp);
					}
				}
			}
			if(next == -1) break;
			else C = next;
		}
		cout << str << endl;
		printf("%d\n\n", C);
	}
	return 0;
}