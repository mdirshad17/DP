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
const int maxn = 1e6 + 1;
int par[maxn];
int dp[maxn];
void precalculate()
{
	// par[1] = 1;
	dp[1] = 0;
	for (int i = 2; i < maxn; i++)
	{
		int ans = inf;
		bool f1 = (i % 2 == 0);
		bool f2 = (i % 3 == 0);
		if (f1 && f2)
		{
			int v = 1 + dp[i / 2];
			if (v < ans)
			{
				ans = v;
				par[i] = i / 2;
			}
			v = 1 + dp[i / 3];
			if (v < ans)
			{
				ans = v;
				par[i] = i / 3;
			}
		} else if (f1)
		{
			int v = 1 + dp[i / 2];
			if (v < ans)
			{
				ans = v;
				par[i] = i / 2;
			}
			v = 1 + dp[i - 1];
			if (v < ans)
			{
				ans = v;
				par[i] = i - 1;
			}
		} else if (f2)
		{
			int v = 1 + dp[i / 3];
			if (v < ans)
			{
				ans = v;
				par[i] = i / 3;
			}
			v = 1 + dp[i - 1];
			if (v < ans)
			{
				ans = v;
				par[i] = i - 1;
			}
		} else
		{
			int v = 1 + dp[i - 1];
			if (v < ans)
			{
				ans = v;
				par[i] = i - 1;
			}
		}
		dp[i] = ans;
	}
}
void runcases(int T)
{

	int n;
	cin >> n;
	cout << dp[n] << endl;
	while (n)
	{
		cout << n << " ";
		n = par[n];
	} cout << endl;


}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	cin >> T;
	precalculate();
	for (int t = 1; t <= T; t++) {
		runcases(t);
	}

	return 0;
}
