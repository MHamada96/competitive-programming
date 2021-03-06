#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define vi vector<int>
#define vl vector<long>
#define vd vector<double>
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

vi pos[128];
char line[1 << 20];
int n,k;

int main(){
	scanf("%d %d %s",&n,&k,line);
	loop(i,k) pos[line[i]].pb(i);
	loop(i,n){
		scanf("%s",line);
		k = strlen(line);
		ll F = 0;
		loop(j,k){
			int score = k;
			if(!pos[line[j]].empty()){
				auto v = upper_bound(all(pos[line[j]]),j);
				auto u = v;
				if(u != pos[line[j]].begin()) --u;
				if(v != pos[line[j]].end()) score = abs(j - *v);
				score = min(score,abs(j - *u));
			}
			F += score;
		}
		printf("%lld\n",F);
	}
	return 0;
}
