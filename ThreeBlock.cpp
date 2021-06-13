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
vector<vector<int> > dp;
int solve(int s, int n, int f, vi & vs, vi & v)
{
	if (s >= n)
	{
		return 0;
	}
	if (dp[s][f] != -1)
	{
		return dp[s][f];
	}
	int ans = INT_MIN;
	if (f == 0)
	{
		int add = (v[s] == vs[0]);
		ans = max(ans, add + solve(s + 1, n, f, vs, v));
		int add1 = (v[s] == vs[1]);
		ans = max(ans, add1 + solve(s + 1, n, 1, vs, v));
	}
	if (f == 1)
	{
		int add = (v[s] == vs[1]);
		ans = max(ans, add + solve(s + 1, n, f, vs, v));
		int add1 = (v[s] == vs[0]);
		ans = max(ans, add1 + solve(s + 1, n, 2, vs, v));
	}
	if (f == 2)
	{
		int add1 = (v[s] == vs[0]);
		ans = max(ans, add1 + solve(s + 1, n, 2, vs, v));
	}
	return dp[s][f] = ans;
}
void runcases(int T)
{

	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int maxans = 0;
	for (int i = 1; i <= 26; i++)
	{
		for (int j = 1; j <= 26; j++)
		{
			dp.assign(n + 1, vi(3, -1));
			vector<int> vs = {i, j};
			int f = solve(0, n, 0, vs, v);
			maxans = max(maxans, f);

		}
	}
	cout << "Case #" << T << ": ";
	cout << maxans << endl;




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
