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

pi P[1000];

int main(){
	set<pi> S;
	int N;
	while(cin >> N && N){
		S.clear();	
		loop(i,N) {
				cin >> P[i].first >> P[i].second;
			loop(j,i){
				int dx = P[i].first - P[j].first,dy = P[i].second - P[j].second;
				if(dx || dy){
					int g = __gcd(dx,dy);
					dx /= g;
					dy /= g;
				}
				if(dx < 0) dx = -dx,dy = -dy;
		//		cout << j << " " << i << " " << dx << " " << dy << endl;
				S.insert(mp(dx,dy));
			}
		}
		cout << sz(S) << endl;
	}
	return 0;
}
