#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve(vector<int > & v, int n, int sum)
{
	if (sum == 0)
	{
		return dp[n][sum] = 1;
	}
	if (n == 0)
	{
		return dp[n][sum] = 0;
	}
	if (dp[n][sum] != -1)
		return dp[n][sum];
	if (v[n - 1] > sum)
		return dp[n][sum] = solve(v, n - 1, sum);
	return dp[n][sum] = ((solve(v, n - 1, sum - v[n - 1]) + solve(v, n - 1, sum)) >= 1);
}
int  main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	if (sum % 2 != 0)
	{
		cout << "NO\n";

	} else
	{
		memset(dp, -1, sizeof(dp));
		int x = sum / 2;
		int ans = solve(v, n, x);
		// cout << ans << endl;
		if (ans)
		{
			cout << "YES\n";
		} else
		{
			cout << "NO\n";
		}
	}

}