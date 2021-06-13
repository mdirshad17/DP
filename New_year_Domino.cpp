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

	int n, m;
	cin >> n >> m;
	vector<vector<int> > v(n, vi(m));
	vector<vector<int> > prefu(n, vi(m, 0));
	vector<vector<int> > prefh(n, vi(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			if (c == '#')
			{
				v[i][j] = -1;
			} else v[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (v[i][j] == -1)
			{
				continue;
			}
			if ((i - 1) >= 0)
			{
				if (v[i - 1][j] != -1)
				{
					prefu[i][j] += 1;
				}
			}
			if ((j - 1) >= 0)
			{
				if (v[i][j - 1] != -1)
				{
					prefh[i][j] += 1;
				}
			}
		}
	}
	vector<vector<int> > prefxu(n, vi(m, 0));
	vector<vector<int> > prefxh(n, vi(m, 0));
	prefxu[0][0] = prefu[0][0];
	prefxh[0][0] = prefh[0][0];
	for (int i = 1; i < m; i++)
	{
		prefxu[0][i] += prefxu[0][i - 1] + prefu[0][i];
		prefxh[0][i] += prefxh[0][i - 1] + prefh[0][i];
	}
	for (int i = 1; i < n; i++)
	{
		prefxu[i][0] += prefxu[i - 1][0] + prefu[i][0];
		prefxh[i][0] += prefxh[i - 1][0] + prefh[i][0];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			prefxu[i][j] += (prefxu[i - 1][j] + prefxu[i][j - 1] - prefxu[i - 1][j - 1] + prefu[i][j]);
			prefxh[i][j] += (prefxh[i - 1][j] + prefxh[i][j - 1] - prefxh[i - 1][j - 1] + prefh[i][j]);
		}
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 	{
	// 		cout << prefx[i][j] << " ";
	// 	} cout << endl;
	// } cout << endl << endl;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--;
		r2--;
		c1--;
		c2--;
		int lsum = 0;
		int rsum = 0;
		int usum = 0;
		int osum = prefxu[r2][c2] + prefxh[r2][c2];
		deb(osum);
		// if (r1 - 1 >= 0)
		// {
		// 	lsum = prefx[r1 - 1][c1];
		// }
		if ((c1 - 1) >= 0)
		{
			lsum += prefxu[r2][c1 - 1];
			lsum += prefxh[r2][c1 - 1];
		}
		if ((r1 - 1) >= 0)
		{
			usum += prefxu[r1 - 1][c2];
			usum += prefxh[r1 - 1][c2];
		}
		if ((r1 - 1) >= 0 && (c1 - 1) >= 0)
		{
			rsum += prefxu[r1 - 1][c1 - 1];
			rsum += prefxh[r1 - 1][c1 - 1];
		}
		int sum = (osum - lsum - usum + rsum);
		deb(lsum);
		deb(rsum);
		deb(usum);
		cout << sum << endl;

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
