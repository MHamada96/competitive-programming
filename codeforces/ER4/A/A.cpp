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

int n,p,q;
string s;
int dp[1 << 10];

int can(int i){
	if(i > n) return -1;
	if(i == n) return n;	
	if(dp[i] != 0) return dp[i];
	dp[i] = -1;
	if(can(i + p) != -1) dp[i] = i + p;
	if(can(i + q) != -1) dp[i] = i + q;
	return dp[i];
}

int main(){
  	cin >> n >> p >> q >> s;
	vector<string> V;
	if(can(0) == -1){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0;i < n;){
		int j = can(i);
		string z = "";
		for(;i < j;i++) z += s[i];
		V.pb(z);
	}
	printf("%lu\n",sz(V));
	for(auto u : V) printf("%s\n",u.c_str());
	return 0;
}
