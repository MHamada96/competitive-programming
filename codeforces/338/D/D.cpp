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

const int MAX = 3e5;
int P[MAX],n;
int F[MAX][2];

const ll mod = 1e9 + 7;

ll EXP(ll b,int p){
	b %= mod;
	if( p == 0) return 1;
	if (p == 1) return b;
	return (EXP(b*b,p >> 1) * EXP(b,p & 1)) %mod;

}

int main(){
	scanf("%d",&n);
	loop(i,n) scanf("%d",P + i);
	int idx = 0;	
	ll sum = 1; ll ans = 1;
	sort(P,P + n); bool c= 1;
	loop(i,n){
		int j = i;
		while(j < n && P[i] == P[j]) {
			ans = (ans * P[i])%mod;	
			j++;
		}
		F[idx][0] = P[i];
		F[idx][1] = j - i;
		idx++;
		int tmp = j - i;
		if((tmp & 1) & c) sum = (sum * (j - i + 1)/2) % (mod - 1);
		else sum = (sum * (tmp + 1))%(mod - 1);
		i = j - 1;
		
	}
	if(c) {
		loop(i,mod){
			if((2*i + 1)%mod == sum){
				sum = i + 1;
				break;
			}
		}
	}
	cerr << ans << " " << sum << endl;
	cout << EXP(ans,sum) << endl;
	return 0;
}
