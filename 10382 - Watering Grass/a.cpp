#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <utility>
using namespace std;

const double EPS = 1e-10;
vector<pair<double,double> > sgmt;
int main(){
    int n, l, w;
    while(cin >> n >> l >> w){
        sgmt.clear();
        for(int i=0;i<n;++i){
            int r,x;
            cin >> x >> r;
            double d = (double)r*r - (double)w*w/4L;
            if(d<0)continue;
            d = sqrt(d);
            sgmt.push_back(make_pair((double)x-d,(double)x+d));
        }
        sort(sgmt.begin(), sgmt.end());
        n = sgmt.size();
        /*
        for(int i=0;i<n;++i){
            printf("%lf %lf\n", sgmt[i].first, sgmt[i].second);
        }
        */
        double cur = 0;
        int ans = 0;
        for(int i=0; cur < 1L*l;){
            bool found = false;
            double maxR = 0;
            for(;(sgmt[i].first+EPS<cur || fabs(sgmt[i].first-cur)<EPS) && i < n;++i){
                if(sgmt[i].second > maxR+EPS){
                    found = true;
                    maxR = sgmt[i].second;
                }
            }
            if(!found) break;
            //cout << maxR << endl;
            ++ans;
            cur = maxR;
        }
        if(cur < l && fabs(cur-l) > EPS) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}