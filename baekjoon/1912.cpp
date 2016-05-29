#include <iostream>

using namespace std;

#define MAX_N	100000

int seq[MAX_N];

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> seq[i];

	int maxSum = seq[0];
	int cache = maxSum;
	for (int i = 1; i < n; ++i)
	{
		if (cache + seq[i] > seq[i]) cache += seq[i];
		else cache = seq[i];

		if (maxSum < cache) maxSum = cache;
	}

	cout << maxSum;
	return 0;
}