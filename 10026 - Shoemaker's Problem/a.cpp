#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
vector<pair<pair<int,int>,int> > a;
bool comp(const pair<pair<int,int>,int>& L, const pair<pair<int,int>,int>& R){
    if(L.first.first == R.first.first){
        if(L.first.second == R.first.second) return L.second < R.second;
        return L.first.second > R.first.second;
    }
    return L.first.first < R.first.first;
}

int main(){
    int TC;
    cin >> TC;
    while(TC--){
        int N;
        cin >> N;
        a.clear();
        for(int i=0;i<N;++i){
            int u,v;
            cin >> u >> v;
            a.push_back(make_pair(make_pair(u,v),i+1));
        }
        sort(a.begin(), a.end(), comp);
        for(int i=0;i<N;++i){
            if(i!=0)printf(" ");
            printf("%d", a[i].second);
        }
        printf("\n");
    }
    return 0;
}