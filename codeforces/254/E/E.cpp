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
int color[MAX],END[MAX],n,m,t,l,r,x;
set<int> start;
ll T1[MAX],T2[MAX];
void update(int p,ll v,ll *T){
	for(;p <= n;p += LSOne(p)) T[p] += v;
}
ll get(int p,ll *T){
	ll ret = 0;
	for(;p > 0;p -= LSOne(p)) ret += T[p];
	return ret;
}

void update_range(int l,int r,ll v){
	update(l,v,T1);
	update(r + 1,-v,T1);
	update(l,-(l - 1)*v,T2);
	update(r + 1,r*v,T2);
}

ll get(int p){
	return get(p,T1) * p + get(p,T2);
}

ll get_range(int l,int r){
	return get(r) - get(l - 1);
}

void update(){
	for(int i = l;i <= r;){
		auto p = start.upper_bound(i); --p;
		if(*p < i){
			END[i] = END[*p];
			END[*p] = i - 1;
			color[i] = color[*p];
			start.insert(i);
		}
		else if(END[*p] > r){
			END[r + 1] = END[*p];
			END[*p] = r;
			color[r + 1] = color[*p];
			start.insert(r + 1);
		}
		else{
			i = END[*p] + 1;
			update_range(*p,END[*p],abs(x - color[*p]));
			start.erase(p);
		}
	}
	start.insert(l);
	color[l] = x;
	END[l] = r;
}

void init(){
	range(i,1,n) {
		color[i] = i;
		END[i] = i;
		start.insert(i);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	init();
	while(m--){
		scanf("%d %d %d",&t,&l,&r);
		if(t == 1){
			scanf("%d",&x);
			update();	
		}
		else printf("%lld\n",get_range(l,r));
	}
	return 0;
}
 
