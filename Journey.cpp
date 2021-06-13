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
const int maxn = 5e3 + 2;
vpi adj[maxn];
// int maxcits[maxn];
int parent[maxn];
int dfs(int s, int t)
{

	if (t < 0)
	{
		return INT_MIN;
	}
	if (s == 1)
	{
		return 1;
	}
	int c = 1;
	int ans = INT_MIN;
	int par = -1;
	for (auto x : adj[s])
	{
		int w = x.ss;
		int n = x.ff;
		int v = dfs(n, t - w);
		if (ans < v)
		{
			parent[s] = n;
			ans = v;
		}
		// max(dfs(n, t - w), ans);
	}
	c += ans;
	return c;

}
void runcases(int T)
{

	int n, m, t;
	cin >> n >> m >> t;
	while (m--)
	{
		int x, y, tx;
		cin >> x >> y >> tx;
		adj[y].pb({x, tx});
	}
	// cout << maxn << endl;
	int f = dfs(n, t);
	cout << f << endl;
	int i = n;
	vector<int> res;
	while (i != 0)
	{
		// cout << i << " ";
		res.pb(i);
		i = parent[i];
	}
	reverse(all(res));
	int l = res.size();
	assert(l == f);
	for (int x : res)
	{
		cout << x << " ";
	} cout << endl;

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
