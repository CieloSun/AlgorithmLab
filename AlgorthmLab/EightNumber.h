#pragma once
#include<algorithm>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;
int endMaze[3][3] =
{
	{ 1,2,3 },{ 8,0,4 },{ 7,6,5 }
};

class Maze
{
public:
	int p[3][3];
	int ei, ej;
	Maze(int temp[3][3])
	{

		for (int i = 0;i < 3;++i)
		{
			for (int j = 0;j < 3;++j)
			{

				p[i][j] = temp[i][j];
				if (!p[i][j])
				{
					ei = i;
					ej = j;
				}

			}
		}

	}
	bool valid(int x, int y) const
	{
		if (0 <= x&&x <= 2 && 0 <= y&&y <= 2) return true;
		return false;
	}
	bool left()
	{
		if (!valid(ei, ej - 1)) return false;
		swap(p[ei][ej], p[ei][ej - 1]);
		--ej;
		return true;
	}
	bool right()
	{
		if (!valid(ei, ej + 1)) return false;
		swap(p[ei][ej], p[ei][ej + 1]);
		++ej;
		return true;
	}
	bool up()
	{
		if (!valid(ei - 1, ej)) return false;
		swap(p[ei][ej], p[ei - 1][ej]);
		--ei;
		return true;
	}
	bool down()
	{
		if (!valid(ei + 1, ej)) return false;
		swap(p[ei][ej], p[ei + 1][ej]);
		++ei;
		return true;
	}
	bool success() const
	{
		for (int i = 0;i < 3;++i)
		{
			for (int j = 0;j < 3;++j)
			{
				if (p[i][j] != endMaze[i][j]) return false;
			}
		}
		return true;
	}
	bool operator== (const Maze &a)
	{
		for (int i = 0;i < 3;++i)
		{
			for (int j = 0;j < 3;++j)
			{
				if (p[i][j] != a.p[i][j]) return false;
			}
		}
		return true;
	}
	int herustic() const
	{
		int res = 0;
		for (int i = 0;i < 3;++i)
		{
			for (int j = 0;j < 3;++j)
			{
				//if (p[i][j] == endMaze[i][j] && endMaze[i][j]) res++;
				for (int k = 0;k < 3;++k)
				{
					for (int h = 0;h < 3;++h)
					{
						if (p[i][j] == endMaze[k][h])
						{
							res += abs(i - k) + abs(j - h);
						}
					}
				}
			}
		}
		return res;
	}
	bool operator < (const Maze &a) const
	{
		return a.herustic() < herustic();
	}
	void print() const
	{
		cout << endl;
		for (int i = 0;i < 3;++i)
		{
			for (int j = 0;j < 3;++j)
			{
				cout << p[i][j] << " ";
			}
			cout << endl;
		}
		cout << herustic() << endl;
	}
};
int dfs(Maze maze)
{
	vector<Maze> v;
	int cnt = 0;
	int d = 0;//0down,1left,2right,3up
	while (!maze.success())
	{
		Maze tmp = maze;
		d = (d + 1) % 4;
		switch (d)
		{
		case 0:
			maze.down() || maze.left() || maze.right() || maze.up();break;
		case 1:
			maze.left() || maze.down() || maze.right() || maze.up();break;
		case 2:
			maze.right() || maze.down() || maze.left() || maze.up();break;
		case 3:
			maze.up() || maze.down() || maze.left() || maze.right();break;
		}
		if (std::find(v.begin(), v.end(), maze) == v.end())
		{
			v.push_back(maze);
			maze.print();
			cnt++;
		}
		else maze = tmp;
	}
	return cnt;
}
int bfs(Maze maze)
{
	vector<Maze> visited;
	visited.clear();
	queue<Maze> q;
	q.push(maze);
	int cnt = 0;
	while (q.size())
	{
		Maze temp = q.front();q.pop();
		visited.push_back(temp);
		cnt++;
		if (temp.success())
		{
			cout << "Success!" << endl;
			return cnt;
		}
		if (temp.left() && find(visited.begin(), visited.end(), temp) == visited.end())
		{
			q.push(temp);
			temp.right();
		}
		if (temp.up() && find(visited.begin(), visited.end(), temp) == visited.end())
		{
			q.push(temp);
			temp.down();
		}
		if (temp.right() && find(visited.begin(), visited.end(), temp) == visited.end())
		{
			q.push(temp);
			temp.left();
		}
		if (temp.down() && find(visited.begin(), visited.end(), temp) == visited.end())
		{
			q.push(temp);
			temp.up();
		}
	}
	cout << "FAIL" << endl;
	return cnt;
}
int bestFirst(Maze maze)
{
	vector<Maze> visited;
	visited.clear();
	priority_queue<Maze> pq;
	pq.push(maze);
	int cnt = 0;
	while (pq.size())
	{
		Maze temp = pq.top();pq.pop();
		visited.push_back(temp);
		cnt++;
		//temp.print();
		if (temp.success())
		{
			cout << "Success!" << endl;
			temp.print();
			return cnt;
		}
		if (temp.left() && find(visited.begin(), visited.end(), temp) == visited.end())
		{
			pq.push(temp);
			temp.right();
		}
		if (temp.up() && find(visited.begin(), visited.end(), temp) == visited.end())
		{
			pq.push(temp);
			temp.down();
		}
		if (temp.right() && find(visited.begin(), visited.end(), temp) == visited.end())
		{
			pq.push(temp);
			temp.left();
		}
		if (temp.down() && find(visited.begin(), visited.end(), temp) == visited.end())
		{
			pq.push(temp);
			temp.up();
		}
	}
	cout << "FAIL" << endl;
	return cnt;
}