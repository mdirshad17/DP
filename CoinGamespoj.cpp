// ctrl+alt+m

//*!Player Can take either 1,k,l coins
// *?Search CoinGame
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
const int maxn = 1e6 + 2;
//*! look for binary search see if dp can fit or dp with bs
//*? Set or Priority_queue
//*! Number is upto 10^5 check if a[maxn] gives something
//*? Graph Question depedencies Topo sort
int dp[maxn];
void runcases(int T)
{

    int k, l, n;
    cin >> k >> l >> n;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    dp[l] = 1;
    dp[k] = 1;
    vi c;
    c.pb(1);
    c.pb(l);
    c.pb(k);
    for (int i = 1; i < maxn; i++)
    {
        if (dp[i] == -1)
        {
            int ans = 0;
            for (int x : c)
            {
                if (i >= x)
                {
                    ans = ans | (!dp[i - x]);
                }
            }
            dp[i] = ans;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[v[i]])
        {
            cout << "A";
        }
        else
            cout << "B";
    }

    // dp[1]

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
