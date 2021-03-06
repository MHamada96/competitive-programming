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

int n,m;
bool f(ll h){
	ll x = h/2,y = h/3,z = h/6;
	ll l = m + z - x,r = y - n;
	ll a = min(r,z);
	if(l <= a && a >= 0 && x - z + r >= m && y - r >= n) return 1;
		
	return 0;
}

int main(){
	cin >> m >> n;
	if(n == 0) {
		cout << 2*m << endl;
		return 0;
	}
	if(m == 0){
		cout << 3*n << endl;
		return 0;
	}
	ll s = 1,e = 1e15;
	while(s < e){
	//	cerr << s << " " << e << endl;
		ll mid = s + ((e - s) >> 1);
		if(f(mid)) e = mid;
		else s = mid + 1;
	}
	//cerr << s << endl;
	cout << s << endl;
	return 0;
}
