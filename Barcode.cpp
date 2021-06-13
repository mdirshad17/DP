// ctrl+alt+m
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
const int maxn = 1e3 + 6;
//*! look for binary search see if dp can fit or dp with bs
//*? Set or Priority_queue
//*! Number is upto 10^5 check if a[maxn] gives something
//*? Graph Question depedencies Topo sort

vi v;
int dp[maxn][maxn][3];
int solve(int s, int n, int cnt, int l, int r, int w, int p)
{
    if (s >= n)
    {
        if (w >= l && w <= r)
        {
            return 0;
        }
        return INT_MAX;
    }
    if (dp[s][w][p] != -1)
    {
        return dp[s][w][p];
    }
    int ans = INT_MAX;
    if (w < l)
    {
        if (p == 0)
        {
            int op1 = v[s] + solve(s + 1, n, cnt, l, r, w + 1, 1);
            int op2 = cnt - v[s] + solve(s + 1, n, cnt, l, r, w + 1, 2);
            ans = min(op1, op2);
        }
        else
        {
            if (p == 1)
            {
                ans = v[s] + solve(s + 1, n, cnt, l, r, w + 1, 1);
            }
            else if (p == 2)
            {
                ans = cnt - v[s] + solve(s + 1, n, cnt, l, r, w + 1, 2);
            }
        }
    }
    else if (w >= l && w < r)
    {
        if (p == 1)
        {
            int op1 = v[s] + solve(s + 1, n, cnt, l, r, w + 1, 1);
            int op2 = cnt - v[s] + solve(s + 1, n, cnt, l, r, 1, 2);
            ans = min(op1, op2);
        }
        else if (p == 2)
        {
            int op1 = cnt - v[s] + solve(s + 1, n, cnt, l, r, w + 1, 2);
            int op2 = v[s] + solve(s + 1, n, cnt, l, r, 1, 1);
            ans = min(op1, op2);
        }
    }
    else if (w == r)
    {
        if (p == 1)
        {
            ans = cnt - v[s] + solve(s + 1, n, cnt, l, r, 1, 2);
        }
        else if (p == 2)
        {
            ans = v[s] + solve(s + 1, n, cnt, l, r, 1, 1);
        }
    }
    return dp[s][w][p] = ans;
}
void set_memory(int n)
{
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            for (int k = 0; k <= 2; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }
}
void runcases(int T)
{

    int n, m, l, r;
    cin >> n >> m >> l >> r;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        char c;
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            if (c == '#')
                mp[j]++;
        }
    }
    // vi v;
    for (int i = 0; i < m; i++)
    {
        v.pb(mp[i]);
    }
    set_memory(m);
    int f = solve(0, m, n, l, r, 0, 0);
    cout << f << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int t = 1; t <= T; t++)
    {
        runcases(t);
    }

    return 0;
}
