#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> dp;
int rec(string str){
    //cout << str << endl;
    if(str.size() == 0) return 1;
    if(str.size() == 1) return 0;
    if(dp.find(str) != dp.end()) return dp[str];
    string tmp;
    char prev = str[0];
    int previ = 0;
    int sz = str.size();
    for(int i=1; i<=sz;++i){
        if(str[i] != prev){
            if( i - previ < 2 ){
                previ = i;
                prev = str[i];
                continue;
            }
            tmp = str.substr(0, previ);
            tmp += str.substr(i, sz - i);
            dp[str] |= rec(tmp);
            if(dp[str] == 1) {
                return 1;
            }
            previ = i;
            prev = str[i];
        }
    }
    if( sz - previ >= 2){
        tmp = str.substr(0, previ);
        dp[str] |= rec(tmp);
    }
    return dp[str];
}

int main(){
    string ip;
    int TC;
    cin >> TC;
    while(TC--){
        cin >> ip;
        dp.clear();
        int ans = rec(ip);
        cout << ans << endl;
    }
    return 0;
}