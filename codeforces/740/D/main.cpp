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

const int MAX = 5e5 + 1e2;
vp G[MAX];
int n,X[MAX],ans[MAX];
int BIT[MAX];
ll dist[MAX];
vi ST;

void update(int p,int v){
	for(++p;p <= n;p += LSOne(p))
		BIT[p] += v;
}

int get(int p){
	int ret = 0;
	for(++p;p;p ^= LSOne(p))
		ret += BIT[p];
	return ret;
}

void DO(int u,int h){
	if(!h) return;
	int s = 0,e = h-1;
	while(s < e){
		int m = (s + e) >> 1;
		if(dist[u] - dist[ST[m]] <= X[u]) e = m;
		else s = m + 1;
	}
	if(dist[u] - dist[ST[s]] > X[u]) return;
	update(s,1);
	update(h,-1);
}

void unDo(int u,int h){
	ans[u] = get(h);
	update(h,-ans[u]);
	update(h+1,ans[u]);
}

void dfs(int u,int p,int h,ll d){
	dist[u] = d;
	DO(u,h);
	ST.pb(u);
	for(auto e : G[u]) if(e.xx != p) {
		dfs(e.xx,u,h+1,d+e.yy);
	}
	ST.pop_back();	
	unDo(u,h);
}

int main(){
	scanf("%d",&n);
	loop(i,n) scanf("%d",X + i);
	loop(i,n-1){
		int a,b,c; scanf("%d %d",&a,&c);
		b = i+1; --a;
		G[a].pb(mp(b,c));
	}
	dfs(0,-1,0,0);
	loop(i,n) printf("%d%c",ans[i]," \n"[i==n-1]);
	return 0;
}

