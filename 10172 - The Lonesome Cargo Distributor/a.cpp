#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int TC;
	scanf("%d",&TC);
	while(TC--)
	{
		int N,S,Q;
		scanf("%d%d%d",&N,&S,&Q);
		int tot=0;
		vector< queue<int> > ct(N+3);
		for(int i=1;i<=N;++i)
		{

			int nQ;
			scanf("%d",&nQ);
			tot+=nQ;
			while(nQ--)
			{
				int M;
				scanf("%d",&M);
				ct[i].push(M);
			}
		}
		vector<int> st;
		int min = -2;
		int station = 1;
		while(tot)
		{
			//printf("move to %d\n", station);
			min += 2;
			while(!st.empty())
			{
				int top = st.back();
				if (top == station)
				{
					st.pop_back();
					--tot;
					++min;
					//printf("store %d at %d\n", top, station);
				}
				else
				{
					if(ct[station].size() < Q)
					{
						ct[station].push(top);
						st.pop_back();
						++min;
						//printf("queue %d at %d\n", top, station);
					}
					else
						break;
				}
			}

			while(st.size() < S && !ct[station].empty())
			{
				st.push_back(ct[station].front());
				ct[station].pop();
				++min;
			}

			station = station + 1;
			if(station > N) station = 1;
		}

		printf("%d\n", min);
	}

	return 0;
}