#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

set<int> dp, tmp;
set<int>::iterator it;
int a[10003];
int N, K, u, v;

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        cin >> N;
        cin >> K;
        for(int i=0;i<N;++i){
            cin >> u;
            u %= K;
            if( u < 0 ) u += K;
            a[i] = u;
        }
        dp.clear();
        dp.insert(a[0]);
        for(int i=1;i<N;++i){
            for(it = dp.begin(); it != dp.end();++it){
                u = (*it + a[i]) % K;
                v = (*it - a[i]) % K;
                if(u < 0) u += K;
                if(v < 0) v += K;
                tmp.insert(u);
                tmp.insert(v);
            }
            dp.clear();
            for(it = tmp.begin(); it != tmp.end(); ++it){
                dp.insert(*it);
            }
            tmp.clear();
        }
        if(dp.find(0) != dp.end()) printf("Divisible\n");
        else printf("Not divisible\n");
    }
    return 0;
}