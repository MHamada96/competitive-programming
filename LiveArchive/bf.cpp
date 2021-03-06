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
using namespace std;

map<vi,ll> dp[71];
vi primes;
vi sol;

int mod = 1e9;

void dfs(int n,int i,ll m){
	sol.pb(m);
	for(int j = i;j < sz(primes) && primes[j] <= n;j++)
		dfs(n - primes[j],j,m*primes[j] % mod);
}


int main(){
	for(int i = 2;i <= 70;i++){
		bool c = 1;
		for(int j = 2;j*j <= i && c;j += 1)
			if(i%j == 0) c = 0;
		if(c) primes.pb(i);
	}
	int n,t; cin >> t;
	while(t--){
		cin >> n >> mod;
		sol.clear();
		dfs(n,0,1%mod);
		sort(all(sol));
		cout <<	unique(all(sol)) - sol.begin() << endl;
	}
}
