#include <iostream>
#include <cstdio>
using namespace std;

int a[6], b[6], c[6];
// t b f l b r
// 0 1 2 3 4 5
// 0 1 5 2 3 4
// 4 2 0 3 1 5
// 5 3 2 0 4 1
void cpy(){
	for(int i=0;i<6;++i){
		c[i] = a[i];
	}
}

bool check(){
	for(int i=0;i<6;++i){
		if(c[i] != b[i]) return false;
	}
	return true;
}

void rx(){
	int temp = c[2];
	c[2] = c[5];
	c[5] = c[4];
	c[4] = c[3];
	c[3] = temp;
}

void ry(){
	int temp = c[0];
	c[0] = c[4];
	c[4] = c[1];
	c[1] = c[2];
	c[2] = temp;
}

void rz(){
	int temp = c[0];
	c[0] = c[5];
	c[5] = c[1];
	c[1] = c[3];
	c[3] = temp;
}

int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		for(int i=0;i<6;++i){
			scanf("%1d", &a[i]);
		}
		for(int i=0;i<6;++i){
			scanf("%1d", &b[i]);
		}
		/*
		for(int i=0;i<6;++i){
			cout << b[i] << endl;
		}
		*/
		bool yes = false;
		for(int i=0;i<=3;++i){
			for(int j=0;j<=3;++j){
				for(int k=0;k<=3;++k){
					cpy();
					for(int x=0;x<i;++x){
						rx();
					}
					for(int y=0;y<j;++y){
						ry();
					}
					for(int z=0;z<k;++z){
						rz();
					}
					if(check()){
						yes = true;
					}
					if(yes) break;
				}
				if(yes) break;
			}
			if(yes) break;
		}
		if(yes) printf("Equal");
		else printf("Not Equal");
		printf("\n");
	}
	return 0;
}