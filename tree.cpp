#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#pragma warning(disable:4996)
using namespace std;
vector <int> vec;
vector <int> vec2;
vector <int> arr;
int size1;
int size2;
int check()
{
	sort(vec2.begin(), vec2.end());
	size1 = vec2.size();
	vec2.erase(unique(vec2.begin(), vec2.end()), vec2.end());
	size2 = vec2.size();

	if (size1 == size2)
		return 1;
	else if (vec.size() - size2 == 1)
		return 1;
	else
		return 2;
}
int process()
{
	if (size1 == size2)
	{
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		if (vec.size() - size2 == 1)
		{
			set_difference(vec.begin(), vec.end(), vec2.begin(), vec2.end(), back_inserter(arr));
			return arr[0];
		}
		else
			return -1;
	}
}
int main()
{
	freopen("tree.inp", "r", stdin);
	freopen("tree.out", "w", stdout);
	int first;
	int second;
	int i = 1;
	while (1)
	{
		scanf("%d %d", &first, &second);
		if (first == -1 && second == -1)
			return 0;
		else if (first == 0 && second == 0) // ½ÇÇà
		{
			int cnt = check();
			if (cnt == 2)
				printf("Test Case %d: -1\n", i);
			else
			{
				int value=process();
				printf("Test Case %d: %d\n", i, value);
			}
			i++;
			size1 = 0;
			size2 = 0;
			vec.clear();
			vec2.clear();
			arr.clear();
		}
		else // »ðÀÔ
		{
			vec.push_back(first);
			vec.push_back(second);
			vec2.push_back(second);
		}
	}
}

