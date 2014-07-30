#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int graph[204][403];
int cc[80003];
string helio[204];
int H, w, W, ff;

int code[16][4] = {0,0,0,0, 0,0,0,1, 0,0,1,0, 0,0,1,1, 0,1,0,0, 0,1,0,1, 0,1,1,0, 0,1,1,1, 
									 1,0,0,0, 1,0,0,1, 1,0,1,0, 1,0,1,1, 1,1,0,0, 1,1,0,1, 1,1,1,0, 1,1,1,1};


void decode(int i, int j, char c){
	int d = -1;
	d = c - '0';
	if( d > 9 ) d = c - 'a' + 10;
	for(int k=0;k<4;++k){
		graph[i][j+k] = code[d][k];
	}
}


void dec(int i, int j){
	if(i < 0 || i >= H || j < 0 || j >= W) return;
	if(graph[i][j] != 0) return;
	graph[i][j] = -1;
	dec(i-1,j);
	dec(i+1,j);
	dec(i,j-1);
	dec(i,j+1);
}

void mark(int i, int j){
	if(i < 0 || i >= H || j < 0 || j >= W) return;
	if( graph[i][j] != 1) return;
	graph[i][j] = ff;
	mark(i+1,j);
	mark(i-1,j);
	mark(i,j-1);
	mark(i,j+1);
}

void fill(int i, int j, int col){
	if(i < 0 || i >= H || j < 0 || j >= W) return;
	if(graph[i][j] != 0) return;
	graph[i][j] = col;
	fill(i-1, j, col);
	fill(i+1, j, col);
	fill(i, j-1, col);
	fill(i, j+1, col);
}

void printout(){
	printf("\n");
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			printf(" %2d", graph[i][j]);
		}
		printf("\n");
	}
}

void drawout(){
	printf("\n");
	for(int i=0;i<H;++i){
		for(int j=0;j<W;++j){
			if(graph[i][j] == 1) printf("0");
			else printf(" ");
		}
		printf("\n");
	}
}

int main(){
	int T = 1;
	while(scanf("%d %d", &H, &w), H+w != 0){
		printf("Case %d: ", T++);
		for(int i=0;i<H;++i){
			cin>>helio[i];
			for(int j=0;j<w;++j){
				decode(i, j*4, helio[i][j]);
			}
		}
		
		W = 4*w;
		//printout();
		//drawout();
		for(int i=0;i<W;++i){
			if(graph[0][i] == 0)dec(0,i);
			if(graph[H-1][i] == 0) dec(H-1, i);
		}
		for(int i=0;i<H;++i){
			if(graph[i][0] == 0) dec(i,0);
			if(graph[i][W-1] == 0) dec(i, W-1);
		}

		ff = 1;
		for(int i=0;i<H;++i){
			for(int j=0;j<W;++j){
				if(graph[i][j] == 1){
					++ff;
					cc[ff] = 0;
					mark(i,j);
				}
			}
		}
		int col = -1;
		bool ingraph = false;

		for(int i=0;i<H;++i){
			for(int j=0;j<W;++j){
				if(graph[i][j] != -1){
					if(ingraph == false){
						col = graph[i][j];
						ingraph = true;
					} else {
						if(graph[i][j] == 0){
							++cc[col];
							fill(i,j,col);
						}
					}
				} else {
					ingraph = false;
				}
			}
		}

		string ans;
		for(int i=2;i<=ff;++i){
			if(cc[i] == 0) ans += 'W';
			if(cc[i] == 1) ans += 'A';
			if(cc[i] == 2) ans += 'K';
			if(cc[i] == 3) ans += 'J';
			if(cc[i] == 4) ans += 'S';
			if(cc[i] == 5) ans += 'D';
		}
		sort(ans.begin(), ans.end());
		cout << ans << endl;
		
	}
	return 0;
}