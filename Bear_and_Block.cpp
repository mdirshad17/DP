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
	dp[0] = 0;
	dp[n - 1] = 0;
	int maxans = 0;
	for (int  i = 1; i < n - 1; i++)
	{
		int lh = v[i - 1];
		int rh = v[i + 1];
		int f = min({lh, rh, v[i] - 1});
		int d1 = i;
		int d2 = n - 1 - i;
		f = min({d1, d2, f});
		dp[i] = f;
		maxans = max(maxans, dp[i]);
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	cout << dp[i] << " ";
	// } cout << endl;
	cout << maxans + 1 << endl;



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
