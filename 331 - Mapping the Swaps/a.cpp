#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
using namespace std;

set<vector<int> > ans;
int N;

void rec(vector<int> arr, vector<int> smap){
  bool mark = false;
  for(int i=0;i+1<N;++i){
    if(arr[i] > arr[i+1]){
      mark = true;
      smap.push_back(i);
      swap(arr[i], arr[i+1]);
      rec(arr, smap);
      swap(arr[i], arr[i+1]);
      smap.pop_back();
    }
  }
  if(!mark){
    if(!smap.empty()) ans.insert(smap);
    return;
  }
}


int main(){
  int u, T=1;
  vector<int> arr;
  while(scanf("%d", &N), N != 0){
    arr.clear();
    for(int i=0;i<N;++i){
      scanf("%d", &u);
      arr.push_back(u);
    }
    ans.clear();
    rec(arr, vector<int>());
    printf("There are %d swap maps for input data set %d.\n", (int) ans.size(), T++);
  }
  return 0;
}