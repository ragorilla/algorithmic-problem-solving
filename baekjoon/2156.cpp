#include <iostream>

using namespace std;

#define MAX_N	10000

int n;
int amount[MAX_N];
int cache[MAX_N][2];
bool cached[MAX_N][2];

inline int MAX(int a, int b)
{
	return (a > b ? a : b);
}

int getMaxAmount(int pos, int continuous)
{
	if (pos >= n) return 0;

	if (cached[pos][continuous])
		return cache[pos][continuous];

	int maxAmount = 0, curAmount;

	curAmount = getMaxAmount(pos + 1, 0);
	maxAmount = MAX(maxAmount, curAmount);

	if (continuous == 0) 
		curAmount = getMaxAmount(pos + 1, 1);
	else 
		curAmount = getMaxAmount(pos + 2, 0);

	curAmount += amount[pos];
	maxAmount = MAX(maxAmount, curAmount);

	cached[pos][continuous] = true;
	return (cache[pos][continuous] = maxAmount);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> amount[i];

	cout << getMaxAmount(0, 0);
	return 0;
}