// Practising Iterative Dp;


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

	int n, k;
	cin >> n >> k;
	int dp[k + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		dp[1][i] = 1;
	}


	for (int i = 2; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int ans = 0;
			for (int l = j; l <= n; l += j)
			{
				ans = (ans + dp[i - 1][l]) % M;
			}
			dp[i][j] = (dp[i][j] + ans) % M;
		}

	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = (ans + dp[k][i]) % M;
	}
	cout << ans << endl;


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
