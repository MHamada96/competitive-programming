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

int dp[5001][5001];
pi R[5001][5001];

vi g(vi & s){
	vi z = s;
	reverse(all(z));
	int n = sz(s);
	loop(i,n) dp[i][0] = dp[0][i] = 0;
	range(i,1,n) range(j,1,n)
		if(s[i - 1] == z[j - 1]) {
			dp[i][j] = 1 + dp[i - 1][j - 1];
			R[i][j] = mp(i - 1,j - 1);
		}
		else if(dp[i][j - 1] > dp[i - 1][j]){
			dp[i][j] = dp[i][j - 1];
			R[i][j] = mp(i,j - 1);
		}
		else{
			dp[i][j] = dp[i - 1][j];
			R[i][j] = mp(i - 1,j);		
		}
	vi ret;
	int i = n,j = n;
	while(i && j){
		int ni = R[i][j].xx,nj = R[i][j].yy;
		if(i == ni + 1 && j == nj + 1) ret.pb(i - 1);
		i = ni,j = nj;
	}
	reverse(all(ret));
	return ret;
}

int f(vi & s){
	if(sz(s) == 0) return 0;
	vi idxs = g(s);	
	vi ns; int j = 0;
	loop(i,sz(s)){
		if(j < sz(idxs) && i == idxs[j]){
			j++;
		}
		else ns.pb(s[i]);
	}
	return 1 + f(ns);
}

int main(){
	int n;
	scanf("%d",&n);
	vi V(n);
	loop(i,n) scanf("%d",&V[i]);
	cout << f(V) << endl;
	return 0;
}
