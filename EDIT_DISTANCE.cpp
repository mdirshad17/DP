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
// int dp[1005][1005];
void runcases(int T)
{
	string s;
	cin >> s;
	string t;
	cin >> t;
	int n = s.size();
	int m = t.size();
	// memset(dp, -1, sizeof(dp));
	int dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = i;
	}
	for (int i = 0; i <= m; i++)
	{
		dp[0][i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s[i - 1] == t[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			} else
			{
				dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
			}
		}
	}
	cout << dp[n][m] << endl;









	//cout<<"Case #"<<T<<": ";
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