#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> q;
int main()
{
	int N;
	while (scanf("%d", &N), N!=0)
	{
		int x;
		for(int i =0;i<N;++i)
		{
			scanf("%d",&x);
			q.push(-x);
		}
		long long tot=0;
		int a,b;
		while(q.size() != 1)
		{
			a = -q.top();
			q.pop();
			b = -q.top();
			q.pop();
			tot += (long long) a + (long long) b;
			q.push(-(a+b));
		}
		q.pop();
		printf("%lld\n", tot);
	}
	return 0;
}