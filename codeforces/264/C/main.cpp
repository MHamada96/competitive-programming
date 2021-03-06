#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
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

int G[2000][2000];
ll DIAG[2*2000],rDIAG[2*2000];
ll F[2000][2000];
int n;

#define psi(p) F[p.xx][p.yy]

int main(){
	scanf("%d",&n);
	loop(i,n) loop(j,n) {
		scanf("%d",&G[i][j]);
		DIAG[i + j] += G[i][j];
		rDIAG[i - j + n - 1] += G[i][j];
	}
	loop(i,n) loop(j,n) F[i][j] = DIAG[i + j] + rDIAG[i - j + n - 1] - G[i][j];
	vector<pi> even,odd;
	even.pb(mp(0,0));even.pb(mp(0,0));
	odd.pb(mp(0,1));odd.pb(mp(0,1));
	loop(i,n) loop(j,n){
		if((i + j) & 1){
			if(F[i][j] >= psi(odd[0])) {
				odd[0] = mp(i,j);
				if(psi(odd[0]) > psi(odd[1])) swap(odd[0],odd[1]);
			}
		}
		else{
			if(F[i][j] >= psi(even[0])) {
				even[0] = mp(i,j);
				if(psi(even[0]) > psi(even[1])) swap(even[0],even[1]);
			}
		}
	}
	ll ans = -1;
	pi X,Y;
	loop(i,n) loop(j,n){
		if((i + j) & 1){
			pi Z = even[even.back() != mp(i,j)];
			if(F[i][j] + psi(Z) > ans) ans = F[i][j] + psi(Z),X = mp(i,j),Y = Z;
		}
		else{
			pi Z = odd[odd.back() != mp(i,j)];
			if(F[i][j] + psi(Z) > ans) ans = F[i][j] + psi(Z),X = mp(i,j),Y = Z;
		}
	}
	cout << ans << endl;
	cout << X.xx + 1 << " " << X.yy + 1 << " " << Y.xx + 1 << " " << Y.yy + 1 << endl;
	return 0;
}
