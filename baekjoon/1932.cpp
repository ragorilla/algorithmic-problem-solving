#include <iostream>

using namespace std;

#define MAX_N	500

int n;
int triangle[MAX_N][MAX_N];
int cache[MAX_N][MAX_N];

inline int MAX(int a, int b)
{
	return (a > b ? a : b);
}

int getMaxSum(int y, int x)
{
	if (y >= n) return 0;

	int& ret = cache[y][x];
	if (ret > -1) return ret;

	int maxSum = 0, curSum;
	curSum = getMaxSum(y + 1, x);
	maxSum = MAX(curSum, maxSum);

	curSum = getMaxSum(y + 1, x + 1);
	maxSum = MAX(curSum, maxSum);

	return (ret = maxSum + triangle[y][x]);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i + 1; ++j)
		{
			cin >> triangle[i][j];
			cache[i][j] = -1;
		}
	}
		
	cout << getMaxSum(0, 0);
	return 0;
}