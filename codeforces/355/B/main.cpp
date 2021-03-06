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

int n,h,k;
int A[1 << 20];
ll ans = 0;

int main(){
	scanf("%d %d %d",&n,&h,&k);
	loop(i,n) scanf("%d",A + i);
	ll cur = 0; int i = 0;
	for(int j = 0;i < n;j++){
		//cerr << j << " " << i << " cur = " << cur << " " << A[i] << endl;
		while(i < n && cur + A[i] <= h) cur += A[i++];
		//h - cur + t*k < A[i];
		//t < (A[i] + cur - h + k - 1)/k
		ll t = (A[i] + cur - h + k - 1)/k;
		ans += t;
		cur -= k*t; 
		cur = max(cur,0LL);
	}
	//cerr << cur << endl;
	ans += (cur + k - 1)/k;
	cout << ans << endl;
	cerr << ans << endl;
	return 0;
}
