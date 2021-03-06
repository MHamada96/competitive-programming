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

const int MAX = 3e5 + 1e2;
const ll oo = 1LL << 60,inf = 1e9 + 7;
map<int,int> R[MAX],O[MAX];

int A[MAX],n,d;

bool exist(int key,map<int,int> & M){
	return M.find(key) != M.end();
}

void merge(deque<int> & A,deque<int> & B,vp & seq,int a,int b){
	reverse(all(A));
	reverse(all(B));
	while(!A.empty() && !B.empty()){
		if(A.back() < B.back()){
			seq.pb(mp(a,b));
			A.pop_back();
		}
		else{
			seq.pb(mp(b,a));
			B.pop_back();
		}
	}
	for(;!A.empty();A.pop_back()) seq.pb(mp(a,b));
	for(;!B.empty();B.pop_back()) seq.pb(mp(b,a));
}

ll work(int a,int b,ll cost,vp & seq){
	deque<int> A,B;
	ll ret = 0;	
	loop(i,sz(seq)){
		if(seq[i].xx == a) A.pb(i);
		else{
			if(A.empty()) B.pb(i);
			else {
				A.pop_front();
				ret += cost;
			}
		}
	}
	seq.clear();
	merge(A,B,seq,a,b);
	//cerr << "after forking " << a << " -> " << b << " -> " << a << " : ";
	//for(auto p : seq) {prp(p);}
	//cerr << endl;
	//cerr << "returning " << ret << endl; 
	return ret;
}

ll solve(vp & seq){
	int a = seq[0].xx,b = seq[0].yy;
	ll Ra = exist(b,R[a]) ? R[a][b] : (3*inf),Rb = exist(a,R[b]) ? R[b][a] : (3*inf);
	ll Da = exist(b,O[a]) ? O[a][b] : inf,Db = exist(a,O[b]) ? O[b][a] : inf;
	Da = min(Da,Ra); Db = min(Db,Rb);	
	//for(auto p : seq) prp(p);
	//cerr << endl;	
	if(Ra > Rb) swap(a,b),swap(Ra,Rb),swap(Da,Db);
	ll ret = 0;
	if(Ra <= Da + Db) ret += work(a,b,Ra,seq);
	if(Rb <= Da + Db) ret += work(b,a,Rb,seq);
	int x = 0,y = 0;
	for(auto p : seq) x += p.xx == a,y += p.xx == b;
	ret += x * Da + y * Db;	
	//cerr << ret << endl;
	//cerr << "===================================" << endl;
	return ret;
}

ll solve(){
	vector<pair<pi,pi> > V(d-1); int idx = 0;
	loop(i,d-1) {
		int a = A[i],b = A[i + 1],c = 0;
		if(a > b) swap(a,b),c = 1;	
		V[i] = mp(mp(a,b),mp(c,i));
	}
	sort(all(V));
	d--;
	ll ans = 0;
	loop(i,d){
		int j = i;
		vector<pair<int,pi> > Q;
		while(j < d && V[i].xx == V[j].xx) {
			int a = V[j].xx.xx,b = V[j].xx.yy;
			if(V[j].yy.xx) swap(a,b);
			Q.pb(mp(V[j].yy.yy,mp(a,b)));
			j++;
		}
		sort(all(Q));
		vp T;
		for(auto p : Q) T.pb(p.yy);
		ans += solve(T);
		i = j - 1;
	}	
	return ans;
}


int main(){
	scanf("%d %d",&n,&d);
	loop(i,d) scanf("%d",A + i);
	int m; scanf("%d",&m);
	loop(i,m){
		int a,b,c; char type;
		scanf("%d %d %c %d",&a,&b,&type,&c);
		if(type == 'R') {
			if(!exist(b,R[a])) R[a][b] = c;
			R[a][b] = min(R[a][b],c);
		}
		else{
			if(!exist(b,O[a])) O[a][b] = c;
			O[a][b] = min(O[a][b],c); 
		}
	}
	
	cout << solve() << endl;
	return 0;
}
