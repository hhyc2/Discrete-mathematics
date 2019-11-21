#include<cstdio>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int DFS_visit[10001];
int BFS_visit[10001];
vector < vector <pair<int, int > > >vec;
int n;
int m;
int num;
int value1 = 0;
int value2 = 0;

bool compare(pair<int, int> A, pair<int, int> B)
{
	if (A.first < B.first) {
		return true;
	}

	return false;
}
void DFS(int x)
{
	DFS_visit[x]++;
	for (int i = 0; i < vec[x].size(); i++) {
		if (DFS_visit[vec[x][i].first] == 0) {
			DFS_visit[vec[x][i].first]++;
			value1 += vec[x][i].second;
			DFS(vec[x][i].first);
		}
	}
}
void BFS(int x)
{
	BFS_visit[x]++;
	queue<int> que;
	que.push(x);
	while (!que.empty()) {
		int nn = que.front();
		que.pop();

		for (int i = 0; i < vec[nn].size(); i++) {

			if (BFS_visit[vec[nn][i].first] == 0) {
				BFS_visit[vec[nn][i].first]++;
				value2 += vec[nn][i].second;
				que.push(vec[nn][i].first);
			}

		}

	}

}
int main()
{
	FILE* fp;
	FILE* fp1;
	fp = fopen("graph.inp", "r");
	fp1 = fopen("graph.out", "w");
	int Test;
	int first;
	int second;
	int value;
	int count;
	fscanf(fp, "%d", &Test);
	for (int i = 0; i < Test; i++)
	{
		fscanf(fp, "%d %d", &n, &m);
		vec.clear();
		vec.resize(n);
		for (int j = 0; j < m; j++)
		{
			fscanf(fp, "%d %d %d", &first, &second, &value);
			vec[first].push_back(make_pair(second, value));
			vec[second].push_back(make_pair(first, value));
		}
		for (int j = 0; j < n; j++)
			sort(vec[j].begin(), vec[j].end(), compare);

		fscanf(fp, "%d", &count);
		for (int j = 0; j < count; j++)
		{
			fscanf(fp, "%d", &num);
			value1 = 0;
			value2 = 0;
			DFS(num);
			BFS(num);
			fprintf(fp1, "n=%d m=%d start=%d DFS:%d BFS:%d\n", n, m, num, value1, value2);
			for (int k = 0; k <= n; k++)
			{
				DFS_visit[k] = 0;
				BFS_visit[k] = 0;
			}
		}
	}
	fclose(fp);
	fclose(fp1);
}