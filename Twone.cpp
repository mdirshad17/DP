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
	string s;
	cin >> s;
	int n = s.size();
	int c = 0;
	for (int i = 0; i + 5 <= n; i++)
	{
		string p = s.substr(i, 5);
		if (p == "twone")
		{
			s[i + 2] = '#';
			c++;
		}
	}
	for (int i = 0; i + 3 <= n; i++)
	{
		string p = s.substr(i, 3);
		if (p == "two" || p == "one")
		{
			s[i + 1] = '#';
			c++;
		}
	}
	cout << c << endl;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '#')
		{
			cout << (i + 1) << " ";
		}
	} cout << endl;
	// cout << s << endl;


}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T = 1;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		runcases(t);
	}

	return 0;
}
