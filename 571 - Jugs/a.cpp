#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int vis[1003][1003];
int Ca, Cb, N;
vector<int> seq;
bool completed;

void rec(int A, int B){
  if(completed) return;
  if(vis[A][B]) return;
  
  vis[A][B] = 1;
  
  if(B == N || A == N){
    completed = true;
    return;
  }
  
  seq.push_back(0);
  rec(Ca, B);
  if(completed) return;
  seq.pop_back();
  
  seq.push_back(1);
  rec(A, Cb);
  if(completed) return;
  seq.pop_back();
  
  seq.push_back(2);
  rec(0,B);
  if(completed) return;
  seq.pop_back();
  
  seq.push_back(3);
  rec(A,0);
  if(completed) return;
  seq.pop_back();
  
  seq.push_back(4);
  if(Ca - A >= B) rec(A+B, 0);
  else rec(Ca, B - Ca + A);
  if(completed) return;
  seq.pop_back();
  
  seq.push_back(5);
  if(Cb - B >= A) rec(0, A+B);
  else rec(A - Cb + B, Cb);
  if(completed) return;
  seq.pop_back();
}

int main(){
  while(scanf("%d %d %d", &Ca, &Cb, &N) != EOF){
    seq.clear();
    for(int i=0;i<=Ca;++i) for(int j=0;j<=Cb;++j) vis[i][j] = 0;
    completed = false;
    rec(0,0);
    for(int i=0;i<seq.size();++i){
      if(seq[i] == 0){
        printf("fill A\n");
      } else if(seq[i] == 1){
        printf("fill B\n");
      } else if(seq[i] == 2){
        printf("empty A\n");
      } else if(seq[i] == 3){
        printf("empty B\n");
      } else if(seq[i] == 5){
        printf("pour A B\n");
      } else if(seq[i] == 4){
        printf("pour B A\n");
      }
    }
    printf("success\n");
  }
  return 0;
}