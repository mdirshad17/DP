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
	// vi v(n);
	int a[n][m];
	int b[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> b[i][j];
	}
	int s[n + 1][m + 1];
	int ns[n + 1][m + 1];
	memset(s, 0, sizeof(s));
	memset(ns, 0, sizeof(ns));
	s[0][0] = 1;
	ns[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((i == 0 || (s[i - 1][j] && a[i][j] > a[i - 1][j] && b[i][j] > b[i - 1][j]) ||
			        (ns[i - 1][j] && a[i][j] > b[i - 1][j] && b[i][j] > a[i - 1][j]))
			        && (j == 0 || (s[i][j - 1] && a[i][j] > a[i][j - 1] && b[i][j] > b[i][j - 1]) || (ns[i][j - 1] && a[i][j] > b[i][j - 1] && b[i][j] > a[i][j - 1])))
			{
				s[i][j] = 1;
			}
			if ((i == 0 || (s[i - 1][j] && b[i][j] > a[i - 1][j] && a[i][j] > b[i - 1][j]) ||
			        (ns[i - 1][j] && b[i][j] > b[i - 1][j] && a[i][j] > a[i - 1][j]))
			        && (j == 0 || (s[i][j - 1] && b[i][j] > a[i][j - 1] && a[i][j] > b[i][j - 1]) || (ns[i][j - 1] && a[i][j] > a[i][j - 1] && b[i][j] > b[i][j - 1])))
			{
				ns[i][j] = 1;
			}
		}
	}
	bool f = s[n - 1][m - 1] || ns[n - 1][m - 1];
	if (!f)
	{
		cout << "Impossible\n";
	} else cout << "Possible\n";

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
