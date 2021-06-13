#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int par[1001][1001];
int LCS(string s, int n, string p, int m)
{
	if (n == 0 || m == 0)
	{
		return 0;
	}
	if (dp[n][m] != -1)
	{
		return dp[n][m];
	}
	int ans = INT_MIN;
	if (s[n - 1] == p[m - 1])
	{
		ans = 1 + LCS(s, n - 1, p, m - 1);
	} else
	{
		int v = LCS(s, n - 1, p, m);
		if (v > ans)
		{
			ans = v;
			par[n][m] = 1;
		}
		v = LCS(s, n, p, m - 1);
		if (v > ans)
		{
			ans = v;
			par[n][m] = 2;
		}
	}
	return dp[n][m] = ans;
}
void solve(string s, string p)
{

	memset(dp, -1, sizeof(dp));
	memset(par, 0, sizeof(par));

	int f = LCS(s, s.size(), p, p.size());
	cout << f << endl;
	// string res;
	int i = s.size();
	int j = p.size();
	string res;
	while (i > 0 && j > 0)
	{

		if (par[i][j] == 0)
		{
			res.push_back(s[i - 1]);
			i--;
			j--;
		} else if (par[i][j] == 1)
		{
			i--;
		} else
		{
			j--;
		}
	}
	// reverse it
	cout << res << endl;


}
int main()
{
	int t;
	t = 1;
	// cin >> t;
	while (t--)
	{
		string s, p;
		cin >> s >> p;
		solve(s, p);
	}
}