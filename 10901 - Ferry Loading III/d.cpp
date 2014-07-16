#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <utility>
#include <string>
using namespace std;

vector< queue< pair<int, int> > > q(2);
vector< int > stack;
vector< int > seq;

int main()
{
	int TC;
	scanf("%d",&TC);
	bool flag = false;
	while(TC--)
	{
		if(flag) printf("\n");
		int n,t,m;
		scanf("%d%d%d",&n,&t,&m);
		seq = vector<int>(n+3, 0);
		stack.clear();

		for(int i=0;i<m;++i)
		{
			int T;
			string str;
			cin>>T; cin>>str;
			if(str == "left")
			{
				q[0].push(make_pair(T,i));
			}
			else
				q[1].push(make_pair(T,i));
		}

		int s = 0;
		int now = -t;
		while(!q[0].empty() || !q[1].empty())
		{
			now += t;
			//printf("%d\n",now);
			if(q[s].empty()) 
			{
				s = (s+1)%2;
				continue;
			}
			if(q[s].front().first > now )
			{
				int r = (s+1)%2;
				if(q[r].front().first < q[s].front().first)
				{
					now = q[r].front().first;
					s = (s+1)%2;
					continue;
				}
				else
				{
					now = q[s].front().first;
				}
			}
			while( q[s].front().first <= now && stack.size() != n)
			{
				stack.push_back(q[s].front().second);
				q[s].pop();
				if(q[s].empty()) break;
			}

			while(!stack.empty())
			{
			//	printf("%d\n",stack.back());
				seq[stack.back()] = now+t;
				stack.pop_back();
			}
			s = (s+1) %2;
		}
		for(int i=0;i<m;++i)
		{
			printf("%d\n",seq[i]);
		}
		flag = true;
	}
	return 0;
}