// ctrl+alt+m
// ** 2d Kadane Algo
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

vector<int>  Kadane(int *b, int n)
{
    int msum = b[0];
    int csum = b[0];
    pii s={0,0};
    int p=0;
    for (int i = 1; i < n; i++)
    {
        // csum = max(csum + b[i], b[i]);
        if((csum+b[i])>b[i])
        {
            csum=csum+b[i];
        }else {
            csum=b[i];
            p=i;
        }
        if(msum<csum){
          msum = csum;
        s={p,i};  
        }
    }
    // cout<<msum<<" ";
    return {msum,s.ff,s.ss};
}
void runcases(int T)
{

    // todo >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    // ?? Calculate 2d prefix
    // ?? O(N^4)EASY for i,j find i' and j'
    // ? and keep the track of maxsum so far
    // ! O(N^3) is the algo
    // !We have Done it
    // todo >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
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
    cout << ":::::::::::::\n";
    int maxans = -1*inf;
    pii s={-1,-1};
    pii e={-1,-1};
    for (int i = 0; i < n; i++)
    {
        int b[m];
        memset(b, 0, sizeof(b));
        for (int j = i; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                b[k] += a[j][k];
            }
            
            vector<int> sum = Kadane(b, m);
            if(maxans<sum[0]){
            maxans = max(maxans, sum[0]);
               s={i+1,sum[1]+1}; 
               e={j+1,sum[2]+1}; 
            }
        }
    }
    cout << maxans << endl;
    cout<<s.ff<<" "<<s.ss<<" \n";
    cout<<e.ff<<" "<<e.ss<<" \n";

    //cout<<"Case #"<<T<<": ";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int t = 1; t <= T; t++)
    {
        runcases(t);
    }

    return 0;
}
