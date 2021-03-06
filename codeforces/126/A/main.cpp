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

ll t1,t2,x1,x2,t0;

ll diff(ll y1,ll y2){
	return t1*y1 + t2 * y2 - t0 * (y1 + y2);
}

bool valid(ll y1,ll y2){
	return diff(y1,y2) >= 0;
}

void choose(ll & c1,ll & c2,ll y1,ll y2){
	if(c1 == -1) c1 = y1,c2 = y2;
	else{
		ll len = ((c1 + c2)/__gcd(y1 + y2,c1 + c2)) * (y1 + y2);
		ll e1 = (t1*c1 + t2 * c2)*(len/(c1 + c2)) - len*t0;
		ll e2 = (t1*y1 + t2 * y2)*(len/(y1 + y2)) - len*t0;;
		if(e2 < e1) c1 = y1,c2 = y2; 
		else if(e1 == e2 && c1 + c2 < y1 + y2) 
			c1 = y1,c2 = y2;
	}
}
int main(){
	cin >> t1 >> t2 >> x1 >> x2 >> t0;
	if(t1 == t0 && t2 == t0) cout << x1 << " " << x2 << endl;
	else if(t2 == t0) cout << 0 << " " << x2 << endl;
	else if(t1 == t0) cout << x1 << " " << 0 << endl;
	else{
		ll c1 = -1,c2 = 0;
		for(ll y1 = 0;y1 <= x1;y1++){
			ll y2 = (t1-t0)*y1/(t0 - t2);
			if(y2 > x2) y2 = x2;
			if(y2 < 0) y2 = 0;
			range(i,-1,1)			
				if(y2 + i >= 0 && y2 + i <= x2 && y1 + y2 && diff(y1,y2 + i) >= 0) {
					choose(c1,c2,y1,y2 + i);			
				}
		}
		for(ll y2 = 0;y2 <= x2;y2++){
			ll y1 = (t2-t0)*y2/(t0 - t1);
			if(y1 > x1) y1 = x1;
			if(y1 < 0) y1 = 0;
			range(i,-1,1)			
				if(y1 + i >= 0 && y1 + i <= x1 && y1 + y2 && diff(y1 + i,y2) >= 0) {
					choose(c1,c2,y1,y2);			
				}
		}
		if(valid(x1,0)) choose(c1,c2,x1,0);
		if(valid(x1,x2)) choose(c1,c2,x1,x2);
		if(valid(0,x2)) choose(c1,c2,0,x2);
		cout << c1 << " " << c2 << endl;	
		cerr << c1 << " " << c2 << endl;
	}
	
	return 0;
}
