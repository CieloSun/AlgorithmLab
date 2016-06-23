#pragma once
//Not tested
#include <iostream>
#include <vector>
#include <algorithm>


const int MAX_N = 10000;

class UNION_FIND_SET
{
private:
	int par[MAX_N];
public:
	UNION_FIND_SET()
	{
		init(0);
	}
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

struct Edge
{
	int from;
	int to;
	int weight;
};

struct Graph
{
	int node_number;
	UNION_FIND_SET NodeList;
	std::vector<Edge> EdgeList;
	void input(Edge E)
	{
		EdgeList.push_back(E);
		NodeList.unite(E.from, E.to);
	}
};

bool compare(const Edge &a, const Edge &b)
{
	return a.weight > b.weight;
}

Graph T;
Graph G;

void Kruskal()
{
	//����Ȩ����ͼ�����б�
	std::sort(G.EdgeList.begin(), G.EdgeList.end(), compare);
	T.EdgeList.clear();
	T.NodeList.init(G.node_number);
	//һֱ���е�N-1���߼���ʹ���е����
	while (T.EdgeList.size() < G.node_number - 1)
	{
		//��ȡ��Ȩ��С�ı�
		Edge temp = G.EdgeList.back();
		G.EdgeList.pop_back();
		//�ж��Ƿ��γɻ�·,���ǣ������
		if (T.NodeList.find(temp.from) != T.NodeList.find(temp.to))
		{
			T.input(temp);
		}
	}
}

void EXP3_Kruskal() {
	using namespace std;
	G.EdgeList.clear();
	cout << "������ڵ�ĸ���" << endl;
	cin >> G.node_number;
	cout << "����������ÿ���ߵ���㣬�յ�ͱ�Ȩ����������0��������" << endl;
	while (true)
	{
		Edge tmp;
		cin >> tmp.from >> tmp.to >> tmp.weight;
		if (!(tmp.from|tmp.to|tmp.weight))
		{
			break;
		}
		else G.EdgeList.push_back(tmp);
	}
	Kruskal();
	while (T.EdgeList.size())
	{
		cout << "���" << T.EdgeList.back().from << " ";
		cout << "�յ�" << T.EdgeList.back().to << " ";
		cout << "��Ȩ" << T.EdgeList.back().weight << endl;
		T.EdgeList.pop_back();
	}
}