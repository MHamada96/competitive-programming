#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0,_ = (n);i < _;i++)
#define range(i,a,b) for(int i = (a),_ = (b);i <= _;i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b),_ = (a);i >= _;i--)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define vi vector<int>
#define vl vector<long>
#define vd vector<double>
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

int main(){
	int n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	ll ans = 0;
	range(z,1,n){
		int d1 = z + a + b,d2 = z + a + c,d3 = z + b + d,d4 = z + c + d;
		int low = max(max(max(d1,d2),max(d3,d4)),0);
		int high = min(min(min(d1,d2),min(d3,d4)) + n,9*n);
		ans += max(high - low,0);
	}
	cout << ans << endl;
	return 0;
}
/*
xay
bzc
qdl

x + z + a + b= S - d1
y + z + a + c = S
z + q + b + d = S
z + l + c + d = S

0 < S - d1 <= n
d1 < S <= n + d1
*/
