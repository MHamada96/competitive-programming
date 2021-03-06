#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
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

vi G[1 << 20];
vi U[2];
int V[1 << 20];

bool dfs(int u,int c){
	V[u] = c;
	U[c - 1].pb(u);
	for(int v : G[u]){
		if(V[v]){
			int nc = (c == 1) ? 2 : 1;
			if(V[v] != nc) return 0;
		}
		else if(!dfs(v,(c == 1) ? 2 : 1)) return 0;
	}
	return 1;	
}

int main(){
	int n,m,a,b;
	scanf("%d %d",&n,&m);
	loop(i,m){
		scanf("%d %d",&a,&b);
		G[a].pb(b);
		G[b].pb(a);
	}
	bool c = 1;
	loop(i,n) if(!V[i + 1]) c &= dfs(i + 1,1);
	if(!c || U[0].empty() || U[1].empty()){
		puts("-1");
		return 0;
	}
	loop(i,2){
		printf("%lu\n",sz(U[i]));
		for(int u : U[i]) printf("%d ",u);
		puts("");
	}
	return 0;
}
