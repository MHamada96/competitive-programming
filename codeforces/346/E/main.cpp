#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long long>
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

const int MAX = 1000010;
int n,a,b;
int F[MAX],lst[MAX];
vi X,Y;

int main(){
	scanf("%d",&n);
	X = vi(n);
	loop(i,n) scanf("%d",&X[i]);
	scanf("%d %d",&a,&b);
	sort(all(X));
	X.resize(unique(all(X)) - X.begin());
	int ans = 0;
	while(a != b){
		int to = a - 1; ans++;
		for(int x : X){
			int o = a - a%x;
			if(o >= b){
				Y.pb(x);
				to = min(to,o);
			}
		}
		X = Y; Y.clear();
		a = to;
	}
	cout << ans << endl;
	return 0;
}
