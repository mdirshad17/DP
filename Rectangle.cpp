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
int dp[501][501];
int solve(int a, int b)
{
	if (a == b)
	{
		return 0;
	}
	if (a == 1 || b == 1)
	{
		abs(b - a);
	}
	if (dp[a][b] != -1)
	{
		return dp[a][b];
	}
	int ans = INT_MAX;
	for (int i = 1; i < a; i++)
	{
		ans = min(ans, 1 + solve(i, b) + solve(a - i, b));
	}
	for (int i = 1; i < b; i++)
	{
		ans = min(ans, 1 + solve(a, i) + solve(a, b - i));
	}
	return dp[a][b] = ans;
}
void runcases(int T)
{


	int a, b;
	cin >> a >> b;
	memset(dp, -1, sizeof(dp));
	int f = solve(a, b);
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
