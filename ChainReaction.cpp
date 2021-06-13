
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
int bs(vpi & v, int val)
{
	int l = 0, r = v.size() - 1;
	int ans = -1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (v[m].ff >= val)
		{
			ans = m;
			r = m - 1;
		} else
		{
			l = m + 1;
		}
	}
	return ans;
}
int dp[maxn + 10][10];
int solve(int s, int n, int f, vpi & v)
{
	if (s < 0)
	{
		return 0;
	}
	if (dp[s][f] != -1)
	{
		return dp[s][f];
	}
	int ans = INT_MAX;
	if (s == n - 1)
	{
		int val = (v[s].ff - v[s].ss);

		int idx = bs(v, val);
		int ans1 = (s - idx) + solve(idx - 1, n, 0, v);
		int ans2 = 1 + solve(s - 1, n, 1, v);
		ans = min(ans1, ans2);
	} else
	{


		int val = (v[s].ff - v[s].ss);

		int idx = bs(v, val);
		int ans1 = (s - idx) + solve(idx - 1, n, 0, v);
		ans = ans1;
		if (f == 1) {
			int ans2 = 1 + solve(s - 1, n, 1, v);
			ans = min(ans, ans2);
		}
	}
	// cout << s << " " << ans << endl << endl;
	return dp[s][f] = ans;

}
void runcases(int T)
{

	int n;
	cin >> n;
	vpi v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].ff;
		cin >> v[i].ss;
	}
	memset(dp, -1, sizeof(dp));
	int f = solve(n - 1, n, 0, v);

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
