#include <iostream>
#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<string, pair<int,int> > > player;
int ans[5], mark[10];
int curA, curD;
int A,D;
int b[5], tempA, tempD;

int main(){
	int TC, T=1;
	string name;
	int a,d;
	scanf("%d", &TC);
	while(TC--){
		player.clear();
		curA = curD = A = D = 0;
		for(int i=0;i<10;++i){
			mark[i] = 0;
			cin >> name >> a >> d;
			A += a;
			D += d;
			player.push_back(make_pair(name, make_pair(a,d)));
		}
		sort(player.begin(), player.end());
		for(b[0] = 0; b[0] < 10; ++ b[0])
			for(b[1] = b[0]+1; b[1] < 10; ++b[1])
				for(b[2] = b[1]+1; b[2] < 10; ++b[2])
					for(b[3] = b[2] + 1; b[3] < 10; ++ b[3])
						for(b[4] = b[3] +1; b[4] <10; ++b[4]){
							tempA = tempD = 0;
							for(int i=0;i<5;++i){
								tempA += player[b[i]].second.first;
								tempD += player[b[i]].second.second;
							}
							tempD = D - tempD;
							if(curA < tempA || (curA == tempA && curD < tempD) ){
								for(int i=0;i<5;++i){
									ans[i] = b[i];
									curA = tempA;
									curD = tempD;
								}
							}
						}
		printf("Case %d:\n", T++);
		printf("(");
		for(int i=0;i<5;++i){
			cout << player[ans[i]].first;
			mark[ans[i]] = 1;
			if(i != 4) printf(", ");
		}
		printf(")\n");
		printf("(");
		for(int i=0, j=0;i<10;++i){
			if(mark[i]) continue;
			cout << player[i].first;
			++j;
			if(j != 5) printf(", ");
		}
		printf(")\n");
	}
	return 0;
}