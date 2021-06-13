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
vi adj[maxn + 2];
int visited[maxn + 2];

struct cmp {
	bool operator()(pii & a, pii & b)
	{
		if (a.ff == b.ff)
		{
			return a.ss > b.ss;
		}
		return a.ff < b.ff;
	}
};
int bfs(int s, int k)
{
	int l = 0;
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	priority_queue<pii, vector<pii>, cmp> pq;
	while (!q.empty())
	{
		int n = q.size();
		while (n--)
		{
			int d = q.front();
			q.pop();
			bool ng = false;
			for (int x : adj[d]) {

				if (!visited[x])
				{
					ng = true;
					visited[x] = 1;
					q.push(x);
				}
			}
			if (!ng)
			{
				pq.push({l + 1, 0});
			}
		} l++;
	}
	// cout << endl;
	while (k)
	{
		pii p = pq.top();
		pq.pop();
		p.ss += 1;
		p.ff -= 1;
		pq.push(p);
		k--;
	}
	int ans = 0;
	while (!pq.empty())
	{

		pii p = pq.top();
		// cout << p.ff << " " << p.ss << endl;
		pq.pop();
		ans += (p.ff * p.ss);
	}
	return ans;


}
void runcases(int T)
{

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < (n - 1); i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int f = bfs(1, k);
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
