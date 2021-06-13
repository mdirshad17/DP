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
int getPerimeter(vi & v)
{
	int maxans = 0;
	sort(all(v));
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		int w = (n - i);
		int area = w * v[i];
		maxans = max(maxans, area);
	}
	return maxans;
}
void runcases(int T)
{

	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}
	vector<vi> v;
	vi p;
	for (int i = 0; i < m; i++)
	{
		p.clear();
		for (int j = 0; j < n; j++)
		{
			int c = (grid[j][i] == '1');
			p.push_back(c);
		}
		v.pb(p);
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][j])
			{
				v[i][j] += v[i - 1][j];
			}
		}
	}
	for (auto x : v)
	{
		for (auto y : x)
		{
			cout << y << " ";
		} cout << endl;
	}
	int maxans = 0;
	for (int i = 0; i < n; i++)
	{
		int f = getPerimeter(v[i]);
		maxans = max(maxans, f);
	}
	// cout << maxans << endl;



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
