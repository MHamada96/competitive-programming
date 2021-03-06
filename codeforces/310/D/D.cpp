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

pair<pl,int> event[1 << 22];
pl A[1 << 20],B[1 << 20];
int N,n,m;
int ans[1 << 20];


int main(){
	scanf("%d %d",&N,&m); n = N - 1;
	loop(i,N) scanf("%I64d %I64d",&A[i].xx,&A[i].yy);
	loop(i,m) scanf("%I64d",&B[i].xx), B[i].yy == i;
	//cerr << "here" << endl;
	loop(i,n) {
		event[2*i] = mp(mp(A[i + 1].xx - A[i].yy,-1),i);
		event[2*i + 1] = mp(mp(A[i + 1].yy - A[i].xx,2),i);
	}
	loop(i,m) event[i + 2*n] = mp(mp(B[i].xx,0),i);
	sort(event,event + 2*n + m);
	set<pl> S;
	//cerr << "z here" << endl;
	//cerr << 2*n + m << endl;
	loop(i,2*n + m){
	//	cerr << event[i].xx.xx << " " << event[i].xx.yy << " " << event[i].yy << endl;
		if(event[i].xx.yy == 0){
			if(S.empty()) continue;
			auto p = *S.begin();
			ans[p.yy] = event[i].yy + 1;
	//		cerr << "assign bridge " << event[i].yy + 1 << " to " << p.yy << endl;
			S.erase(S.begin());
		}
		else if(event[i].xx.yy == -1){
			ll idx = event[i].yy;
			ll v = A[idx + 1].yy - A[idx].xx;
	//		cerr << "inset " << v << " " << idx << endl;
			S.insert(mp(v,idx));
		}
		else S.erase(mp(event[i].xx.xx,event[i].yy));
	//	for(auto s : S) cerr << "(" << s.xx << " ," << s.yy << ") ";
	//	cerr << endl;
	}
	//cerr << "h here " << endl;
	bool c = 1;
	loop(i,n) c &= ans[i] != 0;
	if(!c){
		puts("No");
		return 0;
	}	
	puts("Yes");
	loop(i,n) printf("%d%s",ans[i],(i == n - 1) ? "\n" : " ");
	return 0;
}
