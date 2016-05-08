#include <iostream>

using namespace std;

int main()
{
	int T;

	cin >> T;

	while (T--)
	{
		int a, b, x = 0, y = 0;

		for (int i = 0; i < 3; ++i)
		{
			cin >> a >> b;
			x ^= a;
			y ^= b;
		}

		cout << x << " " << y << endl;
	}
	return 0;
}