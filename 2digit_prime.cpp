#include<stdio.h>
#pragma warning(disable:4996)
int arr[100001];
int num[10];
int check[100];
int cnt;
void swap(int arr[], int i, int j)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void perm(int i, int n)
{
	int j;
	if (i == n - 1)
	{

	}
	else
	{
		for (j = i; j < n; j++)
		{
			swap(num, i, j);
			perm(i + 1, n);
			swap(num, i, j);
		}
	}

}
void sosu()
{
	for (int i = 2; i < 100001; i++)
	{
		for (int j = 2; i * j < 100001; j++)
		{
			arr[i * j] = 1;
		}
	}
}
int main()
{
	int Test;
	scanf("%d", &Test);
	arr[1] = 1;
	for (int i = 0; i < Test; i++)
	{
		int A;
		int B;
		scanf("%d %d", &A, &B);
		num[10] = { 0, };
		check[100] = { 0, };
		cnt = 0;
		for (int i = A; i <= B; i++)
		{

			int index = 0;
			for (int j = 0; ; j++, index++)
			{
				if (i == 0)
					break;
				else
				{
					num[j] = i % 10;
					i = i / 10;
				}
			}


		}
	}
}