#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

const int MAX_V = 100;//���������
const int INF = 1000000;//����

int cost[MAX_V][MAX_V];//��ʾͼ
std::vector<int> rec;//��ʾ��С������
int mincost[MAX_V];//ͳ�ƴ�Ŀǰ��С��������ÿ���ڵ���������
bool used[MAX_V];//ͳ���Ѿ�����С�������еĽڵ�
int V;//�ڵ�ĸ���

int Prime()
{
	//��ʼ��
	for (int i = 0;i < V;++i)
	{
		mincost[i] = INF;
		used[i] = false;
	}
	rec.clear();
	//�����������������Ϊ0
	mincost[0] = 0;
	//��С������������
	int res = 0;
	while (1)
	{
		int v = -1;
		for (int u = 0;u < V;++u)
		{
			//�������е㣬�ҳ�û�м�����С�������ĵ��пɼ����������ĵ���Ϊv
			if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
		}
		//��v==-1��û�пɼ���ĵ㣬��ʱ��С�������Ѿ��������
		if (v == -1) break;
		//���ҵ�������㣬�������С������������������ֵ
		used[v] = true;
		rec.push_back(v);
		res += mincost[v];
		//���¼���������Ϊ������������С�������е㵽ͼ�����е���������
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
	cout << "������ڵ�ĸ���" << endl;
	cin >> V;
	
	cout << "����������ÿ���ߵ���㣬�յ�ͱ�Ȩ����������0��������" << endl;
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
	cout << "������������˳������Ϊ��" << endl;
	for (int i = 0;i < rec.size();++i) cout << rec[i] << " ";
	cout << endl;
}

/*
������ڵ�ĸ���
4
����������ÿ���ߵ���㣬�յ�ͱ�Ȩ����������0��������
0 1 2
0 2 3
0 3 10
1 2 5
1 3 4
2 3 2
0 0 0
���0 �յ�2 ��Ȩ3
���0 �յ�1 ��Ȩ2
���2 �յ�3 ��Ȩ2
������ڵ�ĸ���
4
����������ÿ���ߵ���㣬�յ�ͱ�Ȩ����������0��������
0 1 2
0 2 3
0 3 10
1 2 5
1 3 4
2 3 2
0 0 0
������������˳������Ϊ��
0 1 2 3
�밴���������. . .
*/
