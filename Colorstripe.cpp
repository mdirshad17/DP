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
const int maxn = 5e5 + 10;
int solve(string & s, string f)
{

	string m, p;
	int n = s.size();

	for (int i = 0; i < n; i++)
	{
		if (i & 1)
		{
			m.pb('A');
			p.pb('B');
		} else
		{
			p.pb('A');
			m.pb('B');
		}
	}
	int c1 = 0, c2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != m[i])
		{
			c1++;
		}
		if (s[i] != p[i])
		{
			c2++;
		}
	}
	if (c1 <= c2)
	{
		s = m;
	} else
	{
		s = p;
	}
	return min(c1, c2);


}
void runcases(int T)
{

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string f;
	for (int i = 0; i < k; i++)
	{
		f.pb('A' + i);
	}
	if (k == 2)
	{

		int r = solve(s, f);
		cout << r << endl;
		cout << s << endl;
		return;
	}
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (s[i] == s[i - 1])
		{
			ans++;

			if (i + 1 < n)
			{
				bool fx = false;
				for (char c : f)
				{
					if (c != s[i + 1] && c != s[i - 1])
					{
						s[i] = c;
						fx = true;
						break;
					}
				}
				if (!fx)
				{
					for (char c : f)
					{
						if (c != s[i - 1])
						{
							s[i - 1] = c;
							// fx=true;
							break;
						}
					}
				}
			} else
			{
				for (char c : f)
				{
					if ( c != s[i - 1])
					{
						s[i] = c;
						break;
					}
				}
			}
		}

	} cout << ans << endl;
	cout << s << endl;
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
