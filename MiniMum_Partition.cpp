#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve(vector<int> v, int n, int sum, int csum)
{
	if (n == 0)
	{
		return abs(sum - 2 * csum);
	}
	if (dp[n][csum] != -1)
		return dp[n][csum];
	return dp[n][sum] = min(solve(v, n - 1, sum, csum + v[n - 1]), solve(v, n - 1, sum, csum));
}
int main()
{
	memset(dp, -1, sizeof(dp));
	int  n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	cout << solve(v, n, sum, 0);
}
