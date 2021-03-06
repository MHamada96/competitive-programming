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

const int MAX = 4e5;
map<pi,int> M;
int n,m,a,b,K,P[MAX],W[MAX];
char s[3];


int find(int a){
	while(a != P[a]) a = P[a];
	return a;
}

int find(int a,int & pre){
	pre = -1;
	while(a != P[a]){
		pre = a;
		a = P[a];
	}
	return a;
}


bool get(int a,int b,pi & e){
	if(b == -1) return 0;
	if(M.find(mp(a,b)) != M.end()) {
		e = mp(a,b);
		return 1;
	}
	if(M.find(mp(b,a)) != M.end()) {
		e = mp(b,a);
		return 1;
	}
	return 0;
}

void join(int a,int b){
	int pra,prb;
	a = find(a,pra),b = find(b,prb);
	if(a == b){
		pi e;
		if(get(a,prb,e));
		else if(get(a,pra,e));
		else get(a,b,e);
		M[e]++;
		return;
	}
	if(W[a] < W[b]) swap(a,b);
	W[a] += W[b];
	P[b] = a;
	M[mp(a,b)] = 1;
	K--;
}

void disjoin(int a,int b){
	int pra,prb;
	a = find(a,pra),b = find(b,prb);
	pi e;
	if(get(a,prb,e));
	else if(get(a,pra,e));
	else get(a,b,e);
	if(W[a] < W[b]) swap(a,b);	
	M[e]--;
	if(M[e] == 0){
		W[a] -= W[b];
		P[b] = b;
		M.erase(e);
		K++;
	}
}

int main(){
	scanf("%d %d",&n,&m); K = n;
	loop(i,n) W[i] = 1,P[i] = i;
	loop(i,m){
		scanf("%s",s);
		if(strcmp(s,"?") == 0){
			printf("%d\n",K);
		}
		else {
			scanf("%d %d",&a,&b); a--,b--;
			if(strcmp(s,"+") == 0){
				join(a,b);
			}
			else{
				disjoin(a,b);
			}
		}
	}	
	return 0;
}
