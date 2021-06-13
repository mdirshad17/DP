#include <bits/stdc++.h>
using namespace std;
#define M 100000000
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
int dp[110][110][11][11];
int solve(int n1, int n2, int k1, int k2, int d1, int d2)
{

	// cout << n1 << " " << n2 << " " << k1 << " " << k2 << " " << d1 << " " << d2 << endl;
	if (n1 == 0 && n2 == 0)
	{
		return 1;
	}
	if (n1 < 0 || n2 < 0)
		return 0;
	if (dp[n1][n2][d1][d2] != -1)
	{
		return dp[n1][n2][d1][d2];
	}
	int ans = 0;
	if (d1 > 0)
	{
		ans = (ans + solve(n1 - 1, n2, k1, k2, d1 - 1, k2)) % M;
	}
	if (d2 > 0)
	{
		ans = (ans + solve(n1, n2 - 1, k1, k2, k1, d2 - 1)) % M;
	}
	return dp[n1][n2][d1][d2] = ans;

}
void runcases(int T)
{

	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	memset(dp, -1, sizeof dp);
	int f = solve(n1, n2, k1, k2, k1, k2);
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
