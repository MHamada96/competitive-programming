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

const int MAX = 1e5 + 1e2;
int A[MAX],val[MAX],n;
vector<vi> LIS;

void solve(){
	memset(val,0,sizeof val);
	LIS.clear();	
	scanf("%d",&n);
	loop(i,n) scanf("%d",A + i);
	loop(i,n){
		if(LIS.empty() || A[i] > A[LIS.back().back()]) LIS.pb(vi(1,i));
		else{
			auto p = lower_bound(all(LIS),i,[](const vi & V,const int & k){
				return A[V.back()] < A[k];
			});
			p->pb(i);
		}
	}
	reverse(all(LIS));
	vi alive; alive.pb(n); A[n] = 1 << 20;	
	for(auto V : LIS){
		vi tmp; int ctr = 0;
		for(int x : V){
			if(x > alive.back()) continue;
			else{
				auto p = lower_bound(all(alive),x);
				if(A[*p] > A[x]) tmp.pb(x),ctr++,val[x] = 1;
			}
		}
		for(int x : V){
			if(!val[x]) val[x] = 1;
			else val[x] = (ctr == 1) ? 3 : 2;
		}
		alive = tmp;
	}
	vi ans;
	loop(i,n) if(val[i] > 1) ans.pb(A[i]);
	sort(all(ans));
	printf("%d\n",sz(ans));
	loop(i,sz(ans)) printf("%d%c",ans[i]," \n"[i==sz(ans)-1]);
}

int main(){
	loop(i,10) solve();
	return 0;
}
