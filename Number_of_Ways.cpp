// number of ways to cover the distance if you can cover the distance by taking 1,2,3 steps at once
#include <bits/stdc++.h>
using namespace std;
int dp[10001];
int solve(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	if (dp[n] != -1)
		return dp[n];
	return dp[n] = (solve(n - 1) + solve(n - 2) + solve(n - 3));
}
int main()
{
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	cout << solve(n) << " ";
}