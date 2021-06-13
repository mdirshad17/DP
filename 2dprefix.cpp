
// ctrl+alt+m
// TODO 2D PrefixSum
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
    //**2d Processing starts here
    // ** Travelling Cols
    for (int i = 1; i < m; i++)
    {
        a[0][i] += a[0][i - 1];
    }
    //**    Travelling Row
    for (int i = 1; i < n; i++)
    {
        a[i][0] += a[i - 1][0];
    }
    // *! Processing the Whole Matrix
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            // **Sum from left and Upper Part
            a[i][j] = a[i - 1][j] + a[i][j - 1] + a[i][j] - a[i - 1][j - 1];
        }
    }
    cout << "2D Prefix Matrix:::::\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Querries :::::\n";
    int q;
    cin >> q;
    while (q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = a[x2][y2];
        int usum = (x1 - 1 >= 0) ? a[x1 - 1][y2] : 0;
        int rsum = (y1 - 1 >= 0) ? a[x2][y1 - 1] : 0;
        int diag = (x1 - 1 >= 0 && y1 - 1 >= 0) ? a[x1 - 1][y1 - 1] : 0;
        int tsum = sum - usum - rsum + diag;
        cout << tsum << endl;
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
