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

ll SQRT(ll n){
	ll s = 1,e = n;
	while(s < e){
		ll m = (s + e) >> 1;
		if(n/m < m|| m*m > n) e = m ;
		else s = m + 1;
	}
	s--;
	return s;
}

ll mod = 1e9 + 7;

inline ll mul(ll a,ll b){
	a %= mod,b %= mod;
	return (a*b)%mod;
}

ll f(ll n){
	ll u = SQRT(n) + 3,ans = 0;
	while(u*u > n) u--;
	loop(i,u + 1) {
		if(!i) continue;
		ans += mul(i , n/i - u) + mul(mul(n/i +1 + 0LL,n/i + 0LL),500000004LL);
		ans %= mod;
	}
	ans %= mod;
	return ans;	
}

ll g(ll n,ll m){
	ll u = SQRT(n) + 3,ans = 0;
	while(u*u > n) u--;
	ll v = min(u,m) % mod;
	loop(i,v + 1){
		if(!i) continue;
		ans += mul(i,n/i - u + 0LL);
	}
	loop(i,u + 1){
		if(!i) continue;
		ll tmp = min(n/i,m) % mod;
		ans += mul(mul(tmp + 1LL,tmp) , 500000004LL);
		ans %= mod;
	}
	ans %= mod;
	return ans;
}

int main(){
	ll n,m,ans = 0;
	cin >> n >> m;
	if(n <= m) ans = mul(n,m)  - f(n);
	else ans = mul(n,m) - g(n,m);
	ans = (ans%mod + mod)%mod;
	cout << ans << endl;
	return 0;
}
