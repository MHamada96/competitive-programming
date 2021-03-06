#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long long>
#define vd vector<double>
#define vp vector<pair<int,int> >
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

const int MAX = 2010,mod = 1e9 + 7;
int C[MAX][MAX];
int E[MAX],F[MAX];

int mul(int x,int y){
	return (x*1LL*y)%mod;
}

int add(int x,int y){
	x += y;
	if(x >= mod) x -= mod;
	if(x < 0) x += mod;
	return x;
}

int POW(int x,int p){
	if(!p) return 1;
	int y = 1;
	for(;p > 1; p >>= 1){
		if(p & 1) y = mul(x,y);
		x = mul(x,x);
	}
	return mul(x,y);
}

int main(){
	loop(n,MAX){
		C[n][0] = C[n][n] = 1;
		range(r,1,n-1) C[n][r] = add(C[n - 1][r],C[n - 1][r - 1]);
	}
	E[0] = F[0] = 1;
	range(i,2,MAX - 1) E[i] = mul(i-1,add(E[i - 1],E[i - 2]));
	range(i,1,MAX - 1) F[i] = mul(F[i - 1],i);

	set<int> A,B;
	int n; cin >> n;
	loop(i,n) A.insert(i + 1);
	loop(i,n){
		int a; cin >> a;
		if(a == -1) B.insert(i + 1);
		else A.erase(a);
	}
	assert(sz(A) == sz(B));
	n = sz(B); int m = 0;
	for(int x : A) m += B.find(x) != B.end();
	//print(A,int);
	//print(B,int);

	int ans = 0;
	range(i,0,m) {
		int sgn = (i & 1) ? -1 : 1;
		ans = add(ans,sgn* mul(C[m][i],F[n - i]));
	//	fprintf(stderr,"%c C[%d][%d] * %d!\n","+-"[i&1],m,i,n - i);	
	}
	
	cout << ans << endl;
	cerr << ans << endl;
	
	return 0;
}
