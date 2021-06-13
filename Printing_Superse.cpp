#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int par[1001][1001];
int SS(string s, int n, string p, int m)
{
	if (n == 0 || m == 0)
	{
		return abs(n - m);
	}
	if (dp[n][m] != -1)
	{
		return dp[n][m];
	}
	int ans = INT_MAX;
	if (s[n - 1] == p[m - 1])
	{
		ans = 1 + SS(s, n - 1, p, m - 1);
	} else
	{
		int v = 1 + SS(s, n - 1, p, m);
		if (v < ans)
		{
			ans = v;
			par[n][m] = 1;
		}
		v = 1 + SS(s, n, p, m - 1);
		if (v < ans)
		{
			ans = v;
			par[n][m] = 2;
		}
	}
	return dp[n][m] = ans;
}
void solve()
{
	string s, p;
	cin >> s >> p;
	memset(dp, -1, sizeof(dp));
	int f = SS(s, s.size(), p, p.size());
	cout << f << endl;
	int i = s.size(), j = p.size();
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
			res.push_back(s[i - 1]);
			i--;

		} else
		{
			res.push_back(p[j - 1]);
			j--;
		}
	}
	while (i > 0)
	{
		res.push_back(s[i - 1]);
		i--;
	}
	while (j > 0)
	{
		res.push_back(p[j - 1]);
		j--;
	}
	// reverse it
	cout << res << endl;


}

int main()
{
	solve();
}