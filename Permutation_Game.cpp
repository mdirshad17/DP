// Graph Solution also exist
//
//
//
//
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
const int maxn = 1e5 + 10;
vi v;
int n;
int dp[maxn][2];
int cnt = 0;
int solve(int st, int f)
{
	// bool ans = false;
	// int cnt = 0;
	cnt++;
	if (dp[st][f] != -1)
	{
		return dp[st][f];
	}
	if (f == 1)
	{
		int ans = 0;
		for (int i = st; i < n; i += v[st])
		{
			if (v[st] < v[i])
			{
				int d = f ^ 1;
				if (solve(i, d) == 0)
				{
					ans = 1;
				}
			}
		}
		for (int i = st; i >= 0; i -= v[st])
		{
			if (v[st] < v[i])
			{
				int d = f ^ 1;
				if (solve(i, d) == 0)
				{
					ans = 1;
				}
			}
		}
		return dp[st][f] = ans;

	} else
	{
		// We dont need this
		int ans = 0;
		for (int i = st; i < n; i += v[st])
		{
			if (v[st] < v[i])
			{
				int d = f ^ 1;
				if (solve(i, d) == 0)
				{
					ans = 1;
				}
			}
		}
		for (int i = st; i >= 0; i -= v[st])
		{
			if (v[st] < v[i])
			{
				int d = f ^ 1;
				if (solve(i, d) == 0)
				{
					ans = 1;
				}
			}
		}
		return dp[st][f] = ans;
	}

}
void runcases(int T)
{

	// int n;
	cin >> n;
	n = n + 1;
	v.resize(n);
	for (int i = 1; i < n; i++) {
		cin >> v[i];

	}
	for (int i = 0; i < (n + 2); i++)
	{
		for (int j = 0; j < 2; j++)
		{
			dp[i][j] = -1;
		}
	}
	string res;
	for (int i = 1; i < n; i++)
	{

		int f = solve(i, 1);
		res += 'B' - f;
	}
	// deb(cnt);
	cout << res << endl;



}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	// cin >> T;
	for (int t = 1; t <= T; t++) {
		runcases(t);
	}

	return 0;
}
