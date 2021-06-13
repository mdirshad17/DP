

#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int xdir[4] = { -1, 1, 0, 0};
int ydir[4] = {0, 0, -1, 1};
bool good(int x, int y, int n, int m)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}
int solve(vector<vector<int> > v, int s, int e)
{

	if (dp[s][e] != -1)
		return dp[s][e];
	int ans = 0;
	for (int i = 0; i < 4; i++)
	{
		if (good(s + xdir[i], e + ydir[i], v.size(), v[0].size()))
		{
			if ((v[s][e] + 1) == v[s + xdir[i]][e + ydir[i]])
			{
				ans = max(ans, 1 + solve(v, s + xdir[i], e + ydir[i]));
			}
		}

	}
	return dp[s][e] = ans;

}
int main()
{
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	vector<vector<int> > v(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			ans = max(1 + solve(v, i, j), ans);

		}
	}
	cout << ans << endl;

	return 0;
}