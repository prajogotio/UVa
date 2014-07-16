#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int, vector<int> > pos;
int main()
{
	int N,M,k,q;
	while(scanf("%d %d",&N,&M) != EOF)
	{
		pos.clear();
		for(int i=1;i<=N;++i)
		{
			scanf("%d",&k);
			if(pos.find(k) != pos.end())
			{
				pos[k].push_back(i);
			}
			else
			{
				pos.insert(make_pair(k,vector<int>(1,i)));
			}
		}
		for(int i=0;i<M;++i)
		{
			scanf("%d %d",&k, &q);
			if(pos.find(q) != pos.end() && pos[q].size() >= k)
			{
				printf("%d\n", pos[q][k-1]);
			}
			else
			{
				printf("0\n");
			}
		}
	}
	return 0;
}