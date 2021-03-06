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

char line[1 << 20],c[1 << 20];
set<int> S;
int n,m,p;
int O[1 << 20];

int main(){
	scanf("%d %d %d",&n,&m,&p);
	scanf("%s",line);
	loop(i,n) S.insert(i + 1);
	vi ST;
	loop(i,n){
		if(line[i] == '(') ST.pb(i + 1);
		else {
			O[ST.back()] = i + 1;
			O[i + 1] = ST.back();
			ST.pop_back();
		}
	}
	scanf("%s",c);
	loop(i,m){
		if(c[i] == 'R'){
			auto q = S.find(p);
			++q;
			p = *q;
		}
		else if(c[i] == 'L'){
			auto q = S.find(p);
			--q;
			p = *q;
		}
		else{
			int o = O[p];
			if(o < p) swap(o,p);
			while(p != o){
				S.erase(p);
				p = *S.lower_bound(p);
			}
			S.erase(p);
			auto q = S.lower_bound(p);
			if(q == S.end()) --q;
			p = *q;
		}
	}
	for(auto q : S) putchar(line[q - 1]);
	puts("");
	return 0;
}
