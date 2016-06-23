#pragma once
#define MAX_N 100000000
class UNION_FIND_SET
{
private:
	int par[MAX_N];
public:
	UNION_FIND_SET(int n)
	{
		init(n);
	}
	void init(int n)
	{
		for (int i = 0;i < n;++i)
		{
			par[i] = i;
		}
	}
	int find(int x)
	{
		return (par[x] == x) ? x : par[x] = find(par[x]);
	}
	void unite(int x, int y)
	{
		par[find(x)] = find(y);
	}
};