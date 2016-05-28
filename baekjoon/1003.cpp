#include <iostream>

using namespace std;

#define MAX_N	41

int numOfZero[MAX_N];
int numOfOne[MAX_N];

void solve(int n)
{
	if (numOfZero[n] != 0 || numOfOne[n] != 0)
		return;

	solve(n - 1);
	solve(n - 2);
	numOfZero[n] = numOfZero[n - 1] + numOfZero[n - 2];
	numOfOne[n] = numOfOne[n - 1] + numOfOne[n - 2];
}

int main()
{
	numOfZero[0] = numOfOne[1] = 1;

	int T;

	cin >> T;

	while (T--)
	{
		int N;

		cin >> N;
		solve(N);
		cout << numOfZero[N] << " " << numOfOne[N] << endl;
	}
	return 0;
}