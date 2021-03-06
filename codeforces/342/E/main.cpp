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

const int MAX = 1e5 + 1e2,oo = 1e8;

int ST[3][MAX << 4];
int in_time[MAX],out_time[MAX],dfs_time,n;
int siz[MAX],pref_child[MAX],depth[MAX],par[MAX];
int path_siz[MAX],head[MAX],path_id[MAX],idx[MAX],cnt;
vi G[MAX];
bool debug = 0;

int dfs(int u,int p,int d){
	siz[u] = 1;
	depth[u] = d;
	par[u] = p;
	in_time[u] = dfs_time++;
	for(int v : G[u]) if(v != p) {
		siz[u] += dfs(v,u,d + 1);	
		if(!pref_child[u] || siz[v] > siz[pref_child[u]])
			pref_child[u] = v;
	}
	out_time[u] = dfs_time - 1;
	return siz[u];
}

void hld(int u,int p){
	path_id[u] = cnt;
	if(!path_siz[cnt]) head[cnt] = u;
	path_siz[cnt]++;
	idx[u] = dfs_time++;
	if(pref_child[u]) hld(pref_child[u],u); 
	for(int v : G[u]) if(v != p && v != pref_child[u]){
		if(path_siz[cnt]) cnt++;
		hld(v,u);
	}
}

int update(int node,int s,int e,int p,int v,int c){
	if(s == e) return ST[c][node] = v;
	int m = (s + e) >> 1,left = node << 1,right = left | 1;
	if(p <= m) update(left,s,m,p,v,c);
	else update(right,m+1,e,p,v,c);
	return ST[c][node] = min(ST[c][left],ST[c][right]);
}

int query(int node,int s,int e,int l,int r,int c){
	if(l <= s && e <= r) return ST[c][node];
	int m = (s + e) >> 1,left = node << 1,right = left | 1;
	if(r <= m) return query(left,s,m,l,r,c);
	if(m < l) return query(right,m+1,e,l,r,c);
	return min(query(left,s,m,l,m,c),query(right,m+1,e,m+1,r,c)); 
}

void update(int u){
	update(1,0,n-1,in_time[u],depth[u],0);
	int p = u;	
	while(p){
		int h = query(1,0,n-1,in_time[p],out_time[p],0);
		update(1,0,n-1,idx[p],h - 2*depth[p],1);
		update(1,0,n-1,idx[p],h,2);
		p = par[head[path_id[p]]];
	}
	if(debug){
		cerr << "update " << u << endl;
		prArr(ST[0]+1,2*n,int);
		prArr(ST[1]+1,2*n,int);
		prArr(ST[2]+1,2*n,int);
		cerr << endl;
	}
}

int query(int u){
	int ans = query(1,0,n-1,in_time[u],out_time[u],0) - depth[u];
	int p = u;
	while(p){
		if(debug) cerr << "query " << idx[head[path_id[p]]] << " " << idx[p] << endl;
		int h = query(1,0,n-1,idx[head[path_id[p]]],idx[p],1);
		ans = min(ans,h + depth[u]);
		if(debug) cerr << h << endl;
		h = query(1,0,n-1,idx[p],idx[head[path_id[p]]] + path_siz[path_id[p]] - 1,2);
		ans = min(ans,h + depth[u] - 2*depth[p]);
		p = par[head[path_id[p]]];		
	}
	return ans;
}

int main(){
	int m;
	scanf("%d %d",&n,&m);
	loop(i,n-1) {
		int a,b; scanf("%d %d",&a,&b);
		G[a].pb(b);
		G[b].pb(a);
	}	
	dfs(1,0,0);
	assert(dfs_time == n);
	dfs_time = 0;
	hld(1,0);
	assert(dfs_time == n);
	// intialize
	fill(&ST[0][0],&ST[3][0],oo);
	update(1);
	
	while(m--){
		int t,u; scanf("%d %d",&t,&u);
		if(t == 1) update(u);
		else printf("%d\n",query(u));
	}	
	return 0;
}
