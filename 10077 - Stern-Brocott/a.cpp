#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  long long N,M;
  long long n_lo, m_lo, n_hi, m_hi, n_mid, m_mid;
  while(cin >> N >> M, N!=1 || M!=1){
    n_lo = 0, m_lo = 1;
    n_hi = 1, m_hi = 0;
    while(1){
      n_mid = n_lo + n_hi;
      m_mid = m_lo + m_hi;
      if(n_mid == N && m_mid == M) break;
      if(n_mid * M < m_mid * N){
        printf("R");
        n_lo = n_mid;
        m_lo = m_mid;
      } else {
        printf("L");
        n_hi = n_mid;
        m_hi = m_mid;
      }
    }
    printf("\n");
  }
  return 0;
}