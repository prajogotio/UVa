#include <cstdio>
#include <iostream>
using namespace std;

int map[76];
int val[4];
int score[4];
int mark[5][5];
int ball[76];
int N;

void po(){
		for(int i=0;i<5;++i){
		for(int j=0;j<5;++j)
			printf("%d ", mark[i][j]);
		printf("\n");
	}
}
int main(){
	int TC, C, tot, p, x, y, T=1;
	scanf("%d", &TC);
	while(TC--){
		if(T != 1) printf("\n");
		printf("Case %d:\n", T++);
		scanf("%d %d", &N, &C);
		for(int i=0;i<N;++i){
			scanf("%d", &ball[i]);
		}
		for(int i=0;i<4;++i){
			scanf("%d", &val[i]);
		}
		for(int c=0;c<C;++c){
			tot = 0;
			for(int i=0;i<4;++i) score[i] = 0;
			for(int i=0;i<76;++i) map[i] = -1;
			for(int i=0;i<5;++i)
				for(int j=0;j<5;++j)
				{
					mark[i][j] = 0;
					scanf("%d", &p);
					map[p] = i*5 + j;
				}

			for(int i=0;i<N && i < 35; ++i){
				p = ball[i];
				if(map[p] == -1) continue;
				x = map[p] / 5;
				y = map[p] % 5;
				mark[x][y] = 1;
				//printf("%d %d %d\n", p, x, y);

			}
			if(mark[0][0] && mark[4][4] && mark[0][4] && mark[4][0]) score[0] = 1;
			for(int i=35;i<N && i<40;++i){
				p = ball[i];
				if(map[p] == -1) continue;
				x = map[p] / 5;
				y = map[p] % 5;
				mark[x][y] = 1;
			}
			for(int j=0;j<5;++j){
				if(mark[2][j] == 0)break;
				if(j == 4) {
					score[1] = 1;
					break;
				}
			}
			//po();
			for(int i=40;i<45 && i<N;++i){
				p = ball[i];
				if(map[p] == -1) continue;
				x = map[p] / 5;
				y = map[p] % 5;
				mark[x][y] = 1;
			}
			for(int i=0;i<5;++i){
				//cout << mark[i][i] << " " << mark[4-i][i] << endl;
				if(!mark[i][i] || !mark[4-i][i]) break;
				if(i==4) score[2] = 1;
			}
			for(int i=45;i<75 && i <N;++i){
				p = ball[i];
				if(map[p] == -1) continue;
				x = map[p] / 5;
				y = map[p] % 5;
				mark[x][y] = 1;
			}
			score[3] = 1;
			for(int i=0;i<5;++i){
				for(int j=0;j<5;++j){
					if(mark[i][j] == 0){
						score[3] = 0;
						break;
					}
				}
				if(!score[3]) break;
			}
			for(int i=0;i<4;++i){
				if(score[i]) tot += val[i];
			}

			printf("%d\n", tot);
		}

	}
	return 0;
}

