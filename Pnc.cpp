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


	string s;
	cin >> s;
	int n = s.size();

	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % M;
	}

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'n')
		{
			s[i] = '1';
		} else if (s[i] == 'u')
		{
			s[i] = '0';
		}
		else if (s[i] == 'w' || s[i] == 'm')
		{
			cout << 0 << endl;
			// cout << "Hello\n";
			return;
		}
	}

	int cur = 0;
	int ans = 1;
	// cout << s << " \n";
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '1')
		{
			cur++;
		} else
		{

			ans = (ans * dp[cur]) % M;
			cur = 0;
		}
	}
	ans = (ans * dp[cur]) % M;
	cur = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0')
		{
			cur++;
		} else
		{

			ans = (ans * dp[cur]) % M;
			cur = 0;
		}
	}
	ans = (ans * dp[cur]) % M;

	cout << ans << endl;





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
