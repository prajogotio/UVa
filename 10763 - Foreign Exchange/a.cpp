#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int,int> > a;
vector<pair<int,int> > b;

int main(){
    int N;
    while (cin >> N, N!=0){
        a.clear();
        b.clear();
        for(int i=0;i<N;++i){
            int u,v;
            cin >> u >> v;
            if(u < v){
                a.push_back(make_pair(u,v));
            } else {
                b.push_back(make_pair(v,u));
            }
        }
        if(a.size() != b.size()){
            printf("NO\n");
            continue;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool ok = true;
        for(int i=0;i<a.size();++i){
            if(a[i].first != b[i].first || a[i].second != b[i].second){
                ok = false;
                break;
            }
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}