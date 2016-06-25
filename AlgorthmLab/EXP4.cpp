#include "EightNumber.h"
#include <ctime>
#include <cstdlib>
void EXP4()
{
	int temp[3][3];
	int cnt = 0;
	for (int i = 0;i < 3;++i)
	{
		for (int j = 0;j < 3;++j)
		{
			temp[i][j] = cnt++;
		}
	}

	srand(time(0));
	for (int t = 0;t < 100;++t)
	{
		int i = rand() % 3;
		int j = rand() % 3;
		int k = rand() % 3;
		int h = rand() % 3;
		swap(temp[i][j], temp[k][h]);
	}

	cout << "��ʼ״̬��" << endl;
	Maze maze(temp);
	maze.print();
	cout << bestFirst(maze) << endl;
	//cout << bfs(temp) << endl;
	//cout << dfs(maze) << endl;
}

int main()
{
	//��ѡ������01�������ݻ�����ȫ�������ݣ�����1��Ϊ01����������0��Ϊ��ȫ����)
	//dataproduct(1);
	EXP4();
}