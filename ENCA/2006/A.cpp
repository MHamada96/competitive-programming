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
using namespace std;

vi G[101];
int V[101];
int n,m;

bool dfs(int u,int p){
	V[u] = 1;
	for(int v : G[u])
		if(V[v]){
			if(v != p) return 1;
		}
		else dfs(v,u);
	return 0;
}

bool is_tree(){
	fill(V,V + n + 1,0);
	if(dfs(1,0)) return 0;
	loop(i,n) if(!V[i + 1]) return 0;
	return 1;
}

int main(){
	int a,b;
	for(int t = 1;scanf("%d",&n) == 1 && n;t++){
		scanf("%d",&m);
		loop(i,n) G[i + 1].clear();
		while(m--){
			scanf("%d %d",&a,&b);
		//	cout << a << " " << b << endl;
			G[a].pb(b);
			G[b].pb(a);
		}
		bool cond = 0;
		if(is_tree()){
		//	cout << "here" << endl;
			cond = 1;			
			loop(i,n){
				int ctr = 0;
				for(int v : G[i + 1]) ctr += sz(G[v]) > 1;
				if(ctr > 2) cond = 0;//,cout << i + 1 << endl;
			}
		}
		printf("Graph %d is %sa caterpillar.\n",t,cond ? "" : "not ");
	}
	return 0;
}

