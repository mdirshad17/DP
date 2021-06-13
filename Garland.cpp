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
string f = "RGB";
void runcases(int T)
{

	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		if (s[i] == s[i - 1])
		{
			ans++;
			if (i + 1 < n)
			{

				for (char c : f)
				{
					if (c != s[i + 1] && c != s[i - 1])
					{
						s[i] = c;
						break;
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
	}
	cout << ans << endl;
	cout << s << endl;



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
