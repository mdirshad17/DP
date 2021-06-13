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
vi v;
int cnt = 0;
int dp[1001][1001];
int solve(int s, int e)
{
	cnt++;
	if (s >= e)
	{
		return 0;
	}
	if (dp[s][e] != -1)
	{
		return dp[s][e];
	}
	int ans = INT_MAX;
	for (int i = s; i < e; i++)
	{
		int l = solve(s, i) + solve(i + 1, e) + (v[s - 1] * v[i] * v[e]);
		ans = min(ans, l);
	}
	return dp[s][e] = ans;
}

void runcases(int T)
{

	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	memset(dp, -1, sizeof(dp));
	int f = solve(1, n - 1);
	deb(cnt);
	cout << f << endl;



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
