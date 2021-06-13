// ctrl+alt+m

/* 
Firstly we have to note, that second soldier should choose only prime numbers. If he choose a composite number x that is equal to p * q, he can choose first p, then q and get better score. So our task is to find a number of prime factors in factorization of n.

Now we have to note that factorization of number a! / b! is this same as factorization of numbers (b + 1)*(b + 2)*...*(a - 1)*a.

Let's count number of prime factor in factorization of every number from 2 to 5000000.

First, we use Sieve of Eratosthenes to find a prime diviser of each of these numbers. Then we can calculate a number of prime factors in factorization of a using the formula:

primefactors[a] = primefactors[a / primediviser[a]] + 1

When we know all these numbers, we can use a prefix sums, and then answer for sum on interval.
*/
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
const int maxn = 5e6;
//*! look for binary search see if dp can fit or dp with bs
//*? Set or Priority_queue
//*! Number is upto 10^5 check if a[maxn] gives something
//*? Graph Question depedencies Topo sort
vector<int> sieve()
{
    vector<int> v(maxn + 2, 0);
    //   n++;
    v[0] = 0;
    for (int i = 2; i <= maxn; i++)
    {
        if (!v[i])
            for (int j = i; j <= maxn; j += i)
                v[j] = i;
    }
    vi vx(maxn + 1, 0);
    for (int i = 2; i <= maxn; i++)
    {
        map<int, int> mp;
        int d = i;
        int cnt = 0;
        while (d != 1)
        {
            //   mp[v[d]]++;
            cnt++;
            d = d / v[d];
        }
        vx[i] = cnt;
    }
    for (int i = 1; i <= maxn; i++)
    {
        vx[i] += vx[i - 1];
    }

    return vx;
}
vector<int> facts;
void runcases(int T)
{

    int a, b;
    cin >> a >> b;
    int ans = facts[a] - facts[b];
    cout << ans << endl;

    //cout<<"Case #"<<T<<": ";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    facts = sieve();
    for (int t = 1; t <= T; t++)
    {
        runcases(t);
    }

    return 0;
}
