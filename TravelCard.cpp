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
int bs(int val, vi & v)
{
	int ans = -1;
	int l = 0, r = v.size() - 1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (v[m] >= val)
		{
			ans = m;
			r = m - 1;
		} else
		{
			l = m + 1;
		}
	}
	return ans;
}
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
	dp[0] = 20;
	for (int i = 1; i < n; i++)
	{
		int ans1 = dp[i - 1] + 20;
		int val1 = v[i] - 89;
		int val2 = v[i] - 1439;
		int idx1 = bs(val1, v);
		int idx2 = bs(val2, v);
		int ans2 = ((idx1 - 1 >= 0) ? dp[idx1 - 1] : 0) + 50;
		int ans3 = ((idx2 - 1 >= 0) ? dp[idx2 - 1] : 0) + 120;
		ans1 = min({ans1, ans2, ans3});
		dp[i] = ans1;
	}
	int sum = 0;
	cout << dp[0] << " " << endl;
	for (int i = 1; i < n; i++)
	{
		cout << (dp[i] - dp[i - 1]) << " " << endl;
	}



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
