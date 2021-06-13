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
const int maxn = 1e5;
int n, m;
vi v;
int dp[12][5][1010];
int solve(int s, int f, int p)
{
	if (s >= m && f)
	{
		return 1;
	}
	if (s >= m && f == 0)
	{
		return solve(0, 1, p);
	}
	if (dp[s][f][p] != -1)
	{
		return dp[s][f][p];
	}

	int ans = 0;
	if (f == 0) {

		for (int i = p; i <= n; i++)
		{
			// v.pb(i);
			ans = (ans + solve(s + 1, f, i)) % M;
			// v.pop_back();
		}
	} else
	{
		for (int i = p; i <= n; i++)
		{
			// v.pb(i);
			ans = (ans + solve(s + 1, f, i)) % M;
			// v.pop_back();
		}
	}

	return dp[s][f][p] = ans;

}
void runcases(int T)
{


	cin >> n >> m;
	memset(dp, -1, sizeof(dp));
	int f = solve(0, 0, 1);
	cout << f << endl;

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
