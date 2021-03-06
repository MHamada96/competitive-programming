#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long long>
#define vd vector<double>
#define vp vector<pair<int,int> >
#define ll long long
#define pi pair<int,int>
#define point pair<double,double>
#define pl pair<ll,ll>
#define popcnt(x) __builtin_popcount(x)
#define LSOne(x) ((x) & (-(x)))
#define xx first
#define yy second
#define PQ priority_queue
#define print(A,t) cerr << #A << ": "; copy(all(A),ostream_iterator<t>(cerr," " )); cerr << endl
#define prp(p) cerr << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cerr << #A << ": "; copy(A,A + n,ostream_iterator<t>(cerr," " )); cerr << endl
#define PRESTDIO() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
using namespace std;

const int MAX = 2e5 + 1e2;
vi G[MAX];
int E[MAX],n;
ll dp[MAX][2];

void dfs(int u){	
	if(sz(G[u])%2 == 0){
		dp[u][1] = E[u];
		ll x = 0,y = 0;
		for(int v : G[u]){
			dfs(v);
			dp[u][1] += dp[v][1];
			ll t = max(x + dp[v][0],y + dp[v][1]);
			y = max(y + dp[v][0],x + dp[v][1]);
			x = t;
		}
		dp[u][0] = x;
	}
	else{
		vl even,odd;
		for(int v : G[u]){
			dfs(v);
			dp[u][1] += dp[v][1];
		}
		for(int v : G[u]){
			dp[u][0] = max(dp[u][0],dp[u][1] - dp[v][1] + dp[v][0]);;
		}
		dp[u][1] = max(dp[u][1],dp[u][0] + E[u]);
	}
}

int main(){
	scanf("%d",&n);
	range(i,1,n){
		int p; scanf("%d %d",&p,E + i);
		if(p != -1) G[p].pb(i);
	}
	dfs(1);
	cout << dp[1][1] << endl;
	
	return 0;
}
