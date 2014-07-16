#include <cstdio>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <string>
using namespace std;

typedef queue< pair<int,int> > qii;

qii q;
vector< int > stack;

int main()
{
	int tc;
	scanf("%d",&tc);
	bool flag = false;
	while(tc--)
	{
		if(flag) printf("\n");
		int n,t,m;
		scanf("%d %d %d",&n,&t,&m);

		stack.clear();
		for(int i=0;i<m;++i)
		{
			int T;
			string str;
			cin>>T;
			cin>>str;
			if(str == "left")
			{
				q.push(make_pair(T, 0));
			}
			else
				q.push(make_pair(T, 1));
		}
		int s = 0, mtime=-t;
		int st = 0;
		while(!q.empty())
		{
			mtime +=t;
			pair<int,int> qf = q.front();
			if(qf.second != s)
			{
				if(mtime < qf.first)
				{
					mtime = qf.first;
					s = (s+1)%2;
					continue;
				}
			}
			while(qf.second == s && st != n)
			{
				if(mtime < qf.first)
				{
					break;
				}
				++st;
				q.pop();
				if(q.empty()) break;
				qf = q.front();
			}
			for(int i=0;i<st;++i)
			{
				printf("%d\n", mtime+t);
			}
			st = 0;
			s = (s+1) %2;
		}
		flag = true;
	}
	return 0;
}