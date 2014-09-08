#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
using namespace std;

vector<pair<string,string> > choice;
string enc;
int N, SZ;
int ctr;

void rec(int k, string str){
  if(ctr == 100) return;
  if(k == SZ){
    ++ctr;
    cout << str << endl;
  }
  if(k >= SZ) return;
  while(k < SZ && enc[k] == '0'){
    ++k;
  }
  if(k >= SZ) return;
  for(int i=0;i<N;++i){
    if(k + choice[i].second.size() - 1 < SZ){
      bool ok = true;
      for(int j=0;j<choice[i].second.size();++j){
        if(choice[i].second[j] != enc[k+j]){
          ok = false;
          break;
        }
      }
      if(!ok) continue;
      rec(k+choice[i].second.size(), str + choice[i].first);
      if(ctr == 100) return;
    }
  }
}

int main(){
  string First, Second;
  int T = 1;
  while(cin >> N, N!= 0){
    choice.clear();
    ctr = 0;
    for(int i=0;i<N;++i){
      cin >> First >> Second;
      choice.push_back(make_pair(First, Second));
    }
    sort(choice.begin(), choice.end());
    cin >> enc;
    SZ = enc.size();
    printf("Case #%d\n", T++);
    rec(0, string());
    printf("\n");
  }
  return 0;
}