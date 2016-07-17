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

int G[8][8],ord[8];

int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		loop(i,n) loop(j,n) scanf("%d",&G[i][j]);
		loop(i,n) ord[i] = i;
		int ans = 100000;
		do{
			int tmp = 0;
			loop(j,n - 1){
				int u = ord[j],v = ord[j + 1];
				tmp += G[u][v] == 0;
			}
			ans = min(ans,tmp);
		}while(next_permutation(ord,ord + n));
		printf("%d\n",ans);	
	}
	return 0;
}
