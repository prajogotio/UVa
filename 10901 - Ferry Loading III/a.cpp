#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int main()
{
	int TC;
	scanf("%d",&TC);
	bool flag = false;
	vector< queue< pair<int,int> > > q;
	vector< int > seq;
	vector< int > st;
	while(TC--)
	{
		if(flag) printf("\n");
		int n,t,m, mtime=0;
		scanf("%d %d %d",&n,&t,&m);
		printf("%d %d %d\n",n,t,m);
		q.clear();
		seq.clear();
		st.clear();
		seq = vector<int>(n+3,0);
		q = vector<queue<pair<int,int> > >(2);
		for(int i=0;i<m;++i)
		{
			int T;
			string str;
			cin>>T; cin>>str;
			if(str == "left")
			{
				q[0].push(make_pair(T, i));
			}
			else
				q[1].push(make_pair(T,i));
		}
		int s = 0;
		mtime = -t;
		while(!q[0].empty() || !q[1].empty())
		{
			//printf("%d %d\n",q[0].size(), q[1].size());
			mtime += t;
			while(!q[s].empty() && st.size() != n)
			{
				if(q[s].front().first > mtime)
					break;
				st.push_back(q[s].front().second);
				q[s].pop();
			}
			while(!st.empty())
			{
				seq[st.back()] = mtime+t;
				st.pop_back();
			}
			s = (s+1) % 2;
		}

		for(int i=0;i<m;++i)
		{
			printf("%d\n", seq[i]);
		}

		flag = true;
	}
	return 0;
}