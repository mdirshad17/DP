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
	// set<pii> st;
	map<int, pii> mp;
	vpi vp;
	int maxans = 0;
	map<int, int> par;
	int idx;
	for (int i = 0; i < n; i++)
	{

		int l = v[i] - 1;
		pii p;

		if (mp.count(l))
		{
			p = mp[l];
			mp[v[i]] = {i, p.second + 1};
			// vp.pb({p.first, p.second + 1});
			par[i] = p.first;

		} else
		{
			mp[v[i]] = {i, 1};
			par[i] = i;
		}
		if (maxans < mp[v[i]].ss)
		{
			maxans = mp[v[i]].ss;
			idx = i;
		}

	}
	cout << maxans << endl;
	int p = par[idx];
	vi res;
	while (1)
	{
		res.pb(idx);
		if (p == idx)
		{
			break;
		}
		idx = p;
		p = par[p];
	}
	reverse(all(res));
	int d = res.size();
	assert(d == maxans);
	for (int c : res)
	{
		cout << c + 1 << " ";
	} cout << endl;
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
