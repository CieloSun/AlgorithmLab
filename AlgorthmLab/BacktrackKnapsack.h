#include<cstdio>
namespace DFS
{
	int n, M, P, amount;//��Ʒ�ĸ���������������������ֵ��ÿ����Ʒ������
	int v[10000], w[10000], tmp[10000], bestx[10000];//��Ʒ�ļ�ֵ����Ʒ��������tmp[i]�ݴ���Ʒ��ѡ�����,��Ʒ��ѡ�����
}

void Backtrack(int i, int cv, int cw)
{ //cv��ǰ������Ʒ��ֵ,cw��ǰ������Ʒ����
	int j;
	if (i > DFS::n)//���ݽ���
	{
		if (cv > DFS::P)
		{
			DFS::P = cv;
			for (i = 0;i <= DFS::n;++i) DFS::bestx[i] = DFS::tmp[i];
		}
	}
	else
		for (j = 0;j <= DFS::amount;j++)//01������1��Ϊn��Ϊ��ȫ����
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
	printf("������:\n");
	printf("����ÿ����Ʒ������:\n");
	scanf_s("%d", &DFS::amount);
	int i;
	DFS::P = 0;
	printf("�����뱳���������:\n");
	scanf_s("%d", &DFS::M);
	printf("��������Ʒ����:\n");
	scanf_s("%d", &DFS::n);
	printf("������������Ʒ������:\n");
	for (i = 1;i <= DFS::n;i++)
		scanf_s("%d", &DFS::w[i]);
	printf("������������Ʒ�ļ�ֵ:\n");
	for (i = 1;i <= DFS::n;i++)
		scanf_s("%d", &DFS::v[i]);
	Backtrack(1, 0, 0);
	printf("����ֵΪ:\n");
	printf("%d\n", DFS::P);
	printf("��ѡ�е���Ʒ������(���ֱ�ʾѡ�еĸ���)\n");
	for (i = 1;i <= DFS::n;i++)
		printf("%d ", DFS::bestx[i]);
	printf("\n");
}