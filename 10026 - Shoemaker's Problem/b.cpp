#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

/* Greedy Algo, 2nd idea: sort by difference. Proof: ??? */

vector<pair<int,int> > diff;
bool comp(const pair<int,int>& L, const pair<int,int>& R){
    if(L.first == R.first) return L.second < R.second;
    return L.first > R.first;
}

int main(){
    int TC, N;
    cin >> TC;
    bool flag = false;
    while(TC--){
        if(flag) printf("\n");
        flag = true;
        diff.clear();
        cin >> N;
        for(int i=0;i<N;++i){
            int u,v;
            cin >> u >> v;
            diff.push_back(make_pair(v-u,i));
        }
        sort(diff.begin(), diff.end(), comp);
        for(int i=0;i<N;++i){
            if(i != 0) printf(" ");
            printf("%d", diff[i].second + 1);
        }
        printf("\n");
    }
    return 0;
}