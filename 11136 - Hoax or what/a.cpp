#include <set>
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
multiset<ll> s;
multiset<ll>::iterator it;

int main()
{
	int n;
	while (scanf("%d",&n), n!=0)
	{
		s.clear();
		ll tot = 0;
		
		while(n--)
		{
			int k;
			scanf("%d",&k);
			while(k > 0)
			{
				ll b;
				scanf("%lld", &b);
				s.insert(b);
				--k;
			}
			it = --(s.end());
			tot += *it;
			s.erase(it);
			it = s.begin();
			tot -= *it;
			s.erase(it);
		}
		printf("%lld\n", tot);
	}
	return 0;
}