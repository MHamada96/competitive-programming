#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long>
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

const int MAX = 100000 + 1e3;
const int oo  = 1 << 28;

vi G[MAX],Q[MAX];
vi L[MAX],R[MAX];
int is_shot[MAX],n,m,a,b,d;
int furthest[MAX],depth[MAX];
int dfs0(int u,int p,int h = 1){
	int ret = u*is_shot[u];
	depth[u] = h;
	for(int v : G[u]) if(v != p) {
		int t = dfs0(v,u,h + 1);
		int tmp = depth[t] - depth[u];
		Q[u].pb((tmp < 0) ? INT_MAX : (d - tmp));
		if(depth[t] > depth[ret]) ret = t;
	}
	else Q[u].pb(oo);
	return ret;
}

int ans = 0;
void dfs1(int u,int p,int par = oo){
	int mn = par;	
	loop(i,sz(G[u])) {
		if(G[u][i] == p) Q[u][i] = par;
		L[u].pb(oo);
		R[u].pb(oo);
		mn = min(mn,Q[u][i]);
	}
	if(is_shot[u]) mn = min(mn,d);	
	if(mn >= 0 && mn <= d) ans++;
	loop(i,sz(G[u]) - 1) L[u][i + 1] = min(L[u][i],Q[u][i]);
	for(int i = sz(G[u]) - 1;i;i--) R[u][i - 1] = min(R[u][i],Q[u][i]);
	loop(i,sz(G[u])) if(G[u][i] != p){
		mn = min(L[u][i],R[u][i]);
		if(is_shot[u]) mn = min(mn,d);
		dfs1(G[u][i],u,mn - 1);
	}
}

int main(){
	scanf("%d %d %d",&n,&m,&d);
	loop(i,m){
		scanf("%d",&a);
		is_shot[a] = 1;
	}
	loop(i,n - 1){
		scanf("%d %d",&a,&b);
		G[a].pb(b);
		G[b].pb(a);
	}
	int ctr = 0;
	dfs0(1,0);
	dfs1(1,0);
	cerr << ans << endl;
	cout << ans << endl;
	return 0;
}
