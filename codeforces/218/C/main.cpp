#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0,L = (n);i < L;i++)
#define range(i,a,b) for(int i = (a),L = (b);i <= L;i++)
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

#define hash(c) ((c == 'B') ? 0 : ((c == 'S') ? 1 : 2))

int need[3],has[3],price[3],L;
char line[101];
ll k;

bool can(ll q){
	ll tot = 0;
	for(int i = 0;i < 3;i++) tot += max(0LL,q*need[i] - has[i])*price[i];
	return tot <= k;
}

int main(){
	PRESTDIO();
	cin >> line; L = strlen(line);
	for(int i = 0;i < L;i++) need[hash(line[i])]++;
	for(int i = 0;i < 3;i++) cin >> has[i];
	for(int i = 0;i < 3;i++) cin >> price[i];
	cin >> k;
	ll s = 0,e = k + 101;
	while(s < e){
		ll m = s + (e - s + 1)/2;
		if(can(m)) s = m;
		else e = m - 1;
	}
	cout << s << endl;
	cerr << s << endl;
	return 0;
}
