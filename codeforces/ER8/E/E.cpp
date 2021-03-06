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

char G[4000][4000];
int ROW[4000][4000];
int DIG[4000][4000];
int TOT[4000][4000];

int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	int L = min(m,n);
	loop(i,m) scanf("%s",G[i]);
	loop(i,m) loop(j,n){
		ROW[i][j] = G[i][j] == 'z';
		ROW[i][j] += j ? ROW[i][j - 1] : 0;
		DIG[i][j] = G[i][j] == 'z';
		if(i - 1 >= 0 && j + 1 < n) DIG[i][j] += DIG[i - 1][j + 1];
		TOT[i][j] = G[i][j] == 'z';
		if(i) TOT[i][j] += TOT[i - 1][j];
		if(j) TOT[i][j] += TOT[i][j - 1];
		if(i && j) TOT[i][j] -= TOT[i - 1][j - 1];
	}	
	int ctr = 0;
	int ans = 0;
	range(l,1,L){
		loop(i,m - l + 1){
			loop(j,n - l + 1){
				int e = j + l - 1;
				int c1 = ROW[i][e] - (j ? ROW[i][j - 1] : 0),
					c2 = ROW[i + l - 1][e] - (j ? ROW[i + l - 1][j - 1] : 0),
					c3 = DIG[i + l - 1][j];
				if(i - 1 >= 0 && e + 1 < n) c3 -= DIG[i - 1][e + 1];
				if(c1 == l && c2 == l && c3 == l) ans++;
			}
		}
	}
	cerr << ctr << endl;
	cout << ans << endl;
	cerr << ans << endl;
	return 0;
}
