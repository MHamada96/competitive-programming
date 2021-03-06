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

const int MAX = 3e5;
ll A[MAX],S[MAX],TOT;
ll pref[MAX],suff[MAX];
int n;
/*
ll g(int s,int e){
	ll sum = S[e] - S[s - 1];
	return TOT - pref[s - 1] - suff[e + 1] - (s - 1)*sum;
}

// B = TOT - pref [s] - suff[e + 1]  - s*S[s]
// A = - s; x = S[e]

ll f(int p){
	int s = p,e = n;
	while(e - s > 1){
		int m1 = s + (e -s + 1)/3,m2 = m1 + (e - s + 1)/3;
		if(g(p,m1) < g(p,m2)) s = m1 + 1;
		else e = m2 - 1;
	}
	return max(g(p,s),g(p,e));
}
*/


// min pref[i] - pref[x] - x*(S[i] - S[x])
// min pref[i] - pref[x] - x*S[i] + x*S[x]
// A = -x,B = x*S[x] - pref[x]
// X = S[i];

ll f(pl & line,int i){
	return line.xx * S[i] + line.yy;
}

double g(pl a,pl b){
	return (b.yy - a.yy + 0.0)/(a.xx - b.xx);
}

int main(){
	scanf("%d",&n);
	range(i,1,n){
		scanf("%lld",A + i);
		S[i] = S[i - 1] + A[i];
		pref[i] = pref[i - 1] + i*A[i]; 	
	}
	TOT = pref[n];
	for(int i = n;i;i--) suff[i] = suff[i + 1] + A[i]*i;
	ll ans = 0;
	deque<pl> dq; dq.pb(mp(0,0));
	range(i,1,n){
		int s = 0,e = sz(dq) - 1;
		while(e - s > 1){
			int m1 = s + (e - s + 1)/3,m2 = m1 + (e - s + 1)/3;
			if(f(dq[m1],i) < f(dq[m2],i)) s = m1 + 1;
			else e = m2 - 1;
		}
		ans = max(ans,max(f(dq[s],i),f(dq[e],i)) + pref[i]);
		pl tmp = mp(-i,i*S[i] - pref[i]);
		while(sz(dq) > 1 && g(tmp,dq[1]) <= g(tmp,dq[0])) dq.pop_front();
		dq.push_front(tmp);
	}	
	cout << ans << endl;
	return 0;
}
