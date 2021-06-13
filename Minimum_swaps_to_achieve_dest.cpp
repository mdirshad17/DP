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
map<string, vector<string> > adj;
set<string> st;
void addEdge(string s)
{
	if (st.count(s))
	{
		return;
	}
	st.insert(s);
	string p = s;
	// cout << s << " ";
	for (int i = 0; i < s.size() - 1; i++)
	{

		swap(p[i], p[i + 1]);
		// if(st.count(p))
		adj[s].pb(p);
		// adj[p].pb(s)
		addEdge(p);

		swap(p[i], p[i + 1]);

	}
}
int solve(string s, string p)
{
	queue<string> q;
	q.push(s);
	st.insert(s);
	int l = 0;
	while (!q.empty())
	{
		int n = q.size();
		while (n--)
		{
			string d = q.front(); q.pop();
			if (d == p)
			{
				return l;
			}
			for (auto x : adj[d])
			{
				if (st.count(x) == 0)
				{
					st.insert(x);
					q.push(x);
				}
			}
		} l++;
	}
	return l;
}
void runcases(int T)
{

	string s, p;
	cin >> s >> p;
	addEdge(s);
	// for (auto x : adj)
	// {
	// 	cout << x.first << " ";
	// 	for (auto y : x.second)
	// 	{
	// 		cout << y << " ";
	// 	} cout << endl;
	// }
	st.clear();
	int ans = solve(s, p);
	cout << ans << endl;





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
