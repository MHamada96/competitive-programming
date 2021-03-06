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

const ll mod = 1000000007;

ll add(ll a,ll b){
	a %= mod;
	b %= mod;
	a += b;
	return (a%mod + mod)%mod;
}

ll mul(ll a,ll b){
	a %= mod;
	b %= mod;
	a *= b;
	return (a%mod + mod)%mod;
}

void mul(ll A[3][3],ll B[3][3],ll C[3][3]){
	ll Z[3][3] = {0};
	for(int i = 0;i < 3;i++) for(int j = 0;j < 3;j++){
		Z[i][j] = 0;
		for(int k = 0;k < 3;k++){
			Z[i][j] = add(Z[i][j],mul(A[i][k],B[k][j]));
		}
	}
	for(int i = 0;i < 3;i++) for(int j = 0;j < 3;j++) C[i][j] = Z[i][j];
}

void EXP(ll A[3][3],ll p){
	if(p == 0) {
		fill(&A[0][0],&A[3][0],0);
		loop(i,3) A[i][i] = 1;
		return;
	}
	if(p == 1) return;
	ll B[3][3];
	mul(A,A,B);
	EXP(B,p >> 1);
	if(p & 1) mul(B,A,B);
	for(int i = 0;i < 3;i++) for(int j = 0;j < 3;j++) A[i][j] = B[i][j];
}

int main(){
	ll A,B,n,x;
	cin >> A >> B >> n >> x;	
	if(n == 0) cout << x % mod << endl;
	else if(n == 1) cout << add(mul(A,x),B) << endl;
	else{
		ll AA[3][3] = {{A,0,1},{1,0,0},{0,0,1}};
		ll BB[3] = {add(mul(A,x),B),x,B};
		EXP(AA,n - 1);
		ll ans = 0;
		loop(i,3) ans = add(ans,mul(AA[0][i],BB[i]));
		cout << ans << endl;
	}
	return 0;
}
