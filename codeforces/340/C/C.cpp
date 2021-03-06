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

int n,x1,x2,Y1,Y2;
int P[2000][2];
int V[2000];

int main(){
	ll ans = LLONG_MAX;
	scanf("%d %d %d %d %d",&n,&x1,&Y1,&x2,&Y2);
	loop(i,n) loop(j,2) scanf("%d",&P[i][j]);
	loop(i,n){
		ll r = (P[i][0] - x1 + 0LL)*(P[i][0] - x1 + 0LL) + (P[i][1] - Y1 + 0LL)*(P[i][1] - Y1 + 0LL);
		fill(V,V + n,0);	
		ll tmp = 0;
		loop(j,n){
			ll d = (P[j][0] - x1 + 0LL)*(P[j][0] - x1 + 0LL) + (P[j][1] - Y1 + 0LL)*(P[j][1] - Y1 + 0LL);
			if(d > r){
				d = (P[j][0] - x2 + 0LL)*(P[j][0] - x2 + 0LL) + (P[j][1] - Y2 + 0LL)*(P[j][1] - Y2 + 0LL);
				tmp = max(d,tmp);
			}
		}
		ans = min(ans,tmp + r);
	}
	cout << ans << endl;
	return 0;
}
