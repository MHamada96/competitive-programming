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

const int MAX = 2e5 ,MAXLG = 30;
vi G[MAX];
int depth[MAX],SZ[MAX],P[MAX][MAXLG],n;

int dfs(int u,int p = 0,int d = 1){
	depth[u] = d;
	P[u][0] = p;
	loop(i,MAXLG - 1) P[u][i + 1] = P[P[u][i]][i];
	for(int v : G[u]) if(v != p)  SZ[u] += dfs(v,u,d + 1);
	return ++SZ[u];
}

int get(int u,int d){
	assert(d >= 0);
	int ret = u,i = 0;
	while(d){
		int l = LSOne(d);
		for(;l > (1 << i);i++);
		ret = P[ret][i];
		d &= ~LSOne(d);
	}
	assert(ret);
	return ret;
}
int LCA(int a,int b){
	int k = MAXLG - 1;
	while(a != b){
		if(depth[b] < depth[a]) swap(a,b);
		while(k && depth[P[b][k]] < depth[a] ) k--;
		b = P[b][k];
		swap(a,b);
	}
	assert(a);
	return a;
}

int main(){
	scanf("%d",&n);
	loop(i,n - 1){
		int a,b;
		scanf("%d %d",&a,&b);
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(1);
	int m,a,b;
	scanf("%d",&m);
	while(m--){
		scanf("%d %d",&a,&b);
		if(a == b){
			printf("%d\n",n);
			continue;
		}
		int c = LCA(a,b),dist = depth[a] + depth[b] - 2*depth[c];
		if(depth[b] < depth[a]) swap(a,b);
		if(dist & 1) puts("0");
		else{
			dist >>= 1;
			if(c == a) printf("%d\n",SZ[get(b,dist)] - SZ[get(b,dist - 1)]);
			else if(depth[a] == depth[b]) printf("%d\n",n - SZ[get(a,dist - 1)] - SZ[get(b,dist - 1)]);
			else printf("%d\n",SZ[get(b,dist)] - SZ[get(b,dist - 1)]);
		}
	}
	return 0;
}
