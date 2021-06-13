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

map<int,int> mp;
int dp[2010][2010];
int solve(int s,int e,vi & v)
{
    if(s>=e)
    {
        return 0;
    }
    if(dp[s][e]!=-1)
    {
        return dp[s][e];
    }
    int op1=abs(v[s]-v[e])*mp[v[e]]+solve(s,e-1,v);
    int op2=abs(v[s]-v[e])*mp[v[s]]+solve(s+1,e,v);
    return dp[s][e]=min(op1,op2);
}
void runcases(int T)
{
memset(dp,-1,sizeof(dp));
  int n;
  cin>> n;
  vi v(n);
  set<int> st;
  for(int i=0;i<n;i++){
    cin>>v[i];
    mp[v[i]]++;
    // set<int> st;
    st.insert(v[i]);
  }
  vector<int> c(all(st));
  int m=c.size();
  int f=solve(0,m-1,c);
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
