#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

vector<string> m;
int N, M, S;
string inst;

void move(int &x, int &y, int state){
	//printf("%d %d %d\n", x, y, state);
	if(state == 3){
		if(y != 0 && m[x][y-1] != '#')
			--y;
	} else if (state == 2){
		if(x != (N-1) && m[x+1][y] != '#')
			++x;
	} else if (state == 1){
		if(y != (M-1) && m[x][y+1] != '#')
			++y;
	} else if (state == 0){
		if(x != 0 && m[x-1][y] != '#')
			--x;
		
	}
}

int main(){
	while(scanf("%d %d %d",&N, &M, &S), N+M+S != 0){
		m = vector<string>(N+3);
		for(int i=0;i<N;++i){
			cin >> m[i];
		}
		int x = -1, y=-1, state, score = 0;
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				if(m[i][j] == 'N' || m[i][j] == 'L' || m[i][j] == 'S' || m[i][j] == 'O'){
					x = i;
					y = j;
					if(m[i][j] == 'N') state = 0;
					if(m[i][j] == 'L') state = 1;
					if(m[i][j] == 'S') state = 2;
					if(m[i][j] == 'O') state = 3;
					break;
				}
			}
		}
		cin >> inst;
		for(int i=0;i<S;++i){
			if(inst[i] == 'D'){
				state = (state + 1) % 4;
			} else if (inst[i] == 'E'){
				state = (state - 1) % 4;
				if( state < 0) state = (4 + state);
			} else {
				move(x,y,state);
				if(m[x][y] == '*'){
					++score;
					m[x][y] = '.';
				}
			}
		}
		printf("%d\n", score);
	}
	return 0;
}