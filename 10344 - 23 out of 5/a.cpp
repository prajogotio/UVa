#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[6];
int o[6];
bool can;

bool check(){
  int temp = a[0];
  for(int i=1;i<=4;++i){
    if(o[i-1] == 0){
      temp += a[i];
    } else if (o[i-1] == 1){
      temp *= a[i];
    } else {
      temp -= a[i];
    }
  }
  //printf("%d\n", temp);
  return temp == 23;
}

void rec(int k){
  if(can) return;
  if(k == 4){
    can = check();
    return;
  }
  for(int i=0;i<3;++i){
    o[k] = i;
    rec(k+1);
  }
}

int main(){
  int ch = 0;
  while(scanf("%d", &a[0]) != EOF){
    ch = a[0];
    for(int i=1;i<=4;++i){
      scanf("%d", &a[i]);
      ch += a[i];
    }
    if(ch == 0) break;
    can = false;
    sort(a,a+5);
    rec(0);
    while(next_permutation(a, a+5)){
      rec(0);
    }
    if(can) printf("Possible\n");
    else printf("Impossible\n");
  }
  return 0;
}
    