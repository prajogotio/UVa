#include <iostream>
#include <cstdio>
using namespace std;

char first[6], second[6], cur[6];

void rotateX(char *cube){
	char temp = cube[0];
	cube[0] = cube[2];
	cube[2] = cube[5];
	cube[5] = cube[3];
	cube[3] = temp;
}

void rotateY(char *cube){
	char temp = cube[1];
	cube[1] = cube[2];
	cube[2] = cube[4];
	cube[4] = cube[3];
	cube[3] = temp;
}

void rotateZ(char *cube){
	char temp = cube[0];
	cube[0] = cube[1];
	cube[1] = cube[5];
	cube[5] = cube[4];
	cube[4] = temp;
}

bool same(){
	for(int i=0;i<6;++i){
		if(first[i] != cur[i]) return false;
	}
	return true;
}

void cpy(){
	for(int i=0;i<6;++i){
		cur[i] = second[i];
	}
}

int main(){
	bool issame;
	while(scanf(" %c", &first[0]) != EOF){
		for(int i=1;i<6;++i)
			scanf("%c", &first[i]);
		for(int i=0;i<6;++i)
			scanf("%c", &second[i]);
		issame = false;
		for(int x=0;x<4;++x){
			for(int y=0;y<4;++y){
				for(int z=0;z<4;++z){
					cpy();
					for(int i=0;i<x;++i)
						rotateX(cur);
					for(int i=0;i<y;++i)
						rotateY(cur);
					for(int i=0;i<z;++i)
						rotateZ(cur);
					if(same()) {issame=true; break;}
				}
				if(issame) break;
			}
			if(issame) break;
		}
		if(issame) printf("TRUE\n");
		else printf("FALSE\n");
	}
	return 0;
}