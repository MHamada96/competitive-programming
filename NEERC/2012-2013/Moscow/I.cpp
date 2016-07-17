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

ll x,y;
ll solve(ll X,ll Y){
	bool c = X%x && Y%y;
	ll ans = (X/x) * (Y/y);
	if(X%x){
		ll t = X%x;
		t = x/t;
		ans += (Y/y + t - 1)/t;
		c = !((Y/y)%t);
	}
	if(Y%y){
		ll t = Y%y;
		t = y/t;
		ans += (X/x + t - 1)/t;
		c = !((X/x)%t);
	}
	ans += c;
	return ans;
}

int main(){
	ll X,Y;
	cin >> X >> Y >> x >> y;
	cout << solve(X,Y) << endl;
	return 0;
}
