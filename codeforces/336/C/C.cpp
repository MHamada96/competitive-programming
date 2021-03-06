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

pi P[1 << 20];
int n;
int dp[1 << 20];

bool cmp(const pi & p,const int x){
	return p.xx < x;
}

int f(int i){
	if(i == -1) return 0;
	else if(dp[i] != -1) return dp[i];
	else{
		int p = lower_bound(P,P + n,P[i].xx - P[i].yy,&cmp) - P - 1;
		return dp[i] = f(p) + i - p - 1;
	}
}

int main(){
	scanf("%d",&n);
	fill(dp,dp + n,-1);
	loop(i,n) scanf("%d %d",&P[i].xx,&P[i].yy);
	sort(P,P + n);
	int ans = n;
	loop(i,n + 1) ans = min(ans,i + f(n - i - 1));
	cout << ans << endl;
	cerr << ans << endl;
	return 0;
}
