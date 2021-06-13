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
int maxones(vi & v, int m)
{
	int c = 0;
	int maxans = 0;
	for (int i = 0; i < m; i++)
	{
		if (v[i] == 1)
		{
			c++;
			maxans = max(maxans, c);
		} else
		{
			c = 0;
		}
	}
	return maxans;
}
void runcases(int T)
{

	int n, m, q;
	cin >> n >> m >> q;
// int grid[n][m];
	vector<vi> grid(n, vi(m));
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		int c = maxones(grid[i], m);
		v[i] = c;
	}

	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		grid[x][y] = grid[x][y] ^ 1;
		int f = maxones(grid[x], m);
		v[x] = f;
		int maxans = 0;
		for (int i = 0; i < n; i++)
		{
			maxans = max(maxans, v[i]);
		}
		cout << maxans << endl;

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
