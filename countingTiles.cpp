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
int solve(int n, int m)
{
	if (n == 0 && m == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return (m % 2) == 0;
	}
	if (m == 1)
	{
		return (n % 2) == 0;
	}
	if (n < 0 || m < 0)
	{
		return 0;
	}

	return solve(n - 1, m - 2) + solve(n - 2, m - 1);

}
void runcases(int T)
{

	int n, m;
	cin >> n >> m;
	int f = solve(n, m);
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
