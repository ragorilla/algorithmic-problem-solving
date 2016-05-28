#include <iostream>

using namespace std;

#define MAX_N	1000
#define INF		987654321

int N;
int cost[3][MAX_N];
int cache[3][MAX_N];
int cand[3][2] =
{
	{1, 2},
	{0, 2},
	{0, 1}
};

int solve(int color, int i)
{
	int& ret = cache[color][i];
	if (ret != 0) return ret;

	int minCost = INF, curCost;
	for (int j = 0; j < 2; ++j)
	{
		curCost = solve(cand[color][j], i + 1);
		if (curCost < minCost) minCost = curCost;
	}

	return (ret = cost[color][i] + minCost);
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 3; ++j)
			cin >> cost[j][i];
	}

	for (int i = 0; i < 3; ++i)
		cache[i][N - 1] = cost[i][N - 1];
	
	int minCost = INF;
	for (int i = 0; i < 3; ++i)
	{
		if (solve(i, 0) < minCost)
			minCost = cache[i][0];
	}
		
	cout << minCost;
	return 0;
}