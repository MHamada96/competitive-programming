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

vector<vector<pi> > solve(int a,int b){	
	vector<vector<pi> > ret;
	if(a == 0 && b == 0){
		ret.pb(vector<pi>(1,mp(0,0)));
		return ret;
	}
	loop(i,a + 1){
		loop(j,b + 1){
			if(i == 0 && j == 0) continue;	
			vector<vector<pi> > tmp = solve(a - i,b - j);
			for(auto sol : tmp) {
				if(sol.back() == mp(0,0)) sol.pop_back();
				sol.pb(mp(i,j));
				ret.pb(sol);
			}
		}
	}
	return ret;
}

int main(){
	vector<vector<pi> > sol = solve(5,3);
	for(auto & V : sol) sort(all(V));
	set<vector<pi> > S;
	for(auto & V : sol) S.insert(V);
	map<int,int> M;
	for(auto & V : S){
		int L = sz(V);
		if(M.find(L) == M.end()) M[L] = 0;
		M[L] += 1;
	}
	for(auto v : M) cerr << v.xx << " " << v.yy << endl;
	return 0;
}
