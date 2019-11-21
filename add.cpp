#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int arr[10000];
int main()
{
	freopen("add.inp", "r", stdin);
	freopen("add.out", "w", stdout);
	int Test;
	int num;
	while (1)
	{
		long long int value = 0;
		scanf("%d", &Test);
		if (Test == 0)
			break;
		for (int i = 0; i < Test; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + Test);
		for (int i = 0; i < Test - 1; i++)
		{
			int temp = arr[i] + arr[i + 1];
			value += temp;
			arr[i + 1] = temp;
			if (arr[i + 2] < temp&&i<Test-2)
			{
				for (int j = i + 2;; j++)
				{
					if (arr[j] > temp || j==Test-1)
					{
						sort(arr + i, arr + j+1);
						break;
					}
				}
			}
		}
		printf("%lld\n", value);

	}
	
}