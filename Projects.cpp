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
const int maxn = 2e5 + 2;
int dp[maxn];
int solve(vector<tuple<int, int , int>> & v, int s, int n)
{
	if (s >= n)
	{
		return 0;
	}
	if (dp[s] != -1)
	{
		return dp[s];
	}
	int ans = 0;
	int f = get<1>(v[s]);
	tuple<int, int , int> obj = {f + 1, 0, 0};
	int idx = lower_bound(all(v), obj) - v.begin();
	// cout << s << " " << idx << endl;
	ans = get<2>(v[s]) + solve(v, idx, n);
	ans = max(ans, solve(v, s + 1, n));
	return dp[s] = ans;
}
bool cmp(tuple<int, int , int > a, tuple<int, int , int > b)
{
	if (get<0>(a) == get<0>(b))
	{
		return get<1>(a) < get<1>(b);
	}
	return (get<0>(a) < get<0>(b));
}
void runcases(int T)
{

	int n;
	cin >> n;
	vector<tuple<int, int, int>> v(n);
	// vi p(n);
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v[i] = {x, y, z};
	}
	// cout << endl;
	memset(dp, -1, sizeof(dp));
	sort(all(v), cmp);
	// for (int i = 0; i < n; i++)
	// {
	// 	cout << get<0>(v[i]) << " " << get<1>(v[i]) << endl;
	// } cout << endl;
	int f = solve(v, 0, n);
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
