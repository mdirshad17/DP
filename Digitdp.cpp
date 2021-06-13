#include<bits/stdc++.h>
using namespace std;
vector<int> getdigits(int a)
{
	std::vector<int> v;
	while (a)
	{
		v.push_back(a % 10);
		a = a / 10;
	}
	return v;
}
int dp[10][180][2];
int get_digit_sum(vector<int> b, int n, int tight, int sum)
{
	if (n == -1)
		return sum;
	if (dp[n][sum][tight] != -1 && !tight)
	{
		return dp[n][sum][tight];
	}
	int k = (tight) ? b[n] : 9;
	int ret = 0;
	for (int i = 0; i <= k; i++)
	{
		int new_t = tight;
		if (i != b[n])
		{
			new_t = 0;
		}
		ret += get_digit_sum(b, n - 1, new_t, sum + i);
	}
	if (!tight)
	{
		dp[n][sum][tight] = ret;
	}
	return ret;
}
int solve(int a, int b)
{
	vector<int> a1 = getdigits(a - 1);
	vector<int> b1 = getdigits(b);
	memset(dp, -1, sizeof(dp));
	int ans1 = get_digit_sum(a1, a1.size() - 1, 1, 0);
	int ans2 = get_digit_sum(b1, b1.size() - 1, 1, 0);
	return (ans2 - ans1) ;

}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << solve(a, b) << endl;
}