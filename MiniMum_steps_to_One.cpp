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
const int maxn = 1e6 + 5;
int dp[maxn];
int par[maxn];
int solve(int n)
{
	if (n == 1)
	{
		return 0;
	}
	if (dp[n] != -1)
	{
		return dp[n];
	}

	bool f1 = (n % 2 == 0);
	bool f2 = (n % 3 == 0);
	int ans = inf;
	if (f1 && f2)
	{
		int v = min(ans, 1 + solve(n / 2));
		if (v < ans)
		{
			ans = v;
			par[n] = n / 2;
		}
		v = min(ans, 1 + solve(n / 3));
		if (v < ans)
		{
			ans = v;
			par[n] = n / 3;
		}
		// v = min(ans, 1 + solve(n - 1));
		// if (v < ans)
		// {
		// 	ans = v;
		// 	par[n] = n - 1;
		// }
	} else if (f1)
	{
		int v = min(ans, 1 + solve(n / 2));
		if (v < ans)
		{
			ans = v;
			par[n] = n / 2;
		}
		v = min(ans, 1 + solve(n - 1));
		if (v < ans)
		{
			ans = v;
			par[n] = n - 1;
		}
	} else if (f2)
	{
		int v = min(ans, 1 + solve(n / 3));
		if (v < ans)
		{
			ans = v;
			par[n] = n / 3;
		}
		v = min(ans, 1 + solve(n - 1));
		if (v < ans)
		{
			ans = v;
			par[n] = n - 1;
		}
	} else
	{	ans = 1 + solve(n - 1);
		par[n] = n - 1;
	}
	return dp[n] = ans;


}
void runcases(int T)
{

	int n;
	cin >> n;
	memset(dp, -1, sizeof(int) * (n + 1));
	int f = solve(n);
	cout << f << endl;
	while (n != 0)
	{
		cout << n << " ";
		n = par[n];
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
