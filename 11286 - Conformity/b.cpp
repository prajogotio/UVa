#include <map>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

map<vector<int>, int> pp;
bool comp(pair<vector<int>, int> L, pair<vector<int>, int> R)
{
	return L.second < R.second;
}

int main()
{
	int N;
	while(scanf("%d",&N), N != 0)
	{
		pp.clear();
		for(int i=0;i<N;++i)
		{
			vector<int> p;
			for(int j=0;j<5;++j)
			{
				int k;
				scanf("%d",&k);
				p.push_back(k);
			}
			sort(p.begin(),p.end());
			++pp[p];
		}
		map<vector<int>,int>::iterator it;
		it = max_element(pp.begin(),pp.end(), comp);
		int val = it->second;
		int ans = 0;
		for(it = pp.begin(); it != pp.end(); ++it)
		{
			if(it->second == val)
				++ans;
		}
		printf("%d\n", ans*val);
		/*
		for(it = pp.begin(); it != pp.end(); ++it)
		{
			for(int i=0;i<5;++i)
			{
				cout<<it->first[i]<<" ";
			}
			cout<<endl;
			printf("%d\n", it->second);
		}
		*/
	}
	return 0;
}