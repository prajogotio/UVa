#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
int N;
string cd[] = {"YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY"};
vector<string> vs;
vector<int> state;

int main(){
	while(scanf("%d", &N), N!=0){
		vs.clear(); state.clear();
		state.assign(N+1, 0);
		for(int i=0;i<N;++i){
			string str;
			cin>>str;
			vs.push_back(str);
		}
		for(int i=0;i<7;++i){
			if(vs[N-1][i] == 'N'){
				state[N-1] |= (1<<i);
			}
		}

		for(int i=1;i<N;++i){
			state[N-i-1] = state[N-i];
			for(int j=0;j<7;++j){
				if(vs[N-1-i][j] == 'Y'){
					if(state[N-i-1] & (1<<j)){
						state[N-i-1] &= (~(1<<j));
					}
				}
			}
			//printf("%d\n", state[N-1-i]);
		}
		bool matched = false;
		for(int i=9; i>=N-1; --i){
			bool wrong = false;
			for(int j=0; j<N; ++j){
				for(int k=0;k<7;++k){
					if(state[j] & (1<<k)) continue;
					if(vs[j][k] != cd[i-j][k]){
						wrong = true;
						break;
					}
				}
				if(wrong) break;
			}
			if(!wrong){
				matched = true;
				break;
			}
		}
		if(matched) printf("MATCH\n");
		else printf("MISMATCH\n");
	}
	return 0;
}

