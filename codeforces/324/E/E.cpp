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

vi G[1001];
int C[1001][1001],n,A[1001],B[1001],F[1001],V[1001];
int dfs_time,ord[1001],in[1001];

void dfs(int u){
	if(V[u]) return;
	V[u] = 1;
	for(int v : G[u]) dfs(v);
	ord[dfs_time++] = u;
}

void dfs(int u,int & sum,int & cmax,int & cnt,int r,vector<pi> & T){
	if(V[u]) return;
	V[u] = 1;
	for(int v : G[u]) 
	if(!V[v] || v == r){
		T.pb(mp(u,v));
		sum += C[u][v];
		cmax = max(cmax,C[u][v]);	
		if(v != r){
			dfs(v,sum,cmax,cnt,r,T);
			cnt++;
		}
	}
}

int main(){
  	scanf("%d",&n);
	loop(i,n) scanf("%d",A + i),F[A[i]] = i;
	loop(i,n) scanf("%d",B + i);
	loop(i,n) {
		G[i].pb(F[B[i]]);
		C[i][F[B[i]]] = abs(i - F[B[i]]);
		C[F[B[i]]][i] = C[i][F[B[i]]];	
	}
	loop(i,n) if(!V[i]) dfs(i);
	fill(V,V + n,0);
	reverse(ord,ord + n);
	int tot = 0;
	vector<pi> V,T;
	loop(i,n)
	if(!::V[ord[i]]){
		int sum = 0,cnt = 0,cmax = 0; T.clear();
		dfs(ord[i],sum,cmax,cnt,ord[i],T);
		tot += sum - cmax;
		bool c = 1; int j;
		loop(i,sz(T)){ 
			auto e = T[i]; 
			//cerr << e.xx << " " << e.yy << endl;
			if(C[e.xx][e.yy] == cmax && c) {
				j = i;
				c = 1;
				continue;
			}
		}
		int u;
		if(j == sz(T) - 1) u = T[0].xx;
		else u = T[j + 1].xx;
		range(i,j + 1,sz(T) - 1) V.pb(mp(u,T[i].yy)),u = T[i].yy;		
		loop(i,j) V.pb(mp(u,T[i].yy)),u = T[i].yy;	
	}
	printf("%d\n",tot);
	printf("%lu\n",sz(V));
	for(auto e : V) printf("%d %d\n",min(e.xx,e.yy) + 1,max(e.xx,e.yy) + 1);
	return 0;
}
