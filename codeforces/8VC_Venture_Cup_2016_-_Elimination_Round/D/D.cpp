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

ll freq[10001];
int A[2000],n;

int main(){
	scanf("%d",&n);
	loop(i,n) scanf("%d",A + i);
	sort(A,A + n);
	loop(i,n) loop(j,i) freq[A[i] - A[j]]++;
	loop(i,5001) freq[i] += i ? freq[i - 1] : 0;	
	ll ans = 0;
	loop(i,5000) loop(j,5000){
		ll x = freq[i] - (i ? freq[i - 1] : 0);
		ll y = freq[j] - (j ? freq[j - 1] : 0);
		if(i + j <= 5000 && x && y) {
			if(freq[5000] - freq[i + j]) cerr << i << " " << j << " " << x << " " << y << " " << freq[5000] - freq[i + j] << endl;
			ans += x*y*(freq[5000] - freq[i + j]);
		}
	}		
	ll tot = n*(n - 1)/2;
	tot = tot * tot * tot;
	cerr << ans << endl;
	printf("%.10f\n",ans*1.0/tot);
	return 0;
}
