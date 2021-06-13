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
vi v;
int dp[60][2];
int solve(int s, int n, int f)
{

	if (s >= n)
	{
		return 0;
	}
	if (dp[s][f] != -1 * inf)
	{
		return dp[s][f];
	}
	int ans = 0;
	if (f == 0)
	{
		ans = v[s] + solve(s + 1, n, 1);
		ans = max(ans, solve(s + 1, n, 0) - v[s]);

	} else if (f == 1)
	{
		ans = solve(s + 1, n, 0) - v[s];

		ans = min(ans, solve(s + 1, n, 1) + v[s]);

	}

	return dp[s][f] = ans;

}
void runcases(int T)
{

	int n;
	cin >> n;
	// vi v(n);
	v.resize(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	// memset(dp,-1,sizeof(dp));
	for (int i = 0; i <= n + 5; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			dp[i][j] = -1 * inf;
		}
	}
	int sumx = solve(0, n, 0);
	int bob = (sum + sumx) / 2;
	int alice = sum - bob;
	// cout << sumy << endl;
	cout << alice << " " << bob << endl;



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
