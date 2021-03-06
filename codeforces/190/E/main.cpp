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

const int MAX = 1e5 + 1e2;
vi G[MAX],nG[MAX];
int n,a,b;
char rnk[MAX];
int mrk[MAX];
int deg[MAX],V[MAX],depth ;


int dfs(int u,int p,vi & subtree){
	int ret = 0;	
	subtree.pb(u);
	for(int v : G[u]) 
		if(v != p && !mrk[v]) {
			int tmp =	dfs(v,u,subtree);
			if(mrk[tmp] > mrk[ret]) ret = tmp;
		}
		else if(mrk[v] > mrk[ret]) ret = v;
	return ret;
}

int get_center(vi & subtree){
	if(sz(subtree) == 1) return subtree.back();
	//for(int u : subtree) fprintf(stderr,"(%d,%d)",u,deg[u]);
	//cerr << endl;
	queue<int> q;
	for(int u : subtree) if(deg[u] == 1) q.push(u),V[u] = 1;
	while(sz(q) > 1){
		int u = q.front(); q.pop();
		for(int v : G[u]) if(!mrk[v] && !V[v]) {
			q.push(v);
			V[v] = 1;
		}
	}
	return q.front();
}

int tot = 0;
void build(){
	if(tot == n) return;
	depth++;
	fill(V,V + n + 1,0);
	vi subtree;
	range(u,1,n) if(!mrk[u] && !V[u]){
		subtree.clear();
		int r = dfs(u,0,subtree);
		int c = get_center(subtree);
		mrk[c] = depth; nG[r].pb(c); tot++;
		for(int v : G[c]) deg[v]--;
	}
	//range(u,0,n) {cerr << u << " "; print(nG[u],int); }
	build();
}

void color(int u,char c){
	rnk[u] = c;
	for(int v : nG[u]) color(v,c + 1);
}

int main(){
	scanf("%d",&n);
	loop(i,n - 1){
		scanf("%d %d",&a,&b);
		G[a].pb(b);
		G[b].pb(a);
		deg[a]++;
		deg[b]++;
	}
	build();
	//range(u,1,n) for(int v : nG[u]) cerr << u << " " << v << endl;
	color(nG[0][0],'A');
	range(u,1,n) printf("%c%c",rnk[u]," \n"[u == n]);		
	return 0;
}
