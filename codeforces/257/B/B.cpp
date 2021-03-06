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

const int mod = 1e9 + 7;

void mul(int A[2][2],int B[2][2],int C[2][2]){
	int Z[2][2];
	loop(i,2) loop(j,2){
		Z[i][j] = 0;
		loop(k,2){
			Z[i][j] = (Z[i][j] + A[i][k] * B[k][j])%mod;
		}
	}
	copy(&Z[0][0],&Z[2][0],&C[0][0]);
}

void EXP(int A[2][2],int p){
	if(p == 1) return;
	int B[2][2];
	mul(A,A,B);
	EXP(B,p >> 1);
	if(p & 1) mul(A,B,B);
	copy(&B[0][0],&B[2][0],&A[0][0]);
}


int main(){
	int x,y,n;
	scanf("%d %d %d",&x,&y,&n);
	x = (x%mod + mod)%mod;
	y = (y%mod + mod)%mod;
	if(n == 1) cout << x << endl;
	else if(n == 2) cout << y << endl;
	else{
		int A[2][2] = {{1,-1},{1,0}};
		EXP(A,n - 2);
		int ans = (A[0][0] *1LL*y + A[0][1]*1LL*x)%mod;
		if(ans < 0) ans += mod;
		cout << ans << endl;
	}
	return 0;
}
