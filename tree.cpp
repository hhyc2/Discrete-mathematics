#include<stdio.h>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
vector <int> vec;
// Ʈ���� ����Ŭ�� ����� �ϸ� ����Ǿ��־�� �Ѵ�. ��Ʈ ���� �ϳ��� �ִ�. ������ ���� �ڸ��� ����Ű�� ���� �ϳ��� ����.
int main()
{
	freopen("tree.inp", "r", stdin);
	freopen("tree.out", "w", stdout);
	int first;
	int second;
	while (1)
	{
		scanf("%d %d", &first, &second);
		if (first == 0 && second == 0)
		{
			// �ʱ�ȭ 
		}
		else if (first == -1 && second == -1)
			return 0;
	}
}