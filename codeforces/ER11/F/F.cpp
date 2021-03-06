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

const int MAX = 3e5;
ll A[MAX],S[MAX],TOT;
ll pref[MAX],suff[MAX];
int n;

ll g(int s,int e){
	ll sum = S[e] - S[s - 1];
	return TOT - pref[s - 1] - suff[e + 1] - (s - 1)*sum;
}

bool f(int p,ll v){
	int s = p,e = n;
	while(e - s > 1){
		int m = s + (e - s + 1)/2;
		if(g(p,m) <= v) s = m;
		else e = m - 1;
	}
	return g(p,s) <= v;
}

ll psi(int p){
	ll inf = 1LL << 60;
	ll s = -inf,e = inf;
	while(s < e){
		ll m = s + (e - s + 1) / 2;
		if(f(p,m)) e = m - 1;
		else s = m;
	}
	return s + 1;
}

int main(){
	scanf("%d",&n);
	range(i,1,n){
		scanf("%lld",A + i);
		S[i] = S[i - 1] + A[i];
		pref[i] = pref[i - 1] + i*A[i]; 	
	}
	TOT = pref[n];
	for(int i = n;i;i--) suff[i] = suff[i + 1] + A[i]*i;
	ll ans = 0;
	range(i,1,n) ans = max(ans,psi(i));
	cout << ans << endl;
	return 0;
}
