#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int maxint = (int) 1e9;
vector<pair<int,int> > seg;
vector<int> path;

int main(){
    int N, M;
    int TC;
    cin>>TC;
    bool flag = false;
    while(TC--){
        if(flag) printf("\n");
        cin >> M;
        int u,v;
        seg.clear();
        path.clear();
        while(cin>>u>>v){
            if(u==0 && v ==0) break;
            seg.push_back(make_pair(u,v));
        }
        N = seg.size();
        sort(seg.begin(), seg.end());
        /*
        int cur = 0;
        int next = -maxint;
        int idx = -maxint;
        bool ok = true;
        for(int i=0;i<N;++i){
            if(seg[i].first > cur){
                if(next == -maxint) {
                    ok = false;
                    break;
                }
                path.push_back(idx);
                cur = next + 1;
                next = idx = -maxint;
                if(cur > M) break;
            }
            if(seg[i].first <= cur && cur <= seg[i].second){
                if(next < seg[i].second){
                    next = seg[i].second;
                    idx = i;
                }
            }
        }
        if(!ok){ 
            printf("0\n");
            continue;
        }
        if(next != -maxint){
            path.push_back(idx);
        }
        if(seg[path[path.size()-1]].second < M) {
            printf("0\n");
            continue;
        }
        else {
            printf("%d\n", (int) path.size());
            for(int i=0;i<path.size();++i){
                printf("%d %d\n", seg[path[i]].first, seg[path[i]].second);
            }
        }
        */
        int cur = 0;
        for(int i = 0; i<N && cur < M;){
            bool found = false;
            int maxR = 0;
            int idx = -1;
            for(;i<N && seg[i].first <= cur; ++i){
                if(maxR < seg[i].second){
                    maxR = seg[i].second;
                    idx = i;
                    found = true;
                }
            }
            if(!found) break;
            path.push_back(idx);
            cur = maxR;
        }
        if(cur < M) printf("0\n");
        else {
            printf("%d\n", (int) path.size());
            for(int i=0;i<path.size();++i){
                printf("%d %d\n", seg[path[i]].first, seg[path[i]].second);
            }
        }
        flag = true;
    }
    return 0;
}