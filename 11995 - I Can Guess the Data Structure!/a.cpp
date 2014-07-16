#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> stack;
priority_queue<int> pq;
queue<int> q;

int main()
{
	int N;
	while(scanf("%d",&N)!=EOF)
	{
		bool isstack = true, isq = true, ispq = true;
		stack.clear();
		queue<int> nq;
		priority_queue<int> npq;
		swap(q, nq);
		swap(pq, npq);
		for(int i=0;i<N;++i)
		{
			int cmd, n;
			scanf("%d %d", &cmd, &n);
			if(cmd == 1)
			{
				stack.push_back(n);
				pq.push(n);
				q.push(n);
			}
			if(cmd == 2)
			{
				if(isstack && !stack.empty() && stack.back() == n)
				{
					stack.pop_back();
				} else {
					isstack = false;
				}
				if(isq && !q.empty() && q.front() == n)
				{
					q.pop();
				}	else {
					isq = false;
				}
				if(ispq && !pq.empty() && pq.top() == n)
				{
					pq.pop();
				} else {
					ispq = false;
				}
			}
		}
		if(isstack && !isq && !ispq)
			printf("stack\n");
		else if(isq && !isstack && !ispq)
			printf("queue\n");
		else if(ispq && !isstack && !isq)
			printf("priority queue\n");
		else if(!ispq && !isstack && !isq)
			printf("impossible\n");
		else
			printf("not sure\n");
	}
	return 0;
}