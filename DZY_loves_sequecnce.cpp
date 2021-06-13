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
void runcases(int T)
{

	int n;
	cin >> n;
	vi v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int dp[n];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i < n; i++)
	{
		if (v[i] > v[i - 1])
		{
			dp[i] = 1 + dp[i - 1];
		} else
		{
			dp[i] = 1;
		}
	}
	int dp1[n];
	dp1[n - 1] = 1;
	for (int i = n - 2; i >= 0; i--)
	{
		if (v[i] < v[i + 1])
		{
			dp1[i] = 1 + dp1[i + 1];
		} else dp1[i] = 1;
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	cout << dp[i] << " " << dp1[i] << endl;
	// }
	int maxans = 0;
	for (int i = 0; i < n; i++)
	{
		int x = (i - 1 >= 0) ? v[i - 1] : INT_MIN;
		int y = (i + 1 < n) ? v[i + 1] : INT_MAX;
		maxans = max({maxans, dp1[i], dp[i]});
		int lp = (i - 1 >= 0) ? dp[i - 1] : 0;
		int rp = (i + 1 < n) ? dp1[i + 1] : 0;
		if (y > x + 1)
		{
			maxans = max(maxans, lp + rp + 1);
		}
		maxans = max(maxans, 1 + rp);
		maxans = max(maxans, 1 + lp);

	}
	cout << maxans << endl;


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
