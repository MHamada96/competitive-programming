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

const int MAX = 1e5 + 1e2,mod = 1e9 + 7;
vi G[MAX];
int A[MAX],n;
int F[MAX],r[MAX];
int siz[MAX];

int mul(int x,int y){
	return (x*1LL*y)%mod;
}

int POW(int x,int p){
	if(!p) return 1;
	int y = 1;
	for(;p > 1;p >>= 1) {
		if(p & 1) y = mul(x,y);
		x = mul(x,x);
	}
	return mul(x,y);
}

int C(int n,int k){
	int ret = F[n];
	ret = mul(ret,r[k]);
	ret = mul(ret,r[n - k]);
	return ret;
}

void init(){
	F[0] = r[0] = 1;
	loop(i,MAX - 1) {
		F[i + 1] = mul(F[i],i + 1);
		r[i + 1] = POW(F[i + 1],mod - 2);
	}
}

int decompose(int x,int r,int p){
	if(x + A[x] > r) return 0;
	G[p].pb(x);
	if(x == r) return 1;
	int ret = 1;
	if(A[x]) ret &= decompose(x + 1,x + A[x],x);
	if(x + A[x] < r) ret &= decompose(x + A[x] + 1,r,p);
	return ret;
}

int dfs(int u){
	siz[u] = 1;
	for(int v : G[u]) siz[u] += dfs(v);
	return siz[u];
}

int solve(int u){
	int ret = 1,cnt = siz[u]; cnt--;
	for(int i = sz(G[u]) - 1;i >= 0;i--){
		int v = G[u][i];
		int tmp = mul(C(cnt-1,siz[v]-1),solve(G[u][i]));
		cnt -= siz[v];
		ret = mul(ret,tmp);
	}
	return ret;
}

int main(){
	init();
	int T; scanf("%d",&T);	
	while(T--){
		scanf("%d",&n);
		range(i,0,n) G[i].clear();
		range(i,1,n) scanf("%d",A + i);
		if(!decompose(1,n,0)) puts("0");
		else {
			dfs(0);
			printf("%d\n",solve(0));
		}
	}
	
	return 0;
}
