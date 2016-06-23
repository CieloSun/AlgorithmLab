#include<cstdio>
namespace DFS
{
	int n, M, P, amount;//物品的个数，背包的容量，最大价值，每种物品的数量
	int v[10000], w[10000], tmp[10000], bestx[10000];//物品的价值，物品的重量，tmp[i]暂存物品的选中情况,物品的选中情况
}

void Backtrack(int i, int cv, int cw)
{ //cv当前包内物品价值,cw当前包内物品重量
	int j;
	if (i > DFS::n)//回溯结束
	{
		if (cv > DFS::P)
		{
			DFS::P = cv;
			for (i = 0;i <= DFS::n;++i) DFS::bestx[i] = DFS::tmp[i];
		}
	}
	else
		for (j = 0;j <= DFS::amount;j++)//01背包，1改为n则为完全背包
		{
			DFS::tmp[i] = j;
			if (cw + DFS::tmp[i] * DFS::w[i] <= DFS::M)
			{
				cw += DFS::w[i] * DFS::tmp[i];
				cv += DFS::v[i] * DFS::tmp[i];
				Backtrack(i + 1, cv, cw);
				cw -= DFS::w[i] * DFS::tmp[i];
				cv -= DFS::v[i] * DFS::tmp[i];
			}
		}
}

void EXP2_TREE()
{
	printf("树搜索:\n");
	printf("输入每种物品的数量:\n");
	scanf_s("%d", &DFS::amount);
	int i;
	DFS::P = 0;
	printf("请输入背包最大容量:\n");
	scanf_s("%d", &DFS::M);
	printf("请输入物品个数:\n");
	scanf_s("%d", &DFS::n);
	printf("请依次输入物品的重量:\n");
	for (i = 1;i <= DFS::n;i++)
		scanf_s("%d", &DFS::w[i]);
	printf("请依次输入物品的价值:\n");
	for (i = 1;i <= DFS::n;i++)
		scanf_s("%d", &DFS::v[i]);
	Backtrack(1, 0, 0);
	printf("最大价值为:\n");
	printf("%d\n", DFS::P);
	printf("被选中的物品依次是(数字表示选中的个数)\n");
	for (i = 1;i <= DFS::n;i++)
		printf("%d ", DFS::bestx[i]);
	printf("\n");
}