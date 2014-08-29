#include <iostream>
#include <cstdio>
using namespace std;

int b[10][10];
int vis[10][10];
int N,M;
int stack[10];
bool completed;
char p[9] = "@IEHOVA#";

void dfs(int i, int j, int state){
  if(completed) return;
  if(state == 7) {
    completed = true;
    return;
  }
  vis[i][j] = 1;
  if(i > 0 && b[i-1][j] == state+1){
    stack[state] = 0;
    dfs(i-1,j,state+1);
  } else if(j > 0 && b[i][j-1] == state+1){
    stack[state] = -1;
    dfs(i,j-1,state+1);
  }
  /* else if(i+1 < N && b[i+1][j] == state+1){
    stack[state] = -1;
    dfs(i+1,j,state+1);
  } 
  */
  else if(j+1 < M && b[i][j+1] == state+1){
    stack[state] = 1;
    dfs(i,j+1,state+1);
  }
}

void printpath(){
  for(int i=0;i<7;++i){
    if(i != 0) printf(" ");
    if(stack[i] == 0) printf("forth");
    else if(stack[i] == 1) printf("right");
    else printf("left");
  }
}

int main(){
  int TC, u, v;
  char temp;
  scanf("%d", &TC);
  while(TC--){
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;++i){
      for(int j=0;j<M;++j){
        scanf(" %c", &temp);
        b[i][j] = -1;
        if(temp == p[0]){
          u = i;
          v = j;
        }
        for(int k=0;k<=7;++k){
          if(temp == p[k]){
            b[i][j] = k;
          }
        }
      }
    }
    completed = false;
    dfs(u,v,0);
    printpath();
    printf("\n");
  }
  return 0;
}