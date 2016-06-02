#include <iostream>

using namespace std;

#define MOD	10007

int currNumOfInc[10];
int nextNumOfInc[10];

int main()
{
	int N;

	cin >> N;

	for (int i = 0; i < 10; ++i)
		currNumOfInc[i] = 1;

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			nextNumOfInc[j] = 0;
			for (int k = j; k < 10; ++k)
			{
				nextNumOfInc[j] += currNumOfInc[k];
				nextNumOfInc[j] %= MOD;
			}
		}

		for (int j = 0; j < 10; ++j)
			currNumOfInc[j] = nextNumOfInc[j];
	}

	int res = 0;
	for (int i = 0; i < 10; ++i)
	{
		res += currNumOfInc[i];
		res %= MOD;
	}

	cout << res;
	return 0;
}