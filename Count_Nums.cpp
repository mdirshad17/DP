#include<bits/stdc++.h>
using namespace std;
vector<int> getdigits(int a)
{
	vector<int> v;
	while (a)
	{
		v.push_back(a % 10);
		a = a / 10;
	}
	return v;
}
int dp[10][2];
bool prime(int x)
{
	return (x == 2 || x == 3 || x == 5 || x == 7 || x == 11);
}
int count_nums(int s, int n, int tight, vector<int> a)
{
	if (s == n)
	{
		return 1;
	}
	if (dp[s][tight] != -1 && !tight);
	return dp[s][tight];
	int k = (tight) ? a[s] : 9;
	int ret = 0;
	for (int i = 0; i <= k; i++)
	{
		int nt = tight;
		if (a[s] != i)
			nt = 0;
		if (prime(s + 1) && prime(i))
		{
			ret += count_nums(s + 1, n, nt, a);
		}
		if (!prime(s + 1) && !prime(i))
		{
			ret += count_nums(s + 1, n, nt, a);
		}
	}
	if (!tight)
		dp[s][tight] = ret;


	return ret;

}
int solve(int a, int b)
{
	vector<int> a1 = getdigits(a - 1);
	vector<int> b1 = getdigits(b);
	memset(dp, -1, sizeof(dp));
	int ans1 = count_nums(0, a1.size(), 1, a1);
	int ans2 = count_nums(0, b1.size(), 1, b1);
	return (ans2 - ans1);
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << solve(a, b);
}