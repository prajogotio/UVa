#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

/*
 0 0 0
 0 0 1
 0 1 0
 0 1 1
 1 0 0
 1 0 1
 1 1 0
 1 1 1
 */
int conf[8][3] = {{0,0,0}, {0,0,1}, {0,1,0}, {0,1,1}, {1,0,0}, {1,0,1}, {1,1,0}, {1,1,1}};
int step[35];
int ind[10];
int end[35];
int N, Ind;
bool completed;

void rec(int k){
  if(completed) return;
  
  int st = step[k-1]*4 + step[k]*2;
  
  if(k == N-2){
    /*
    for(int i=0;i<N;++i){
      printf("%d", step[i]);
    }
    printf("\n");
    */
    st += step[k+1];
    if(end[k] == ind[st]){
      st = step[k]*4 + step[k+1]*2 + step[0];
      if(end[k+1] == ind[st]){
        completed = true;
      }
    }
    return;
  }
  
  if(ind[st] == end[k]){
    step[k+1] = 0;
    rec(k+1);
  } 
  if(ind[st+1] == end[k]){
    step[k+1] = 1;
    rec(k+1);
    
  }
}

int main(){
  while(scanf("%d %d",&Ind, &N) != EOF){
    for(int i=0;i<N;++i){
      scanf(" %1d", &end[i]);
    }
    /*
    for(int i=0;i<N;++i){
      printf("%d", end[i]);
    }
    printf("\n");
    */
    for(int i=0;i<8;++i){
      ind[i] = Ind%2;
      Ind /= 2;
    }
    /*
    printf("indicator: ");
    for(int i=0;i<8;++i){
      printf("%d", ind[i]);
    }
    printf("\n");
    */
    completed = false;
    for(int i=0;i<8;++i){
      if(ind[i] == end[0]){
        step[N-1] = conf[i][0];
        step[0] = conf[i][1];
        step[1] = conf[i][2];
        rec(1);
      }
    }
    if(completed) printf("REACHABLE\n");
    else printf("GARDEN OF EDEN\n");
  }
  return 0;
}