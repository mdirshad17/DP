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
const int maxn = 2e3 + 1;
//*! look for binary search see if dp can fit or dp with bs
//*? Set or Priority_queue
//*! Number is upto 10^5 check if a[maxn] gives something
//*? Graph Question depedencies Topo sort

int dp[maxn][maxn];
int solve(int s, int n, int hrs, int h, int l, int r, vi &v)
{
    if (s >= n)
    {
        return 0;
    }
    if (dp[s][hrs] != -1)
    {
        return dp[s][hrs];
    }
    // cout<<" Hello\n";
    int f1 = ((hrs + v[s] - 1) % h + h) % h;
    int f2 = ((hrs + v[s]) % h + h) % h;
    int add1 = (l <= f1 && f1 <= r) ? 1 : 0;
    int add2 = (l <= f2 && f2 <= r) ? 1 : 0;
    int ans1 = add1 + solve(s + 1, n, f1, h, l, r, v);
    int ans2 = add2 + solve(s + 1, n, f2, h, l, r, v);
    return dp[s][hrs] = max(ans1, ans2);
}
void runcases(int T)
{

    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vi v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    memset(dp, -1, sizeof(dp));
    int f = solve(0, n, 0, h, l, r, v);
    cout << f << endl;

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
