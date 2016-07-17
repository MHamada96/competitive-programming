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

void reduce(ll & a,ll & b){
	ll d = (a || b) ? __gcd(a,b) : 1;
	a /= d;
	b /= d;
}

ll lcm(ll a,ll b){
	return (a/__gcd(a,b))*b;
}

int main(){
	int T; ll a,b,c,d,x,y,xx,yy;
	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		reduce(a,b);
		reduce(c,d);
		x = lcm(a,c); y = __gcd(b,d);
		xx = __gcd(a,c); yy = lcm(b,d);
		reduce(x,y);
		reduce(xx,yy);
		printf("%lld/%lld %lld/%lld\n",xx,yy,x,y);
	}  
	return 0;
}
