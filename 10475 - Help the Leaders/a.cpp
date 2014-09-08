#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cctype>
using namespace std;

vector<string> str;
map<string,int> idx;
int no[20][20];
int mark[20];
int N, P, C;

void choose(int c, int k, int cnt){
  if(c == cnt){
    bool flag = false;
    for(int i=0;i<N;++i){
      if(mark[i]){
        if(flag) printf(" ");
        cout << str[i];
        flag = true;
      }
    }
    printf("\n");
    return;
  }
  if(k >= N) return;
  bool ok = true;
  for(int i=0;i<k;++i){
    if(mark[i] && no[i][k]){
      ok = false;
      break;
    }
  }
  if(ok){
    mark[k] = 1;
    choose(c, k+1, cnt+1);
    mark[k] = 0;
  }
  choose(c, k+1, cnt);
}

bool cmp(const string& L, const string& R){
  if(L.size() != R.size()) return L.size() > R.size();
  return L < R;
}

int main(){
  string one, two;
  int u,v, T=1;
  int TC;
  cin >> TC;
  for(int i=0;i<20;++i)mark[i] = 0;
  while(scanf("%d %d %d", &N, &P, &C) != EOF, TC--){
    printf("Set %d:\n", T++);
    str.clear();
    idx.clear();
    for(int i=0;i<N;++i){
      for(int j=0;j<N;++j){
        no[i][j] = 0;
      }
    }
    for(int i=0;i<N;++i){
      cin >> one;
      for(int j=0;j<one.size();++j){
        one[j] = toupper(one[j]);
      }
      str.push_back(one);
    }
    sort(str.begin(), str.end(), cmp);
    for(int i=0;i<N;++i){
      idx[str[i]] = i;
    }
    for(int i=0;i<P;++i){
      cin >> one >> two;
      for(int j=0;j<one.size();++j){
        one[j] = toupper(one[j]);
      }
      for(int j=0;j<two.size();++j){
        two[j] = toupper(two[j]);
      }
      u = idx[one];
      v = idx[two];
      no[u][v] = 1;
      no[v][u] = 1;
    }
    choose(C, 0, 0);
    printf("\n");
  }
  return 0;
}