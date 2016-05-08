#include <iostream>

using namespace std;

#define MAX_N	80

int seq[MAX_N];
int lenOfSeq;

bool promising()
{
	bool goodSeq = false;
	for (int i = 1; i <= lenOfSeq / 2; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (seq[lenOfSeq - j] != seq[lenOfSeq - i - j])
			{
				goodSeq = true;
				break;
			}
		}

		if (goodSeq) goodSeq = false;
		else return false;
	}

	return true;
}

bool backtrack(int n)
{
	if (n == 0) return true;

	for (int i = 1; i <= 3; ++i)
	{
		seq[lenOfSeq++] = i;
		if (promising())
			if (backtrack(n - 1))
				return true;
		lenOfSeq--;
	}

	return false;
}

int main()
{
	int N;

	cin >> N;
	backtrack(N);

	for (int i = 0; i < lenOfSeq; ++i)
		cout << seq[i];

	return 0;
}