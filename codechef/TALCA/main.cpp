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
const int MAXLG = 20;

vi G[MAX];
int n,siz[MAX],depth[MAX],cmp_id[MAX],pref_child[MAX];
int head[MAX],cmp_siz[MAX],cmp_cnt,hld_time[MAX],dfs_time;
int dfs_in[MAX],dfs_out[MAX],par[MAX];

int dfs(int u,int p,int d){
	siz[u] = 1;
	depth[u] = d;
	par[u] = p;
	dfs_in[u] = dfs_time++;
	for(int v : G[u]) if(v != p){
		siz[v] += dfs(v,u,d + 1);
		if(!pref_child[u] || siz[v] > siz[pref_child[u]]) pref_child[u] = v;
	}
	dfs_out[u] = dfs_time - 1;
	return siz[u];
}

void hld(int u,int p){
	hld_time[u] = dfs_time++;
	cmp_id[u] = cmp_cnt;
	if(!cmp_siz[cmp_cnt]) head[cmp_cnt] = u;
	cmp_siz[cmp_cnt]++;
	if(pref_child[u]) hld(pref_child[u],u);
	for(int v : G[u]) if(v != p && v != pref_child[u]){
		if(cmp_siz[cmp_cnt]) cmp_cnt++;
		hld(v,u);
	}
}

bool inSubTree(int a,int b){
	return dfs_in[b] <= dfs_in[a] && dfs_in[a] <= dfs_out[b];
}

int lca(int a,int b){
	int cnt = 0;
	while(cmp_id[a] != cmp_id[b]){
		if(depth[head[cmp_id[a]]] > depth[head[cmp_id[b]]]) swap(a,b);
	//	if(cmp_id[a] > cmp_id[b]) swap(a,b);	
		b = par[head[cmp_id[b]]]; 
		assert(a && b);
		cnt++;
	}
	return (depth[a] < depth[b]) ? a : b;
}

int dist(int a,int b){
	return depth[a] + depth[b] - 2*depth[lca(a,b)];
}

int main(){
	scanf("%d",&n);
	loop(i,n-1){
		int a,b; scanf("%d %d",&a,&b);
		G[a].pb(b);
		G[b].pb(a);
	}		
	dfs(1,0,0);
	dfs_time = 0;
	hld(1,0);
	assert(dfs_time == n);
	assert(cmp_cnt <= n);
	int m; scanf("%d",&m);
	while(m--){
		int t,a,b,ans; scanf("%d %d %d",&t,&a,&b);
		if(depth[a] > depth[b]) swap(a,b);
		if(inSubTree(b,t) && inSubTree(a,t)) {
			ans = lca(a,b);
		}
		else if(inSubTree(b,t) || inSubTree(a,t)) {
			ans = t;
		}
		else if(inSubTree(t,b)) {
			if(inSubTree(a,b)) ans = lca(a,t);
			else ans = b;
		}
		else if(inSubTree(t,a)) {
			if(inSubTree(b,a)) ans = lca(b,t);
			else ans = a;
		}
		else if(inSubTree(b,a)) ans = a;
		else {
//			cerr << "here" << endl;
			ans = lca(a,t);
			if(dist(ans,t) > dist(t,lca(b,t))) ans = lca(b,t);
			if(inSubTree(a,ans) && inSubTree(b,ans)) ans = lca(a,b);
		}
		printf("%d\n",ans);
	}
		
	
	return 0;
}
