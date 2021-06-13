
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
vi vx, vy;
void solve(vi & v, int n, int sum, vi & f)
{
	if (n == 0)
	{
		f.pb(sum);
		return;
	}
	solve(v, n - 1, sum + v[n - 1], f);
	solve(v, n - 1, sum, f);
}
int bs(vi & v, int val)
{
	int l = 0, r = v.size() - 1;
	int ans = -1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		if (v[m] <= val)
		{
			ans = m;
			l = m + 1;
		} else
		{
			r = m - 1;
		}
	}
	return ans;
}
void runcases(int T)
{

	int n, sum;
	cin >> n >> sum;
	vi v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vi v1, v2;
	for (int i = 0; i < n / 2; i++)
	{
		v1.pb(v[i]);
	}
	for (int i = n / 2; i < n; i++)
	{
		v2.pb(v[i]);
	}
	int l = v1.size();
	int m = v2.size();
	solve(v1, l, 0, vx);
	solve(v2, m, 0, vy);

	sort(all(vx));
	sort(all(vy));
	// for (int x : vx)
	// {
	// 	cout << x << " ";
	// }
	// cout << endl;
	// for (int y : vy)
	// {
	// 	cout << y << " ";
	// } cout << endl;
	int maxans = 0;
	for (int x : vx)
	{
		int rem = (sum - x);
		if (rem >= 0)
		{
			// cout << rem << " ";
			// int idx = lower_bound(all(vy), rem) - vy.begin();
			int idx = bs(vy, rem);
			if (idx == -1)
			{
				continue;
			}
			int val = vy[idx];
			// cout << val << endl;
			int f = val + x;
			if (f <= sum)
			{
				maxans = max(maxans, f);
			}
		}
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
