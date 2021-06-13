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
vector<vector<int> >  matrix;
int n, m;
int dp[16][120][1620][2];
int solve(int r, int c, int cnt, int f)
{


	// cout << r << " " << c << " " << endl;
	// cout << r << " " << c << " " << cnt << endl;
	if (cnt == 0)
	{
		return 0;
	}
	if (r < 0 || c < 0 || c >= m)
	{
		return INT_MAX;
	}
	if (dp[r][c][cnt][f] != -1)
	{
		return dp[r][c][cnt][f];
	}
	int ans = inf;
	if (f == 0)
	{
		int d = matrix[r][c];
		int ri =  (m - c) + solve(r - 1, m - 1, cnt - d, 1);
		int l = 1 + (c) + solve(r - 1, 0, cnt - d, 0);
		int one = 1 + solve(r, c + 1, cnt - d, f);
		ans = min({ans, ri, l, one});
	} else if (f == 1)
	{
		int d = matrix[r][c];
		int ri = (m - c) + solve(r - 1, m - 1, cnt - d, 1);
		int l = 1 + (c) + solve(r - 1, 0, cnt - d, 0);
		int one = 1 + solve(r, c - 1, cnt - d, f);
		ans = min({ans, ri, l, one});
	}
	return dp[r][c][cnt][f] = ans;

}
void runcases(int T)
{
	cin >> n >> m;
	m = m + 2;
	matrix.assign(n, vector<int>(m, 0));
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			int d = c - '0';
			matrix[i][j] = d;
			if (matrix[i][j] == 1)
			{
				cnt++;
			}
		}
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			for (int k = 0; k <= cnt + 2; k++)
			{
				for (int l = 0; l <= 2; l++)
				{
					dp[i][j][k][l] = -1;
				}
			}
		}
	}
	memset(dp, -1, sizeof(dp));
	int f = solve(n - 1, 0, cnt, 0);
	f = max(f - 1LL, 0LL);
	// int f1 = solve(0, m - 1, cnt, 1);
	cout << f << endl;

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
