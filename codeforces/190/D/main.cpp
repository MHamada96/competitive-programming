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

const int MAX = 5e5;
int A[MAX],F[MAX],n,m;
int cnt[MAX],k;

int main(){
	scanf("%d %d",&n,&k);
	loop(i,n) scanf("%d",A + i),F[i] = A[i];	
	sort(F,F + n);
	m = unique(F,F + n) - F;
	loop(i,n) A[i] = lower_bound(F,F + m,A[i]) - F;
	int r = 0,cond = 0;
	ll ans = 0;
	loop(l,n){
		while(r < n && !cond){
			int v = A[r++];
			cnt[v]++;
			cond = cnt[v] == k;
		}
		if(cond) ans += n - r + 1;
		if(cnt[A[l]] == k) cond = 0;
		cnt[A[l]]--;
	}
	cout << ans << endl;
	cerr << ans << endl;
	return 0;
}
