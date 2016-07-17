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
#define LSOne(x) ((x) & (-(x)))
#define xx first
#define yy second
#define prp(p) cout << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cout << #A << ": "; copy(A,A + n,ostream_iterator<t>(cout," " )); cout << endl
using namespace std;

int ans , s;
vi G[11000];

int dfs(int u,int p,int d){
	if(d > ans) {
		s = u;
		ans = d;
	}
	for(int v : G[u])
		if(p != v)
			dfs(v,u,d + 1);
}

int main(){
  	int T,N;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		loop(i,N + 1) G[i].clear();
		loop(i,N - 1){
			int a,b;
			scanf("%d %d",&a,&b);
			G[a].pb(b);
			G[b].pb(a);
		}
		ans = 0,s = 1;
		dfs(1,0,0);
		ans = 0;
		dfs(s,0,0);
		printf("%d\n",N - 1 - ans);
	}
	return 0;
}
