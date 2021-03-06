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

int P[1 << 20][20], W[1 << 20],best[1 << 20][20];
ll ans[1 << 20];
pair<pi,pi> E[1 << 20];
vector<pi> G[1 << 20];

int get(int a){
	int b = a,t;
	while(a != P[a][0]) a = P[a][0];
	while(b != P[b][0]){
		t = P[b][0];
		P[b][0] = a;
		b = t;
	}
	return a;
}

int join(int a,int b,int c){
	int A = a,B = b;
	a = get(a),b = get(b);
	if(a == b) return 0;
	if(W[a] < W[b]) swap(a,b);
	P[b][0] = a;
	W[a] += W[b];
	G[A].pb(mp(B,c));
	G[B].pb(mp(A,c));
	//cerr << A << " " << B << " " << c << endl;
	return c;
}

void bfs(){
	queue<int> q;
	q.push(0); W[0] = 0;
	loop(i,20) P[0][i] = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		/*cerr << u << " : \n";
		loop(i,20) cerr << P[u][i] << " ";
		cerr << "\n";
		loop(i,20) cerr << best[u][i] << " ";
		cerr << "\n---------------------------------------------" << endl;
		*/for(auto p : G[u]){
			int v = p.xx,c = p.yy;
			if(v != P[u][0]){
				W[v] = W[u] + 1;
				P[v][0] = u;
				best[v][0] = c;
				loop(i,19) {
					if(P[v][i] == -1) P[v][i + 1] = -1;
					else P[v][i + 1] = P[P[v][i]][i];
					
					best[v][i + 1] = best[v][i];
					if(P[v][i] != -1) best[v][i + 1] = max(best[v][i + 1],best[P[v][i]][i]);					
				}
				q.push(v);
			}
		}
	}
}

int f(int a,int b){
	if(W[a] > W[b]) swap(a,b);
	int ans = 0;
	while(W[a] != W[b]){
		int st = 0;		
		while(st < 20 && W[P[b][st]] >= W[a]) st++;
		if(st) --st;
		ans = max(ans,best[b][st]);
		b = P[b][st];
	}
	while(a != b){
		int st = 0;
		while(P[a][st] != P[b][st]) st++;
		if(st) st--;
		ans = max(ans,best[a][st]);
		ans = max(ans,best[b][st]);
		a = P[a][st];
		b = P[b][st];
	}
	return ans;
}

int main(){
  	int n,m;
	scanf("%d %d",&n,&m);
	loop(i,n) P[i][0] = i,W[i] = 1;
	loop(i,m) {
		scanf("%d %d %d",&E[i].yy.xx,&E[i].yy.yy,&E[i].xx.xx);
		E[i].yy.xx--;
		E[i].yy.yy--;
		E[i].xx.yy = i;
	}
	ll tot = 0;	
	sort(E,E + m);
	loop(i,m) tot += join(E[i].yy.xx,E[i].yy.yy,E[i].xx.xx);
	bfs();
	loop(i,m) ans[E[i].xx.yy] = tot + E[i].xx.xx - f(E[i].yy.xx,E[i].yy.yy);
	loop(i,m) printf("%I64d\n",ans[i]);
	return 0;
}
