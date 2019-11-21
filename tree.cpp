#include<stdio.h>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
vector <int> vec;
// 트리는 사이클이 없어야 하며 연결되어있어야 한다. 루트 노드는 하나만 있다. 나머지 노드는 자리를 가리키는 간선 하나만 존재.
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
			// 초기화 
		}
		else if (first == -1 && second == -1)
			return 0;
	}
}