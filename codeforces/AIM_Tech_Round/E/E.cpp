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

pl P[1 << 20];
int n;
ll ans = LLONG_MAX;
ll max_pref[1 << 20],min_pref[1 << 20];
ll max_suff[1 << 20],min_suff[1 << 20];


ll sqr(ll x){
	return x*x;
}

ll SQRT(ll x){
	ll u = sqrt(x);
	while(sqr(u + 1) <= x) u++;
	return u;
}

bool f(ll R){
	loop(l,n){
		int r = upper_bound(P,P + n,mp(P[l].xx + SQRT(R),LLONG_MAX)) - P - 1;
		ll y1 = LLONG_MAX,y2 = LLONG_MIN;
		if(l) y1 = min(y1,min_pref[l - 1]),y2 = max(y2,max_pref[l - 1]);
		if(r < n - 1) y1 = min(y1,min_suff[r + 1]),y2 = max(y2,max_suff[r + 1]);
		if(!l && r >= n - 1) return 1;
		ll d = sqr(y2 - y1);
		d = max(d,sqr(P[l].xx) + sqr(y1));
		d = max(d,sqr(P[l].xx) + sqr(y2));
		d = max(d,sqr(P[r].xx) + sqr(y1));
		d = max(d,sqr(P[r].xx) + sqr(y2));
		if(R == 28421) cerr << l << " " << r << " " << d << endl;
		if(d <= R) return 1;
	}
	return 0;
}

void solve(){
	sort(P,P + n);	
	loop(i,n){
		int j = n - 1 - i;
		min_pref[i] = min(P[i].yy,i ? min_pref[i - 1] : LLONG_MAX);
		max_pref[i] = max(P[i].yy,i ? max_pref[i - 1] : LLONG_MIN);
		min_suff[j] = min(P[j].yy,i ? min_suff[j + 1] : LLONG_MAX);	
		max_suff[j] = max(P[j].yy,i ? max_suff[j + 1] : LLONG_MIN);	
	}
	//loop(i,n) cerr << P[i].xx << " " << P[i].yy << " " << min_pref[i] << " " << max_pref[i] << " " <<
	//		 min_suff[i] << " " << max_suff[i] << endl;
	ll s = 0,e = 1LL << 60;
	while(s < e){
		ll m = (s + e) >> 1;
		if(f(m)) e = m;
		else s = m + 1;
	}
	cerr << s << endl;
	ans = min(ans,s);
}
int main(){
	scanf("%d",&n);
	loop(i,n) scanf("%I64d %I64d",&P[i].xx,&P[i].yy);
	solve();
	loop(i,n) swap(P[i].xx,P[i].yy);
	solve();
	cout << ans << endl;
	cerr << ans << endl;
	return 0;
}
