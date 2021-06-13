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
vector<vi> dp;
int solve(int s, int n, vi & v, int f)
{
	if (s >= n)
	{
		return 0;
	}
	if (dp[s][f] != -1)
	{
		return dp[s][f];
	}
	int ans = 0;
	if (f == 0)
	{
		ans = v[s] ^ solve(s + 1, n, v, 1);
		ans = max(ans, solve(s + 1, n, v, 0));
	}
	if (f == 1)
	{
		// Extend The xor
		ans = v[s] ^ solve(s + 1, n, v, f);
		// End the Xor here
		ans = max(ans, v[s] ^ solve(s + 1, n, v, 2));
	}
	if (f == 2)
	{
		// Just do Nothing
		ans = solve(s + 1, n, v, f);
	}
	return  dp[s][f] = ans;
}
void runcases(int T)
{

	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	dp.assign(n + 2, vi(3, -1));
	int f = solve(0, n, v, 0);
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
