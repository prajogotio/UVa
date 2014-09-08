#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int L;
int ctr;
int target;
bool completed;

bool check(string str){
  //printf("checking %s\n", str.c_str());
  
  int sz = str.size();
  int cnt = 1;
  while(cnt * 2 <= sz){
    bool reject = true;
    for(int i=0;i<cnt;++i){
      if(str[sz - 1 - i] != str[sz - 1 - cnt - i]){
        reject = false;
        break;
      }
    }
    if(reject) return false;
    //printf("passed %d\n", cnt);
    
    ++cnt;
  }
  //printf("accepted\n");
  return true;
}

void dfs(string str, int len){
  //cout << str << endl;
  if(completed) return;
  ++ctr;
  if(ctr == target){
    for(int i=0;i<len;++i){
      if(i!=0 && (i%4 == 0 && i%64 != 0)) printf(" ");
      if(i!=0 && (i%64 == 0)) printf("\n");
      cout << str[i];
    }
    if(len-1%64!=0) printf("\n");
    printf("%d\n", len);
    completed = true;
    return;
  }
  if(len == 80) return;
  string temp = string();
  for(int i=0;i<L;++i){
    temp = str + (char) (i + 'A');
    if(check(temp)){
      dfs(temp, len+1);
      if(completed) return;
    }
  }
}

int main(){
  while(scanf("%d %d", &target, &L), target + L != 0){
    ctr = -1;
    completed = false;
    dfs(string(), 0);
  }
  return 0;
}