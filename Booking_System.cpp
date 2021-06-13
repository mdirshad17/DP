// Booking system
// How to retrack the Path in dp
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
vpi vp;
vi v;
int dp[1002][1002];
// vi f;
int par[1002][1002];
int solve(int n, int k)
{
	// cout << k << " " << n << endl;
	if (k == 0 || n == 0)

	{
		return 0;
	}
	if (dp[n][k] != -1)
	{
		return dp[n][k];
	}
	int ans = INT_MIN;
	if (vp[n - 1].ff <= v[k - 1])
	{

		// f.push_back(v[k - 1]);
		int val = vp[n - 1].ss + solve(n - 1, k - 1);
		if (val > ans)
		{
			par[n][k] = 0;
			ans = val;
		}
	}
	int v = solve(n - 1, k);
	if (v > ans)
	{
		ans = v;
		par[n][k] = 1;
	}
	v = solve(n, k - 1);
	if (v > ans)
	{
		ans = v;
		par[n][k] = 2;
	}
	return  dp[n][k] = ans;
}
void runcases(int T)
{
	int n;
	cin >> n;
	int x, y;
	vector<pair<pii, int> > grps;
	vpi tables;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		vp.pb({x, y});
		grps.pb({vp.back(), i});
	}

	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> x;
		v.pb(x);
		tables.pb({x, i});
	}
	sort(all(v));
	sort(all(vp));
	sort(all(grps));
	sort(all(tables));
	memset(dp, -1, sizeof(dp));
	int ans = solve(n, k);
	// cout << ans << endl;
	vpi res;
	int i = n, j = k;
	int f = 0;
	while (i > 0 && j > 0)
	{
		if (par[i][j] == 0)
		{
			res.pb({grps[i - 1].ss + 1, tables[j - 1].ss + 1});
			i--;
			j--;
			f += vp[i].ss;
		} else if (par[i][j] == 1)
		{
			// res.pb({grps})
			i--;
		} else
		{
			j--;
		}
	}
	// cout << f << " ";
	assert(f == ans);
	cout << res.size() << " " << ans << endl;

	for (auto x : res)
	{
		cout << x.ff << " " << x.ss << endl;
	}




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
