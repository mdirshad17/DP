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
const int maxn = 1e5;
//*! look for binary search see if dp can fit or dp with bs
//*? Set or Priority_queue
//*! Number is upto 10^5 check if a[maxn] gives something
//*? Graph Question depedencies Topo sort
void runcases(int T)
{

    //   cout<<"HELLO WORLd\n";
    int n, w, h;
    cin >> n >> w >> h;
    vector<vector<int>> v;
    v.pb({w, h, 0});
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.pb({x, y, i + 1});
    }
    sort(all(v));
    // cout<<"HELLO WORLD\n";
    int s = -1;
    for (int i = 0; i <= n; i++)
    {
        if (v[i][0] == w && v[i][1] == h)
        {
            s = i;
            break;
        }
    }
    if (s == n)
    {
        cout << 0 << endl;
        return;
    }
    int par[n + 2];
    int dp[n + 2];
    int f[n + 1];
    memset(par, 0, sizeof(par));
    memset(dp, 0, sizeof(dp));
    memset(f, 0, sizeof(f));
    f[s] = 1;
    for (int i = s + 1; i <= n; i++)
    {
        int p = -1, maxd = 0;
        for (int j = i - 1; j >= s; j--)
        {
            if (f[j])
            {
                if (v[i][1] > v[j][1] && v[i][0] > v[j][0])
                {
                    int l = 1 + dp[j];
                    if (l > maxd)
                    {
                        maxd = l;
                        p = j;
                    }
                }
            }
        }
        if (maxd)
        {
            f[i] = 1;
            dp[i] = maxd;
            par[i] = p;
        }
    }
    int maxans = 0;
    int maxidx = -1;
    for (int i = 0; i <= n; i++)
    {
        if (dp[i] > maxans)
        {
            maxans = dp[i];
            maxidx = i;
        }
    }
    if (maxans == 0)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        cout << maxans << endl;
        vi res;
        int l = maxidx;
        while (l != s)
        {
            res.pb(l);
            l = par[l];
        }
        reverse(all(res));
        for (int x : res)
        {
            cout << v[x][2] << " ";
        }
        cout << endl;
        return;
    }

    //cout<<"Case #"<<T<<": ";
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
