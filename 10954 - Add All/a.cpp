#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
	int N;
	while (scanf("%d", &N), N!=0)
	{
		int x;
		v.clear();
		for(int i =0;i<N;++i)
		{
			scanf("%d",&x);
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		long long tot=0;
		long long prev=v[0];
		for(int i=1;i<N;++i)
		{
			prev += (long long) v[i];
			tot += prev;
		}
		printf("%lld\n", tot);
	}
	return 0;
}