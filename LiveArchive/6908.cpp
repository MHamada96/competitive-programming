#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define step(i,a,b,d) for(int i = (a);i <= (b); i += d)
#define all(A) A.begin(),A.end()
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define len(A) A.length()
#define print(A,t) cout << #A << ": "; copy(all(A),ostream_iterator<t>(cout," " )); cout << endl
#define pi pair<int,int>
#define point pi
#define vi vector<int>
#define ll long long
#define pl pair<ll,ll>
#define pre() cin.tie(0),cout.tie(0),ios_base::sync_with_stdio(0)
#define popcnt(x) __builtin_popcount(x)
using namespace std;

const ll INF = 1LL << 60;
int segment[1001],N,K,E;
ll dp[1000 + 1][10 + 1][50 + 1][4];
int help[] = {0,4,8,11};


ll solve(int x,int k,int e,int p){
	if (k < 0 || e < 0) return INF;
	if(x == N) return 0;
	if(dp[x][k][e][p] != INF) return dp[x][k][e][p];
	dp[x][k][e][p] = 1LL << 60;
	loop(i,4)
		dp[x][k][e][p] = min(dp[x][k][e][p],solve(x + 1,k  - (i!=p),e - i,i) + max(segment[x] - help[i],0));
	dp[x][k][e][p] = min(dp[x][k][e][p],solve(x + 1,0,0,0) + segment[x]);
	//cout << x << " " << k << " " << e << " " << p << " " << dp[x][k][e][p] << endl;
	return dp[x][k][e][p];
}

int main(){
	int T;
	scanf("%d",&T);
	loop(t,T){
		scanf("%d %d %d",&N,&K,&E);
		loop(i,N) scanf("%d",segment + i);	
		loop(i,N + 1) loop(j,K + 1) loop(k,E + 1) loop(l,4) dp[i][j][k][l] = INF;
		cout << "Case #" << t + 1 << ": " << solve(0,K,E,0) << endl;
	}
}
