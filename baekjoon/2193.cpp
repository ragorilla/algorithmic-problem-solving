#include <iostream>

using namespace std;

#define MAX_N	91

int N;
long long cache[MAX_N][2];

long long getNumOfPinaryNums(int pos, int num)
{
	long long& ret = cache[pos][num];
	if (ret > 0) return ret;

	long long numOfPinaryNums = getNumOfPinaryNums(pos + 1, 0);
	if(num == 0) numOfPinaryNums += getNumOfPinaryNums(pos + 1, 1);

	return (ret = numOfPinaryNums);
}

int main()
{
	cin >> N;
	cache[N][0] = 2;
	cache[N][1] = 1;

	if (N == 1) cout << "1";
	else cout << getNumOfPinaryNums(2, 1);
	return 0;
}