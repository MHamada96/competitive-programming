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

const int MAX = 2e5;
ll dist,station_count,tank_cap;
pl station[MAX];
ll X[MAX << 1];
ll ans = 0;

int main(){
	scanf("%I64d %I64d %I64d",&dist,&tank_cap,&station_count);
	loop(i,station_count) {
		scanf("%I64d %I64d",&station[i].yy,&station[i].xx);
		X[i] = station[i].yy;	
	}
	X[station_count] = 0; X[station_count + 1] = dist;
	sort(X,X + station_count + 2);
	loop(i,station_count + 1) if(X[i + 1] - X[i] > tank_cap) {
		puts("-1");
		return 0;
	}
	
	sort(station,station + station_count);
	map<ll,ll> fuel;
	fuel[0] = tank_cap;
	fuel[dist] = 0;
	loop(i,station_count){
		auto v = fuel.lower_bound(station[i].yy),u = v; --u;
		if(u->yy >= v->xx - u->xx) continue; 
		ll in_fuel = u->xx + u->yy - station[i].yy; in_fuel = max(in_fuel,0LL);
		ll out_fuel = v->xx - station[i].yy; out_fuel = min(out_fuel,tank_cap + 0LL);
		ans += max(0LL,out_fuel - in_fuel)*station[i].xx;
		fuel[station[i].yy] = max(in_fuel,out_fuel);		
	}
	cout << ans << endl;
	return 0;
}
