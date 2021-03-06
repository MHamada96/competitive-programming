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

int f[64];
char S[1 << 20];
const ll mod = 1e9 + 7;

int main(){
	loop(i,64) loop(j,64) f[i&j]++;
	scanf("%s",S);
	int n = strlen(S);
	ll ans = 1;
	loop(i,n) {
		int v = 0;
		if(isdigit(S[i])) v = S[i] - '0';
		else if(isupper(S[i])) v = S[i] - 'A' + 10;
		else if(islower(S[i])) v = S[i] - 'a' + 36;
		else if(S[i] == '-') v = 62;
		else v = 63;
		ans = ans * f[v];	
		ans %= mod;
	}	
	cout << ans << endl;
	cerr << ans << endl;
	return 0;
}
