#include <iostream>
#include <cstdio>
using namespace std;

char arr[205][205];
char stack[50005];
int r,c;
int s;

void dfs(int i, int j, int m, int n){
	char check = arr[i][j];
	bool allsame = true;
	for(int u=i;u<=m;++u){
		for(int v=j;v<=n;++v){
			if(arr[u][v] != check){
				allsame = false;
				break;
			}
		}
	}
	if(allsame){
		stack[s] = check;
		++s;
		return;
	}
	stack[s] = 'D';
	++s;
	int midr = (i+m)/2;
	int	midc = (j+n)/2;

	//if horizontal
	if(i-m == 0){
		dfs(i,j,i,midc);
		dfs(i,midc+1,i,n);
		return;
	}
	//if vertical
	if(j-n == 0){
		dfs(i,j,midr,j);
		dfs(midr+1,j,m,j);
		return;
	}
	dfs(i,j,midr,midc);
	dfs(i,midc+1,midr,n);
	dfs(midr+1,j,m,midc);
	dfs(midr+1,midc+1,m,n);
}

void proceed(int i, int j, int m, int n){
	char state;
	scanf(" %c",&state);
	if(state != 'D'){
		for(int u=i;u<=m;++u){
			for(int v=j;v<=n;++v){
				arr[u][v]=state;
			}
		}
		return;
	}

	int midr = (i+m)/2;
	int midc = (j+n)/2;
	//if horizontal
	if(i-m == 0){
		proceed(i,j,i,midc);
		proceed(i,midc+1,i,n);
		return;
	}
	//if vertical
	if(j-n == 0){
		proceed(i,j,midr,j);
		proceed(midr+1,j,m,j);
		return;
	}
	proceed(i,j, midr, midc);
	proceed(i,midc+1, midr, n);
	proceed(midr+1, j, m, midc);
	proceed(midr+1,midc+1, m,n);
}

int main(){
	char state;
	while(scanf(" %c",&state), state !='#'){
		scanf("%d%d",&r,&c);
		s=0;
		if(state == 'B'){
			for(int i=0;i<r;++i){
				for(int j=0;j<c;++j){
					scanf(" %c",&arr[i][j]);
				}
			}
			printf("D%4d%4d\n", r, c);
			if(r==0 || c == 0)continue;
			dfs(0,0, r-1, c-1);
			int ctr=0;
			for(int i=0;i<s;++i){
				printf("%c",stack[i]);
				++ctr;
				if(ctr%50 == 0)printf("\n");
			}
			if(ctr%50 != 0) printf("\n");
		} else {
			printf("B%4d%4d\n", r, c);
			if(r==0 || c == 0)continue;
			proceed(0,0, r-1, c-1);
			int ctr = 0;
			for(int i=0;i<r;++i){
				for(int j=0;j<c;++j){
					printf("%c",arr[i][j]);
					++ctr;
					if(ctr%50 == 0)printf("\n");
				}
			}
			if(ctr%50 != 0)printf("\n");
		}
	}
	return 0;
}