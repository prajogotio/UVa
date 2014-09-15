#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
int maxint = (int) 1e9;
int n,m,t;
pair<int,int> dp[10003];
int mark[10003];

pair<int,int> rec(int val){
    if(val < 0) return make_pair(-maxint, maxint);
    if(val - n < 0 && val - m < 0){
        return make_pair(0, val);
    }
    if(mark[val]) return dp[val];
    mark[val] = 1;
    pair<int,int> ret1 = rec(val - n);
    pair<int,int> ret2 = rec(val - m);
    if(ret1.second < ret2.second){
        ++ret1.first;
        dp[val] = ret1;
    } else if( ret1.second > ret2.second){
        ++ret2.first;
        dp[val] = ret2;
    } else {
        ret1.first = max(ret1.first, ret2.first) + 1;
        dp[val] = ret1;
    }
    return dp[val];
}

int main(){
    while(scanf("%d %d %d", &n, &m, &t)!=EOF){
        for(int i=0;i<=t;++i) mark[i] = 0;
        pair<int,int> ans = rec(t);
        printf("%d", ans.first);
        if(ans.second != 0) printf(" %d", ans.second);
        printf("\n");
    }
    return 0;
}