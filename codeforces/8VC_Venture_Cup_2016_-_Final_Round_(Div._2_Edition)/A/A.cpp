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

int G[11][11];
int r,c,n,k;

int main(){
	cin  >> r >> c >> n >> k;
	while(n--){
		int a,b;
		cin >> a >> b;
		G[--a][--b] = 1;
	}
	loop(i,r) loop(j,c){
		if(i) G[i][j] += G[i - 1][j];
		if(j) G[i][j] += G[i][j - 1];
		if(i && j) G[i][j] -= G[i - 1][j - 1];
	}
	int ans = 0;
	loop(x2,r) loop(x1,x2 + 1) loop(y2,c) loop(y1,y2 + 1){
		int tmp = G[x2][y2];
		if(x1) tmp -= G[x1 - 1][y2];
		if(y1) tmp -= G[x2][y1 - 1];
		if(x1 && y1) tmp += G[x1 - 1][y1 - 1];
		if(tmp >= k) ans++;
	} 
	printf("%d\n",ans);
	return 0;
}
