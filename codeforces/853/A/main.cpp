#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long long>
#define vd vector<double>
#define vp vector<pair<int,int> >
#define ll long long
#define pi pair<int,int>
#define popcnt(x) __builtin_popcountll(x)
#define LSOne(x) ((x) & (-(x)))
#define xx first
#define yy second
#define PQ priority_queue
#define print(A,t) cerr << #A << ": "; copy(all(A),ostream_iterator<t>(cerr," " )); cerr << endl
#define prp(p) cerr << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cerr << #A << ": "; copy(A,A + n,ostream_iterator<t>(cerr," " )); cerr << endl
#define PRESTDIO() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
#define what_is(x) cerr << #x << " is " << x << endl
#define bit_lg(x) (assert(x > 0),__builtin_ffsll(x) - 1)
const double PI = acos(-1);
using namespace std;


int C[1 << 20],ord[1 << 20];
int n,k;
int T[1 << 20];
ll ans = 0;

int main(){
	#ifdef HOME
		freopen("in.in", "r", stdin);
	#endif
	scanf("%d %d",&n,&k);
	loop(i,n) scanf("%d",C + i),ord[i] = i;
	sort(ord,ord + n,[](const int & a,const int & b){
		if(C[a] == C[b]) return a < b;
		else return C[a] > C[b];
	});
	set<int> S;
	for(int i = 0;i < n;i++) S.insert(i + k);
	for(int j = 0;j < n;j++) {
		int i = ord[j];
		auto p = S.lower_bound(i);
		T[i] = *p;
		ans += (*p - i + 0LL)*C[i];
		S.erase(p);
	}
	printf("%lld\n",ans);
	loop(i,n) printf("%d%c",T[i]+1," \n"[i==n-1]);
	return 0;
}
