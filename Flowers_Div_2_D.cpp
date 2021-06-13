// In this question we are trying to eat flowers
//
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
const int maxn = 1e5 + 10;
void runcases(int T)
{

	int t, k;
	cin >> t >> k;
	int dp[maxn];
	dp[0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		dp[i] = dp[i - 1];
		int l = ((i - k) >= 0) ? dp[i - k] : 0;
		dp[i] += l;
	}
	for (int i = 1; i < maxn; i++)
	{
		dp[i] += dp[i - 1];
	}

	for (int i = 0; i < t; i++)
	{
		int x, y;
		cin >> x >> y;
		int ans = (dp[y] - dp[x - 1]);
		cout << ans << endl;

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
