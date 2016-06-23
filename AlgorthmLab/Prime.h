#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

const int MAX_V = 100;//最大点的数量
const int INF = 1000000;//无穷

int cost[MAX_V][MAX_V];//表示图
std::vector<int> rec;//表示最小生成树
int mincost[MAX_V];//统计从目前最小生成树到每个节点的最低消耗
bool used[MAX_V];//统计已经在最小生成树中的节点
int V;//节点的个数

int Prime()
{
	//初始化
	for (int i = 0;i < V;++i)
	{
		mincost[i] = INF;
		used[i] = false;
	}
	rec.clear();
	//把起点的最低消耗设置为0
	mincost[0] = 0;
	//最小生成树的消耗
	int res = 0;
	while (1)
	{
		int v = -1;
		for (int u = 0;u < V;++u)
		{
			//遍历所有点，找出没有加入最小生成树的点中可加入的最低消耗点标记为v
			if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
		}
		//若v==-1则没有可加入的点，此时最小生成树已经生成完毕
		if (v == -1) break;
		//若找到了这个点，则加入最小生成树，并更新消耗值
		used[v] = true;
		rec.push_back(v);
		res += mincost[v];
		//以新加入的这个点为基础，更新最小生成树中点到图中所有点的最低消耗
		for (int u = 0;u < V;++u)
		{
			mincost[u] = std::min(mincost[u], cost[v][u]);
		}
	}
	return res;
}

void EXP3_Prime() {
	using namespace std;
	for (int i = 0;i < MAX_V;++i)
	{
		for (int j = 0;j < MAX_V;++j)
		{
			cost[i][j] = INF;
		}
	}
	cout << "请输入节点的个数" << endl;
	cin >> V;
	
	cout << "请依次输入每条边的起点，终点和边权，输入三个0结束输入" << endl;
	while (true)
	{
		int s, e, c;
		cin >> s >> e >> c;
		if (!(s | e | c))
		{
			break;
		}
		else cost[s][e] = c;
	}
	Prime();
	cout << "加入生成树的顺序依次为：" << endl;
	for (int i = 0;i < rec.size();++i) cout << rec[i] << " ";
	cout << endl;
}

/*
请输入节点的个数
4
请依次输入每条边的起点，终点和边权，输入三个0结束输入
0 1 2
0 2 3
0 3 10
1 2 5
1 3 4
2 3 2
0 0 0
起点0 终点2 边权3
起点0 终点1 边权2
起点2 终点3 边权2
请输入节点的个数
4
请依次输入每条边的起点，终点和边权，输入三个0结束输入
0 1 2
0 2 3
0 3 10
1 2 5
1 3 4
2 3 2
0 0 0
加入生成树的顺序依次为：
0 1 2 3
请按任意键继续. . .
*/
