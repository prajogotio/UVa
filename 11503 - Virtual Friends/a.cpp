#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

vector<int> p;
vector<int> r;
map<string, int> idx;

int findset(int i) { return (p[i] == i) ? i : (p[i] = findset(p[i])); }

int main(){
	int TC, pos;
	string f1, f2;
	scanf("%d",&TC);
	while(TC--){
		int F;
		scanf("%d",&F);
		r.assign(2*F+2, 1);
		p.assign(2*F+2, 0);
		for(int i=0;i<2*F+2;++i){
			p[i] = i;
		}
		pos = 0;
		idx.clear();
		for(int k=0;k<F;++k){
			cin >> f1 >> f2;
			int pos1,pos2;
			if(idx.find(f1) != idx.end()){
				pos1 = idx[f1];
			} else {
				pos1 = pos;
				idx[f1] = pos;
				++pos;
			}

			if(idx.find(f2) != idx.end()){
				pos2 = idx[f2];
			} else {
				pos2 = pos;
				idx[f2] = pos;
				++pos;
			}

			int x = findset(pos1), y = findset(pos2), tot;
			//printf("%d %d %d %d\n", x, y, r[x], r[y]);
			if(x != y){
				tot = r[x] + r[y];
				p[x] = y;
				r[y] = tot;
			} else {
				tot = r[x];
			}

			printf("%d\n",tot);
		}
	}
	return 0;
}
