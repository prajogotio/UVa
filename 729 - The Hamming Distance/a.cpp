#include <iostream>
#include <cstdio>
using namespace std;

int bit[20];
int N, H;

void rec(int k, int c){
  if(k == N && c == H){
    for(int i=0;i<N;++i){
      printf("%d", bit[i]);
    }
    printf("\n");
    return;
  }
  if(k >= N || c > H) return;
  bit[k] = 0;
  rec(k+1, c);
  bit[k] = 1;
  rec(k+1, c+1);
}

int main(){
  int TC;
  scanf("%d", &TC);
  bool flag=false;
  while(TC--){
    if(flag) printf("\n");
    scanf("%d %d", &N, &H);
    rec(0,0);
    flag = true;
  }
  return 0;
}