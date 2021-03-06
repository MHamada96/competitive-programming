#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define step(i,a,b,d) for(int i = (a);i <= (b); i += d)
#define all(A) A.begin(),A.end()
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define len(A) A.length()
#define print(A,t) cout << #A << ": "; copy(all(A),ostream_iterator<t>(cout," " )); cout << endl
#define pi pair<int,int>
#define point pi
#define vi vector<int>
#define ll long long
#define pl pair<ll,ll>
#define pre() cin.tie(0),cout.tie(0),ios_base::sync_with_stdio(0)
#define popcnt(x) __builtin_popcount(x)
#define LSOne(x) ((x) & (-(x)))
#define xx first
#define yy second
#define prp(p) cout << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cout << #A << ": "; copy(A,A + n,ostream_iterator<t>(cout," " )); cout << endl
using namespace std;

int n;
pi P[1 << 20];
int A[1 << 20];

bool cmp(const int & a,const int & b){
	double t1 = atan2(P[a].yy,P[a].xx),t2 = atan2(P[b].yy,P[b].xx);
	if(t1 == t2) return hypot(P[a].xx,P[a].yy) < hypot(P[b].xx,P[b].yy);
	return t1 < t2;
}
const double PI = 3.141592653589793238462643383;

int main(){
	scanf("%d",&n);
	loop(i,n) scanf("%d %d",&P[i].xx,&P[i].yy),A[i] = i;
	sort(A,A + n,&cmp); double ans = 2*PI; pi anc = {0,1};
	loop(i,n){
		int j = i + 1; if(j == n) j = 0;
		double t1 = atan2(P[A[i]].xx,P[A[i]].yy); if(t1 < 0) t1 += 2*PI;
		double t2 = atan2(P[A[j]].xx,P[A[j]].yy); if(t2 < 0) t2 += 2*PI;
		double t = max(t1,t2) - min(t1,t2);
		t = min(t,2*PI - t);
		if(t < ans){
			ans = t;
			anc = mp(min(A[i],A[j]),max(A[i],A[j]));
		}
		else if(abs(t - ans) < 1e-9 && mp(min(A[i],A[j]),max(A[i],A[j])) < anc) 
			anc = mp(min(A[i],A[j]),max(A[i],A[j]));
		cerr << A[i] << " " << A[j] << " " << t << " " << abs(t - ans) << endl;
	}
	printf("%d %d\n",anc.xx+1,anc.yy+1);
	return 0;
}
