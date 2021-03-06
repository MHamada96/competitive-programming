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

const int MAX = 2e5 + 3;
ll f[MAX];
int g[MAX];
int A[MAX],n;
int nxt[MAX];
int degree[MAX];
int ST[MAX],V[MAX];

void dfs(){
	int size = 0;
	range(i,2,n) if(degree[i] == 0) ST[size++] = i;
	while(size){	
		int u = ST[--size];
		if(V[u]) continue;
		V[u] = 1; f[u] = -1;
		if(nxt[u] == -1) {
			f[u] = g[u];
			continue;
		}
		int v = nxt[u];
		if(V[v]) {
			if(f[v] == -1) f[u] = -1;
			else f[u] = g[u] + f[v];
			continue;
		}
		ST[size++] = v;
	}
}

int get_nxt(int p){
	int x = p,y = 0;
	y += A[x];
	x += A[x];
	g[p] = y;
	if(x > n) return -1;
	y += A[x];
	x -= A[x];
	g[p] = y;
	if(x <= 0) return -1;
	return x;
}

int main(){
	scanf("%d",&n);
	loop(i,n - 1) scanf("%d",A + i + 2);
	range(i,2,n) {
		nxt[i] = get_nxt(i);
		if(nxt[i] != -1) degree[nxt[i]]++;
	}
	f[1] = -1;
	dfs();	
	range(i,1,n - 1){
		A[1] = i;
		int t = get_nxt(1);
		ll ans = (t == -1) ? g[1] : ((f[t] == -1) ? -1 : (f[t] + g[1])); 
		printf("%I64d\n",ans);
	}
	return 0;
}
