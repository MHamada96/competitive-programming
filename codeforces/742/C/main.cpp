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

const int MAX = 111;
int to[MAX],vis[MAX],n;
set<int> S;

int main(){
	scanf("%d",&n);
	loop(i,n) {
		scanf("%d",to + i);
		to[i]--;
		S.insert(to[i]);
	}
	if(sz(S) != n){
		puts("-1");
		return 0;
	}
	ll ans = 1;
	loop(i,n){
		if(vis[i]) continue;
		int j = i,len = 0;
		while(!vis[j]){
			len++; vis[j] = 1;
			j = to[j];
		}
		if(len%2 == 0) len >>= 1;
		ans = (ans/__gcd(ans,len+0LL)) * len;
	}
	cout << ans << endl;
	return 0;
}
