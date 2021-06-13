#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define hM 9999999900000001
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
int dp[12];
int cd(int n)
{
    if (n == 0)
        return 0;

    return 1 + cd(n / 10);
}
int pw[12];
int psum[12];
void nums()
{
    dp[0] = 0;
    dp[1] = 45;
    dp[2] = 855;
    for (int i = 3; i < 12; i++)
    {
        int sum = 0;
        int p = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            sum += dp[j];
            p = p * 10;
        }
        p = p / 10;
        dp[i] = sum * 9 + 45 * p;
    }
    pw[0] = 1;
    for (int i = 1; i < 12; i++)
    {
        pw[i] = pw[i - 1] * 10;
    }
    psum[0] = 0;
    for (int i = 1; i < 12; i++)
    {
        psum[i] += psum[i - 1] + dp[i];
    }
}
int solve(int n)
{

    int sum = 0;
    int i = 0;
    int ps = 0;
    int b = 1;

    while (n)
    {
        int v = (n % 10);
        // deb(v);
        n = n / 10;
        int add = 0;
        if ((v - 1) >= 0)
        {
            int l = (v - 1) * (v) / 2;
            add = l * pw[i] + (v * psum[i]);
            add += (v * (ps + 1));
        }
        sum += add;
        // deb(sum);
        if (n == 0)
        {
            sum -= psum[i];
        }
        i++;
        ps = ps + v * b;
        b = b * 10;
    }
    return sum;
}
void runcases(int T)
{
    while (1)
    {

        int a, b;
        cin >> a >> b;
        if (b == -1)
        {
            return;
        }
        a = a - 1;
        int d1 = cd(b);
        int d2 = cd(a);
        int lx = max(0LL, d2 - 1);
        int rx = max(0LL, d1 - 1);
        // deb(lx);
        // deb(rx);
        int l1 = solve(b);
        // cout << ":::::::::::::::\n";
        int l2 = solve(a);
        // cout << ":::::::::::::::::::\n";
        // cout << l1 << " " << l2 << endl;
        // cout << psum[2];
        l1 += psum[rx];
        l2 += psum[lx];

        // cout << l1 << " " << l2 << endl;
        l1 -= l2;
        cout << l1 << endl;
        // deb()
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
#endif
    int T = 1;
    //cin >> T;
    nums();
    for (int t = 1; t <= T; t++)
    {
        runcases(t);
    }

    return 0;
}
