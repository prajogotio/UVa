#include <cstdio>
#include <queue>
#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
using namespace std;

int main()
{
	priority_queue<pair<int, int> > q;
	vector<pair<int,int> > v;
	char s[1000];
	int Q,T,K;
	while(fgets(s, 999, stdin))
	{
		if(strcmp(s, "#\n") == 0)
			break;
		sscanf(s,"Register %d %d", &Q, &T);
		v.push_back(make_pair(T,Q));
	}
	fgets(s, 999, stdin);
	sscanf(s, "%d", &K);
	int sz = v.size();

	for(int i=0;i<sz; ++i)
	{
		int QN = v[i].second;
		int P = v[i].first;
		int nP = P;
		for(int j=0;j<=K;++j)
		{
			q.push(make_pair(-nP,-QN));
			nP += P;
		}
	}
	while(K)
	{
		int qtop = -q.top().second;
		while(qtop == -q.top().second)
		{
			printf("%d\n", -q.top().second);
			q.pop();
			--K;
			if(!K) break;
		}
	}
	return 0;
}