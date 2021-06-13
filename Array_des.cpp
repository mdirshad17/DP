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
const int maxn = 1e5 + 2;
int dp[maxn][100];
int cnt = 0;
int solve(vi & v, int s, int n, int m, int val)
{
	cnt++;
	if (s >= n)
	{
		return 1;
	}
	if (dp[s][val] != -1)
	{
		return dp[s][val] % M;
	}
	if (s == 0)
	{
		if (v[s] == 0)
		{
			int ans = 0;
			for (int i = 1; i <= m; i++)
			{
				v[s] = i;
				ans += solve(v, s + 1, n, m, i);
				ans = ans % M;
				v[s] = 0;
			}
			return dp[s][val] = ans % M;
		} else
		{
			return dp[s][val] = solve(v, s + 1, n, m, val) % M;
		}
	} else
	{
		if (v[s] != 0)
		{
			if (abs(v[s] - v[s - 1]) > 1)
			{
				return 0;
			} else return dp[s][val] = solve(v, s + 1, n, m, val) % M;
		} else
		{
			int ans = 0;
			for (int i = 1; i <= m; i++)
			{	if (abs(v[s - 1] - i) <= 1)
				{
					v[s] = i;
					ans += solve(v, s + 1, n, m, i);
					ans = ans % M;
					v[s] = 0;
				}

			}
			return dp[s][val] = ans % M;
		}
	}
	return dp[s][val] = 0;
}
void runcases(int T)
{

	int n, m;
	cin >> n >> m;
	vi v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	memset(dp, -1, sizeof(dp));
	int f = solve(v, 0, n, m, 0);
	f = f % M;
	// deb(cnt);

	cout << f << endl;



	//cout<<"Case #"<<T<<": ";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	//cin >> T;
	for (int t = 1; t <= T; t++) {
		runcases(t);
	}

	return 0;
}
