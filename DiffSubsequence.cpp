// CTRL+ALT+M 
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
const int maxn=1e5;
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
vector<vi> dp;
int solve(int n,int m,string & s,string & p)
{
    if(m==0)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    int ans;
    if(s[n-1]!=p[m-1])
    {
        ans=solve(n-1,m,s,p);
    }else
    {
        ans=solve(n-1,m-1,s,p)+solve(n-1,m,s,p);
    }
    return dp[n][m]=ans;
}
void runcases(int T)
{

  string s,p;
  cin>>s>>p;
  int n=s.size();
  int m=p.size();
  dp.assign(n+1,vi(m+1,-1));
  int f=solve(n,m,s,p);
  cout<<f<<endl;

  

  //cout<<"Case #"<<T<<": ";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    //cin >> T;
    for (int t=1;t<=T; t++) {
        runcases(t);
    }

    return 0;
}
