#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long Long;

/*
 120 --> 1 .. 60 or 61 .. 120
         1 .. 20 21 .. 40 41 .. 60
*/

Long target;
int N, endstate;
int step[30];
string str, ans;
int start;
Long lefts, rights;

Long ffact(int s, int t){
  Long ret = 1;
  for(Long k = s; k<=t;++k){
    ret *= k;
  }
  return ret;
}

Long fact(int n){
  if(n == 0) return 1;
  return n*fact(n-1);
}

void rec(int k, Long L, Long R){
  //printf("%d %lld %lld %lld\n", k, target, L, R);
  if(k == endstate+1) return;
  Long per = (R-L+1LL)/k;
  for(int i=0;i<k;++i){
    if(((Long)i)*per <= target - L && target-L<= (((Long)i)+1)*per - 1){
      step[k] = i;
      rec(k+1, L+((Long)i)*per, L+((Long)(i+1))*per-1);
      return;
    }
  }
}

int main(){
  int TC;
  cin >> TC;
  while(cin>>str){
    cin >> target;
    N = str.size();
    if(N <= 13){
      ans = string();
      start = 1;
      endstate = N;
      lefts = 1LL;
      rights = fact(N);
      /*
      for(int i=1;i<=N;++i){
        printf("%d ", step[i]);
      }
      printf("\n");
      */
    } else {
      // for N > 13
      start = N-13+1;
      endstate = N;
      lefts = 1;
      rights = ffact(start, N);
      //cout << endstate << endl;
      ans = str.substr(0,N-13);
      reverse(ans.begin(), ans.end());
      //str = str.substr(N-13, 13);
      N = 13;
    }
    rec(start, lefts, rights);
    for(int i=start;i<=endstate;++i){
      string temp1 = ans.substr(0, step[i]);
      string temp2 = ans.substr(step[i], ans.size()-step[i]);
      ans = temp1 + str[i-1] + temp2;
    }
    cout << ans << endl;
  }
  return 0;
}