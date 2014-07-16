#include <cstdio>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

int main(){
	string fen;
	while(getline(cin,fen)){
		char board[50][50];
		for(int i=0;i<50;++i)for(int j=0;j<50;++j)board[i][j]='.';
		int len = fen.size();
		int i=8, j=8, k=0;
		while(k<len){
			//printf("%c",fen[k]);
			if(fen[k]=='/'){
				++i;
				j=8;
			}
			else if(isalpha(fen[k])){
				board[i][j]=fen[k];
				++j;
			}
			else if(isdigit(fen[k])){
				j+=fen[k]-'0';
			}
			++k;
		}
		//for(int i=8;i<16;++i){for(int j=8;j<16;++j)printf("%c",board[i][j]);printf("\n");}
		int a[50][50]={0};
		for(int i=8;i<16;++i){
			for(int j=8;j<16;++j){
				if(board[i][j]!='.')a[i][j]=1;
				if(board[i][j]=='r'||board[i][j]=='R'||board[i][j]=='q'||board[i][j]=='Q'){
					int k=1;
					while(k<=8){
						if(board[i+k][j]!='.')break;
						a[i+k][j]=1;
						++k;
					}
					k=1;
					while(k<=8){
						if(board[i][j+k]!='.')break;
						a[i][j+k]=1;
						++k;
					}
					k=1;
					while(k<=8){
						if(board[i-k][j]!='.')break;
						a[i-k][j]=1;
						++k;
					}
					k=1;
					while(k<=8){
						if(board[i][j-k]!='.')break;
						a[i][j-k]=1;
						++k;
					}


				}
				if(board[i][j]=='q'||board[i][j]=='Q'||board[i][j]=='b'||board[i][j]=='B'){
					int k=1;
					while(k<=8){
						if(board[i-k][j-k]!='.') break;
						a[i-k][j-k]=1;
						++k;
					}
					k=1;
					while(k<=8){
						if(board[i-k][j+k]!='.') break;
						a[i-k][j+k]=1;
						++k;
					}
					k=1;
					while(k<=8){
						if(board[i+k][j+k]!='.') break;
						a[i+k][j+k]=1;
						++k;
					}
					k=1;
					while(k<=8){
						if(board[i+k][j-k]!='.') break;
						a[i+k][j-k]=1;
						++k;
					}
					
				}
				if(board[i][j]=='n'||board[i][j]=='N'){
					for(int k=1;k<=2;++k)
						for(int l=1;l<=2;++l){
							if(k!=l){
								a[i-k][j-l]=1;
								a[i+k][j-l]=1;
								a[i-k][j+l]=1;
								a[i+k][j+l]=1;
							}
						}
				}
				if(board[i][j]=='P'){
					a[i-1][j-1]=1;
					a[i-1][j+1]=1;
				}
				if(board[i][j]=='p'){
					a[i+1][j+1]=1;
					a[i+1][j-1]=1;
				}
				if(board[i][j]=='K'||board[i][j]=='k'){
					a[i-1][j-1]=1;
					a[i-1][j+1]=1;
					a[i-1][j]=1;
					a[i][j-1]=1;
					a[i][j]=1;
					a[i][j+1]=1;
					a[i+1][j-1]=1;
					a[i+1][j+1]=1;
					a[i+1][j]=1;
				}
			}
		}
		int R=0;
		//for(int i=0;i<50;++i){for(int j=0;j<50;++j)printf("%d",a[i][j]);printf("\n");}

		for(int i=8;i<16;++i){
			for(int j=8;j<16;++j){
				if(a[i][j]==0)++R;
			}
		}
		printf("%d\n",R);
	}
	return 0;
}

