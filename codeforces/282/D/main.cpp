#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long>
#define vd vector<double>
#define vp vector<pair<int,int> >
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

const int MAX = 1e5 + 1e2;
const ll mod = 1e9 + 7;
char P[MAX << 1],T[MAX << 1];
int Z[MAX << 1];
ll dp1[MAX],dp2[MAX];
int nxt[MAX];
int m,n;



void buildZ(char *P,int L,int *Z){
	int l = 0,r = 0;
	Z[0] = L;	
	range(i,1,L - 1){
		if(i > r){
			l = r = i;
			while(r < L && P[r - l] == P[r]) r++;
			Z[i] = r - l; 
			r--;
		}
		else{
			int k = i - l;
			if(Z[k] < r - i + 1) Z[i] = Z[k];
			else{
				l = i;
				while(r < L && P[r - l] == P[r]) r++;
				Z[i] = r - l;
				r--;
			}
		}
	}
}
	
void add(ll & x,ll y){
	x += y;
	x = (x%mod + mod)%mod;
}

ll solve(){
	nxt[m] = m+1;	
	for(int i = m - 1;i >= 0;i--) nxt[i] = (Z[i] == n) ? (i + n) : nxt[i + 1];
	ll ret = 0;
	dp2[0] = 1;	
	loop(i,m+1){
		add(ret, dp1[i]);
    	add(dp2[i], ret);
   	add(dp2[i + 1], dp2[i]);
    	add(dp1[nxt[i]], dp2[i]);
	}
	add(dp2[m],mod - 1);
	return dp2[m];
}

int main(){
	scanf("%s %s",P,T);
	m = strlen(P),n = strlen(T);
	T[n] = '$';
	strcpy(T + n + 1,P);
	buildZ(T,n + m + 1,Z);
	loop(i,m) Z[i] = Z[i + n + 1];
	ll ans = solve();
	cout << ans << endl;
	/*cerr << ans << endl;
	prArr(Z,m,int);
	prArr(nxt,m+1,int);
	prArr(dp1,m+1,ll);
	prArr(dp2,m+1,ll);	
	*/return 0;
}
