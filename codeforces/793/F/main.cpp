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
#define popcnt(x) __builtin_popcount(x)
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

const int MAX = 100*1000 + 10;
int L[MAX],R[MAX],n,m;
int qL[MAX],qR[MAX],q;
pair<pi,int> ord[MAX << 1];
int ans[MAX];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
	#endif
	scanf("%d %d",&n,&m);
	loop(i,m) scanf("%d %d",L + i,R + i),ord[i] = mp(mp(L[i],1),i);
	scanf("%d",&q);
	loop(i,n) scanf("%d %d",qL + i,qR + i),ord[i + m] = mp(mp(qL[i],-1),i);

	sort(ord,ord + m + q);
	set<int> R;
	for(int i = m + q - 1;i >= 0;i--){
		int type = ord[i].xx.yy;
		int l = ord[i].xx.xx,r,idx = ord[i].yy;
		if(type == 1) r = R[idx];
		else r = qR[idx];

		if(type == -1){
			auto p = R.upper_bound(r);
			if(p == R.begin()) ans[idx] = l;
			else {
				
			}
		}
		else{

		}
	}
	loop(i,q) printf("%d\n",ans[i]);
	return 0;
}
