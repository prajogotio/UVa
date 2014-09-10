#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long Long;
set<Long> x;
vector<Long> a;
int N;
Long num;

int main(){
    Long A=1,B=1;
    x.insert(1);
    for(int i=1;i<=31;++i){
        A *= 2;
        x.insert(A);
        B = 1;
        for(int j=1;j<=31;++j){
            B *= 3;
            x.insert(A*B);
            x.insert(B);
        }
    }
    a.assign(x.begin(), x.end());
    N = a.size();
    int hi,lo,mid;
    while(cin >> num){
        if(num == 0) break;
        lo = 0; hi = N-1;
        while(lo <= hi){
            mid = (lo+hi)/2;
            if( num > a[mid]){
                lo = mid +1;
            } else {
                hi = mid -1;
            }
        }
        cout << a[lo] << endl;
    }
    return 0;
}