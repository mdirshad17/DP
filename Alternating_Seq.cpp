#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long int
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vpi vector<pair<int,int>>
#define pii pair<int,int>
#define pb push_back
#define inf 1e18
#define ff first
#define ss  second
#define deb(x) cout<<#x<<" "<<x<<endl;
#define all(x) x.begin(),x.end()
#define endl "\n"
const int maxn = 2e5;
pii dp[maxn + 10][3][2];
pii solve(int s, int n, int f,  int g, vi & v)
{
	if (s >= n)
	{
		return {0, 0};
	}
	if (dp[s][f][g].ff != -1)
	{
		return dp[s][f][g];
	}
	pii ans = {INT_MIN, INT_MIN};
	if (g == 0)
	{
		int l = 0;
		if (v[s] >= 0)
		{
			l = 1;
		}
		pii x = solve(s + 1, n, l, 1, v);
		pii d = {1 + x.ff, v[s] + x.ss};
		pii c = solve(s + 1, n, f, g, v);
		if (d.ff > c.ff)
		{
			ans = d;
		} else if (d.ff == c.ff)
		{
			if (d.ss >= c.ss)
			{
				ans = d;
			} else ans = c;

		} else
		{
			ans = c;
		}
	} else
	{
		int l = 0;
		if (v[s] >= 0)
		{
			l = 1;
		}
		pii d = {INT_MIN, INT_MIN};
		if ((f ^ l) == 1)
		{
			pii x = solve(s + 1, n, l, 1, v);
			d = {1 + x.ff, v[s] + x.ss};
		}
		pii c = solve(s + 1, n, f, g, v);
		if (d.ff > c.ff)
		{
			ans = d;
		} else if (d.ff == c.ff)
		{
			if (d.ss >= c.ss)
			{
				ans = d;
			} else ans = c;

		} else
		{
			ans = c;
		}
	}
	return dp[s][f][g] = ans;


}
void runcases(int T)
{

	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i <= n + 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				dp[i][j][k] = { -1, -1};
			}
		}
	}
	pii f = solve(0, n, 0,  0, v);
	// cout << "Case #" << T << ": ";
	cout << f.ss << endl;


	// cout << "Case #" << T << ": ";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		runcases(t);
	}

	return 0;
}
