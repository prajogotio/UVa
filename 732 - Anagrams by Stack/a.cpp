#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

string a,b;
vector<string> str;

void dfs(vector<int> s, int i, int j, string op)
{
	//cout<<op<<endl;
	if(j == b.size())
	{
		str.push_back(op);
		return;
	}
	if(!s.empty())
	{
		int k = s.back();
		//printf("%d\n",s.back());
		if(b[j]==a[k])
		{
			vector<int> s2(s.begin(),s.end()-1);
			string op2 = op+"o";
			dfs(s2,i,j+1,op2);
		}
	}
	if(i == a.size())
		return;
	s.push_back(i);
	op+="i";
	dfs(s,i+1,j,op);
}

int main()
{
	while(cin>>a)
	{
		cin>>b;
		str.clear();
		vector<int> s;
		string op = "";
		dfs(s,0,0,op);
		sort(str.begin(),str.end());
		cout<<"[\n";
		int len = a.size();
		for(int i=0;i<str.size();++i)
		{
			for(int j=0;j<2*len; ++j)
			{
				cout<<str[i][j];
				if(j!=2*len-1)printf(" ");
			}
			cout<<endl;
		}
		cout<<"]\n";
	}
	return 0;
}