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

int n,jar[1 << 20];
int nxt[1 << 20];

int main(){
	ll m = INT_MAX;
	scanf("%d",&n);
	loop(i,n) scanf("%d",jar + i),m = min(m,jar[i] + 0LL);
	vi cand; 
	loop(i,n) if(jar[i] == m) cand.pb(i);
	loop(i,n) if(jar[i] == m) cand.pb(i + n);
	int j = 0;	
	loop(i,n) {
		if(jar[i] == m) {
			nxt[i] = i;
			continue;		
		}
		while(j < sz(cand) && cand[j] < i) j++;
		if(j == sz(cand)) j = 0;
		nxt[i] = cand[j];
	}
	ll ans = 0;
	loop(i,n) {
		ll d = nxt[i] - i;
		ans = max(ans,n * m + d);
	}
	cout << ans << endl;
	return 0;
}
