#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

string news[15];
int ways[15];
int N;
int u[3], state;
//nCk
void choose(int k, int c, int cnt){
  if(cnt == c){
    bool flag = false;
    for(int i=0;i<N;++i){
      if(ways[i]){
        if(flag) printf(", ");
        cout << news[i];
        flag = true;
      }
    }
    printf("\n");
    return;
  }
  if(k >= N) return;
  ways[k] = 1;
  choose(k+1, c, cnt+1);
  ways[k] = 0;
  choose(k+1, c, cnt);
}

int main(){
  string Input;
  for(int i=0;i<15;++i) ways[i] = 0;
  int TC;
  scanf("%d", &TC);
  getchar();getchar();
  bool flag = false;
  while(TC--){
    if(flag) printf("\n");
    getline(cin, Input);
    if(Input[0] == '*'){
      state = 0;
    } else {
      int i = 0;
      int sz = Input.size();
      int j = 0;
      int ct = 0;
      while(i <= sz){
        if(Input[i] == ' ' || i == sz){
          if(i == j){
            j = i+1;
            ++i;
            continue;
          }
          int temp = 0;
          for(int k=j;k<i;++k){
            temp *= 10;
            temp += (Input[k] - '0');
          }
          u[ct++] = temp;
          j = i+1;
        }
        ++i;
      }
      state = ct;
    }
    N = 0;
    while(getline(cin, Input)){
      if(Input.empty()) break;
      news[N++] = Input;
    }
    //sort(news, news+N);
    if(state == 0){
      u[0] = 1; u[1] = N;
    } else if(state == 1){
      u[1] = u[0];
    }
    for(int i=u[0]; i<= u[1];++i){
      printf("Size %d\n", i);
      choose(0,i,0);
      printf("\n");
    }
    flag = true;
  }
  return 0;
}