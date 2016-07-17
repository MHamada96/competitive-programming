#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0,_ = (n);i < _;i++)
#define range(i,a,b) for(int i = (a),_ = (b);i <= _;i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b),_ = (a);i >= _;i--)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define vi vector<int>
#define vl vector<long>
#define vd vector<double>
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

vector<pi> G[1 << 20];
ll D[1 << 20],Q[1 << 20];
int n;
ll mn = LLONG_MAX;

ll solve(int u,int p,int l = 0){
	ll ret = 0;
	for(auto e : G[u]) {
		if(e.xx == p) continue;
		ll tmp = solve(e.xx,u,l + e.yy) + 2LL*e.yy;
		ret += tmp;	
	}
	mn = min(mn,-l + 0LL + Q[u]);
	return ret;
}

int main(){
	scanf("%d",&n);
	loop(i,n + 1) scanf("%I64d",Q + i);
	loop(i,n){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		G[a].pb(mp(b,c));
		G[b].pb(mp(a,c));
	}
	ll ans = solve(0,-1);
	printf("%I64d\n",ans + mn);
	//cerr << ans + mn << endl;
	return 0;
}
