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

int V[6000001][2];

int main(){
	freopen("feast.in","r",stdin);
	freopen("feast.out","w",stdout);																																																																																																																																												
	int T,A,B;
	scanf("%d %d %d",&T,&A,&B);
	queue<pi> q;
	q.push(mp(0,1));
	int ans = 0;
	int d[] = {A,B};	
	while(!q.empty()){
		int u = q.front().xx,c = q.front().yy; q.pop();
		//cerr << u << endl;
		if(u > T) continue;
		ans = max(ans,u);
		loop(i,2){
			int v = u + d[i],nc = c;
			if(v <= T && !V[v][nc]){
		//		cerr << u << " " << c << " " << v << " " << nc << endl;
				V[v][nc] = 1;
				q.push(mp(v,nc));
			}	
		}
		int v,nc;
		if(c) {
			v = u >> 1;
			nc = 0;
			if(v <= T && !V[v][nc]){
		//		cerr << u << " " << c << " " << v << " " << nc << endl;
				V[v][nc] = 1;
				q.push(mp(v,nc));
			}
		}
	}	
	cout << ans << endl;
	return 0;
}