#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long Long;
int tgt, N;
Long dp[70][70][2];

Long rec(int k, int cnt, int state){
    if(k == N && cnt == tgt) return 1;
    if(k == N) return 0;
    if(dp[k][cnt][state] != -1) return dp[k][cnt][state];
    //above closed
    Long ret = 0;
    if(state == 1){
        if(cnt == tgt){
            ret += rec(k+1, cnt, 0);
        } else {
            ret += rec(k+1, cnt+1, 1);
            ret += rec(k+1, cnt, 0);
        }
    } else {
        ret += rec(k+1, cnt, 0);
        ret += rec(k+1, cnt, 1);
    }
    dp[k][cnt][state] = ret;
    return ret;
}

int main(){
    while(cin >> N >> tgt){
        if(N < 0 && tgt < 0) break;
        for(int i=0;i<70;++i){
            for(int j=0;j<70;++j){
                dp[i][j][0] = dp[i][j][1] = -1;
            }
        }
        Long ans = rec(0, 0, 1);
        cout << ans << endl;
    }
    return 0;
}