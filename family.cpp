#include<stdio.h>
#pragma warning(disable:4996)
int visit[500001]; // ����� ������ ǥ��
int height[500001]; // ���� ǥ��
int max = 0;
int find_height(int num)
{
	int hei = 0;
	while (1)
	{
		hei++;
		if (visit[num] == 0)
			return hei;
		else
		{
			if (height[visit[num]] != 0 && visit[num] != 0) // ������ ���� ������ 
				return height[visit[num]] + hei;
			else // 0�϶�
				num = visit[num];
		}
	}
}
void find(int num)
{
	for (int i = 1; i <= num; i++)
	{
		if (visit[i] == 0)  // ��Ʈ�� �� üũ ǥ��
			continue;
		else
		{
			int value = find_height(i);
			height[i] = value; // �� �־��ֱ�
			if (max < value)
				max = value;
		}
	}
}
int main()
{
	freopen("family.inp", "r", stdin);
	freopen("family.out", "w", stdout);
	int Test;
	int num;
	int first;
	int second;
	int value;
	scanf("%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		scanf("%d", &num);
		for (int j = 0; j < num - 1; j++)
		{
			scanf("%d %d", &first, &second);
			visit[second] = first; // 0�̸� ��Ʈ 
		}
		find(num);
		printf("%d\n", max);
		max = 0;
		for (int i = 1; i <= num; i++)
		{
			visit[i] = 0;
			height[i] = 0;
		}

	}
}