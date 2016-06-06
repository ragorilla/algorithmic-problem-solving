#include <iostream>

using namespace std;

#define MAX_N	41

int N, M;
bool fixedSeat[MAX_N];
int cache[MAX_N][MAX_N];

int getNumOfCases(int pos, int num)
{
	if (pos > N || num > N) return 0;
	if (pos == N) return 1;

	int& ret = cache[pos][num];
	if (ret > 0) return ret;

	if (fixedSeat[pos + 1])
		return (ret = getNumOfCases(pos + 1, pos + 1));

	if (pos >= num)
	{
		ret = getNumOfCases(pos + 1, pos + 1);

		if (!fixedSeat[pos + 2])
			ret += getNumOfCases(pos + 1, pos + 2);
	}
	else
		ret = getNumOfCases(pos + 1, pos);

	return ret;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int pos;
		cin >> pos;
		fixedSeat[pos] = true;
	}

	int numOfCases = getNumOfCases(1, 1);
	if (!fixedSeat[1] && !fixedSeat[2]) 
		numOfCases += getNumOfCases(1, 2);

	cout << numOfCases;
	return 0;
}