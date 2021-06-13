#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define hM 9999999900000001
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
int dp[3][maxn];
int solve(int f, int n)
{
	if (n == 1)
	{
		return 1;
	}
	// cout << s << " " << f << endl;
	if (dp[f + 1][n] != -1)
		return dp[f + 1][n];

	int ans = 0;
	if (f == -1)
	{
		ans = solve(1, n) + solve(0, n);
	} else if (f == 0)
	{
		ans = solve(1, n - 1);
	} else if (f == 1)
	{
		ans = solve(1, n - 1) + solve( 0, n - 1);
	}
	return  dp[f + 1][n] = ans;
}
void runcases(int T)
{

	int n;
	cin >> n;
	// cout << "HEllo\n";

	int f = solve(-1, n);
	cout << f << endl;



	//cout<<"Case #"<<T<<": ";
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// freopen("error.txt", "w", stderr);
#endif

	memset(dp, -1, sizeof(dp));
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		runcases(t);
	}

	return 0;
}
