// CTRL+ALT+M
#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define int long long int
#define vi vector<int>
#define vb vector<bool>
#define vc vector<char>
#define vpi vector<pair<int, int>>
#define pii pair<int, int>
#define pb push_back
#define inf 1e18
#define ff first
#define ss second
#define deb(x) cout << #x << " " << x << endl;
#define all(x) x.begin(), x.end()
#define endl "\n"
const int maxn = 1e5;
//*! look for binary search see if dp can fit or dp with bs
//*? Set or Priority_queue
//*! Number is upto 10^5 check if a[maxn] gives something
//*? Graph Question depedencies Topo sort
//todo For a Tree its shortest Path in  dfs is same as in bfs if it is acyclic
// *! Bridge Detection:: From Backedge we take low[u]=min(low[u],tin[x])
// *! Bridge Detection:: From Child we take low[u]=min(low[u],low[x])
// *! Bridge Detection:: this is a bridge if(low[x]>tin[u])
// vi adj[maxn];
// int visited[maxn];
void runcases(int T)
{
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int dp[n][m];
    memset(dp, 0, sizeof(dp));
    if (a[n - 1][m - 1] < 0)
    {
        dp[n - 1][m - 1] = abs(a[n - 1][m - 1]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        int rq = dp[i + 1][m - 1];
        int hv = a[i][m - 1];
        int nd = rq - hv;
        if (nd > 0)
        {
            dp[i][m - 1] = nd;
        }
    }
    for (int j = m - 2; j >= 0; j--)
    {
        int rq = dp[n - 1][j + 1];
        int hv = a[n - 1][j];
        int nd = rq - hv;
        if (nd > 0)
        {
            dp[n - 1][j] = nd;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            int rq1 = dp[i + 1][j];
            int rq2 = dp[i][j + 1];
            rq1 = min(rq1, rq2);
            int nd = rq1 - a[i][j];
            if (nd > 0)
            {
                dp[i][j] = nd;
            }
        }
    }

    //  for(int i=0;i<n;i++)
    //  {
    //    for(int j=0;j<m;j++)
    //    {
    //      cout<<dp[i][j]<<" ";
    //    }cout<<endl;
    //  }

    // cout<<"Case #"<<T<<": ";
    cout << (dp[0][0] + 1) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        runcases(t);
    }

    return 0;
}
