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

int id[1024],W[1024];
int n;
char line[1024];
int val[1024];
vi G[1024];
int deg[1024];

int get(int x){
	return id[x] = (x == id[x]) ? x : get(id[x]);
}

void join(int a,int b){
	a = get(a),b = get(b);
	if(a == b) return;
	if(W[a] < W[b]) swap(a,b);
	W[a] += W[b];
	id[b] = a;
}

void dfs(int u,int c){
	val[u] = max(val[u],c);
	if(deg[u]) return;
	for(int v : G[u]) {
		deg[v]--;	
		dfs(v,val[u] + 1); 
	}
}

int main(){
	cin >> n >> line;
	loop(i,n) id[i] = i,W[i] = 1;
	loop(i,n-1) {
		if(line[i] == '=') join(i,i+1);
		else if(line[i] == 'R') G[i].push_back(i+1);
		else G[i + 1].pb(i);
	}
	loop(i,n) if(i != get(i)) for(int v : G[i]) G[get(i)].pb(v);
	loop(i,n) if(i == get(i)) {
		for(int & v : G[i]) v = get(v);
		sort(all(G[i]));		
		G[i].resize(unique(all(G[i])) - G[i].begin());	
		for(int v : G[i]) deg[v]++;
	}
	loop(i,n) if(i == get(i) && deg[i] == 0) dfs(i,1);
	loop(i,n) printf("%d%c",val[get(i)]," \n"[i == n-1]);	
		
	
	return 0;
}
