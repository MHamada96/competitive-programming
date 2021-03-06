#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long>
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

#define c2d(c) (c - '0')
const int MAX = 4010;

int A[MAX],k,L;
char line[MAX];
ll cnt[MAX << 4];

int main(){
	scanf("%d %s",&k,line); L = strlen(line);
	loop(i,L) A[i] = c2d(line[i]) + (i ? A[i - 1] : 0);
	loop(j,L) loop(i,j + 1) cnt[A[j] - (i ? A[i - 1] : 0)]++;
	ll ans = 0;	
	loop(i,MAX << 4) 
		ans += (i && k/i < (MAX << 4)) ? (cnt[i] * cnt[k/i] * (k%i == 0)) : (cnt[0]*L*(L + 1LL)/2*(k==0));
	cerr << ans << endl;
	cout << ans << endl;

	return 0;
}
