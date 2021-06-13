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
const int maxn = 1e3 + 2;
vi adj[maxn];
int visited[maxn];
vi w, b;
int dp[1005][1005];
int cnt = 0;
int solve(int s, int n, vector<vector<int> > & cc, vi & gw, vi & gb, int W)
{


	// cout << s << " " << W << endl;
	cnt++;
	if (s >= n)
	{
		return 0;
	}
	if (dp[s][W] != -1)
	{
		return dp[s][W];
	}
	int one = INT_MIN;
	if (W >= gw[s])
	{
		one = gb[s] + solve(s + 1, n, cc, gw, gb, W - gw[s]);
	}
	int two = INT_MIN;
	for (int i = 0; i < cc[s].size(); i++)
	{
		if (w[cc[s][i]] <= W)
		{
			int f = b[cc[s][i]] + solve(s + 1, n, cc, gw, gb, W - w[cc[s][i]]);
			two = max(two, f);
		}
	}
	int three = solve(s + 1, n, cc, gw, gb, W);
	int ans = max({one, two, three});
	return dp[s][W] = ans;
}
void dfs(int s, vi & v)
{
	visited[s] = 1;
	v.pb(s);
	for (auto x : adj[s])
	{
		if (!visited[x])
		{
			dfs(x, v);
		}
	}
}
void runcases(int T)
{

	int n, m, W;
	cin >> n >> m >> W;
	w.resize(n + 1);
	b.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	memset(dp, -1, sizeof(dp));
	vector<vector<int> >cc;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			// cout << i << " ";
			vector<int> d;
			dfs(i, d);
			cc.pb(d);
		}
	}
	for (auto &x : cc)
	{
		sort(all(x));

	}
	vector<int> gw;
	vector<int> gb;
	int i = 0;
	for (auto x : cc)
	{
		int sumw = 0;
		int sumb = 0;
		for (int y : x)
		{
			sumw += w[y];
			sumb += b[y];
		}
		gw.pb(sumw);
		gb.pb(sumb);
		// i++;
	}
	// for (auto x : gw)
	// {
	// 	cout << x << " ";
	// } cout << endl;
	// for (auto x : gb)
	// {
	// 	cout << x << " ";
	// } cout << endl;
	n = cc.size();

	int f = solve(0, n, cc, gw, gb, W);
	// deb(cnt);
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
