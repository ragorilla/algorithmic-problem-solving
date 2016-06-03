#include <stdio.h>

#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MAX_N	100000

int n;
int sticker[2][MAX_N];
int cache[2][MAX_N];

void init()
{
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < n; ++j)
			cache[i][j] = -1;
}

int getMaxScore(int y, int x)
{
	if (x >= n) return 0;

	int& ret = cache[y][x];
	if (ret > -1) return ret;

	int scoreAtZero = getMaxScore(0, x + 1);
	int scoreAtOne = getMaxScore(1, x + 1);

	if (y == 0) scoreAtOne += sticker[y][x];
	else scoreAtZero += sticker[y][x];

	return (ret = MAX(scoreAtZero, scoreAtOne));
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		scanf(" %d", &n);
		init();
		
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < n; ++j)
				scanf(" %d", &sticker[i][j]);

		printf("%d\n", MAX(getMaxScore(0, 0), getMaxScore(1, 0)));
	}
	return 0;
}