#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define step(i,a,b,d) for(int i = (a);i <= (b); i += d)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define len(A) A.length()
#define vi vector<int>
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
#define pre() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
using namespace std;

const int MAX = 2500;
int A[MAX][MAX],n,id[MAX],W[MAX],L[MAX],P[MAX][14],MX[MAX][14];
vector<pi> G[MAX];

int get(int a){
	return id[a] = (a == id[a]) ? a : get(id[a]);
}
void join(int a,int b,int c){
	int k1 = get(a),k2 = get(b);
	if(k1 == k2) return;
	G[a].pb(mp(b,c));
	G[b].pb(mp(a,c));
	if(W[k1] < W[k2]) swap(k1,k2);
	W[k1] += W[k2];
	id[k2] = k1;
}

void bfs(){
	queue<int> q;
	q.push(0);
	fill(P[0],P[1],-1);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto node : G[u]){
			int v = node.xx,w = node.yy;
			if(v != P[u][0]){
				q.push(v);
				L[v] = L[u] + 1;				
				P[v][0] = u;
				MX[v][0] = w;
				loop(i,13) {
					int t = P[u][i];
					if(t == -1) P[v][i + 1] = -1;
					else {
						P[v][i + 1] = P[t][i];
						MX[v][i + 1] = max(MX[t][i],MX[v][i]);
					}
				}
			}
		}
	}
}

int get(int a,int b){
	int ans = 0;	
	while(a != b){
		if(L[a] > L[b]) swap(a,b);
		int k = 0;
		while(k < 14 && P[b][k] != -1 && L[P[b][k]] > L[a]) k++;
		if(k == 0){
			ans = max(MX[b][0],ans);
			b = P[b][0];
			continue;
		}
		k--;
		ans = max(MX[b][k],ans);
		b = P[b][k];
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	loop(i,n) loop(j,n) scanf("%d",&A[i][j]);
	vector<pair<int,pi> > E;	
	loop(i,n) {
		id[i] = i;
		W[i] = 1;
		if(A[i][i] != 0) {
			puts("NOT MAGIC");
			return 0;
		}
		loop(j,i) {
			if(A[i][j] != A[j][i]) {
				puts("NOT MAGIC");
				return 0;
			}
			E.pb(mp(A[i][j],mp(i,j)));
		}
	}
	sort(all(E));
	for(auto & e : E) join(e.yy.xx,e.yy.yy,e.xx);
	bfs();	
	loop(i,n) loop(j,i) {
		if(A[i][j] != get(i,j)) {
			puts("NOT MAGIC");
			return 0;
		}
	}
	puts("MAGIC");	
	return 0;
}
