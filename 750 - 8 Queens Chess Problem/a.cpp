#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int> > ways;
vector<int> col(8);
int M, N;
void generate(int k){
  if(k == 8){
    ways.push_back(col);
    return;
  }
  for(int i=0;i<8;++i){
    bool ok = true;
    for(int j=0;j<k;++j){
      if(col[j] == i || col[j] - i == j - k || col[j] - i == k - j){
        ok = false;
        break;
      }
    }
    if(ok){
      col[k] = i;
      generate(k+1);
    }
  }
}

int main(){
  generate(0);
  int sz = ways.size(), cnt = 0;
  int TC;
  bool flag = false;
  scanf("%d", &TC);
  while(TC--){
    if(flag) printf("\n");
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    scanf("%d %d", &M, &N);
    cnt = 0;
    for(int i=0;i<sz;++i){
      if(ways[i][N-1] == M-1){
        printf("%2d     ", ++cnt);
        for(int j=0;j<8;++j){
          printf(" %d", ways[i][j] + 1);
        }
        printf("\n");
      }
    }
    flag = true;
  }
  return 0;
}