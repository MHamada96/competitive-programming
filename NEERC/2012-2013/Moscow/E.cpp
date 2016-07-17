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
using namespace std;

pair<long double,int> A[100000];
int n;
vector<pair<long double,int> > B,C,D,E;

int main(){
	pre();
	cin >> n;
	vi out;	
	loop(i,n){
		cin >> A[i].first;
		A[i].second = i;
		if(A[i].first == 1 || A[i].first == 0){
			if(out.empty()) out.pb(i);
			else out[0] =  (A[out[0]].first > A[i].first)? out[0] : i;
		}
		else if(A[i].first > 1) B.pb(A[i]);
		else if(A[i].first > 0) C.pb(A[i]);
		else if(A[i].first > -1) D.pb(A[i]);
		else E.pb(A[i]);
	}
	sort(all(B));
	sort(all(C));
	sort(all(D));
	sort(all(E));
	vi OUT;
	for(auto b : B) OUT.pb(b.second);
	int ctr = 0;
	for(auto e : E) {
		ctr += e.first == -1;
		if(ctr == 2) {OUT.pop_back();break;}
		OUT.pb(e.second);
	}
	if(sz(E) & 1) {
		if(D.empty()) OUT.pop_back();
		else if(A[OUT.back()].first * D.back().first > 1) OUT.pb(D.back().second);
		else if(A[OUT.back()].first * D.back().first > 0 && sz(OUT) == 1) OUT.pb(D.back().second);
		else OUT.pop_back();
	}
	if(OUT.empty()) {
		if(sz(D) >= 2) {
			if(C.empty()) OUT.pb(D[sz(D) - 1].second),OUT.pb(D[sz(D) - 2].second);
			else if(C.back().first > D[sz(D) - 1].first * D[sz(D) - 2].first || abs(C.back().first - D[sz(D) - 1].first * D[sz(D) - 2].first) < 1e-15) OUT.pb(C.back().second);
			else  OUT.pb(D[sz(D) - 1].second),OUT.pb(D[sz(D) - 2].second);
		}
		else if(!C.empty()) OUT.pb(C.back().second);
		else if(sz(D) == 1) OUT.pb(D[0].second);
		if(!sz(OUT)) OUT = out;
		else if(sz(OUT) == 1 && sz(out)){
			if(A[OUT[0]].first < A[out[0]].first)
				OUT = out;
		}
	}
	sort(all(OUT));
	cout << sz(OUT) << endl;
	for(int o : OUT) cout << o + 1 << " ";
	cout << endl;
}
