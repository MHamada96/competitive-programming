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

const int MAX = 110000;
int P[MAX],vis[MAX];
vi G[MAX];
int A[MAX],B[MAX],m,n,N;
int intime[MAX],dfs_time = 1;

bool dfs(int u,int q){
	if(vis[u]) return 1;
	if(B[u] != q) return 0;
	vis[u] = 1;
	bool c = 1;
	for(int v : G[u]) c &= dfs(v,q);
	return c;
}

void dfs2(int u){
	intime[u] = dfs_time++;
	for(int v : G[u]) dfs2(v);
}

bool cmp(const int & a,const int & b){
	return intime[a] > intime[b];
}

bool verify(){
	loop(i,N){
//		cerr << A[i] << " " << vis[A[i]] << endl;
		if(vis[A[i]]) return 0;
		if(!dfs(A[i],A[i])) return 0;
	}
	return 1;
}

int main(){
	int a,b;
	scanf("%d %d",&n,&m);	
	while(m--){
		scanf("%d %d",&a,&b);
		a--,b--;
		G[a].pb(b);
		P[b] = a;
	}
	loop(i,n) if(!intime[i]) dfs2(i);
	loop(i,n) {
		scanf("%d",A + i);
		B[i] = --A[i];
	}
	sort(A,A + n);
	N = unique(A,A + n) - A;
	sort(A,A + N,&cmp);
//	prArr(A,N,int);
	if(!verify()) puts("-1");
	else{
		printf("%d\n",N);
		loop(i,N) printf("%d\n",A[i] + 1);
	} 
	return 0;
}
