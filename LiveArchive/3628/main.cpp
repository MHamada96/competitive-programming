#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0,_ = (n);i < _;i++)
#define range(i,a,b) for(int i = (a),_ = (b);i <= _;i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b),_ = (a);i >= _;i--)
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

#define MAXN (1 << 20)
struct cmp{
	int *R,k,n;
public:
	cmp(){}
	cmp(int a,int *b,int c):k(a),R(b),n(c){}
	bool operator () (const int & a,const int & b){
		if(k == 0) return R[a] < R[b];
		if(R[a] != R[b]) return R[a] < R[b];
		int u = min(a + k,n - 1),v = min(b + k,n - 1);
		return R[u] < R[v];
	}
};

void build(char *P,int *SA,int *R){
	int n = strlen(P);
	P[n++] = '$'; P[n] = 0;
	static int nR[MAXN];
	loop(i,n) R[i] = P[i],SA[i] = i;
	sort(SA,SA + n,cmp(0,R,n));
	for(int k = 1;k <= n;k <<= 1){
		sort(SA,SA + n,cmp(k,R,n));
		int r = 0;
		nR[SA[0]] = r;
		auto comparator = cmp(k,R,n);
		loop(i,n - 1){
			if(comparator(SA[i],SA[i + 1]) || comparator(SA[i + 1],SA[i])) r++;
			nR[SA[i + 1]] = r;  
		}
		copy(nR,nR + n,R);
	}
	//loop(i,n) cerr << R[SA[i]] << " " << (P + SA[i]) << endl;
	//cerr << endl;	
}

void computeLCP(char *T,int n,int *SA,int *LCP) {
	int i, L;
	static int Phi[MAXN],PLCP[MAXN];
	Phi[SA[0]] = -1;
	for (i = 1; i < n; i++)
		Phi[SA[i]] = SA[i-1];
	for (i = L = 0; i < n; i++) {
		if (Phi[i] == -1) { PLCP[i] = 0; continue; }
		while (i + L < n && Phi[i] + L < n && T[i + L] == T[Phi[i] + L]) L++;
		PLCP[i] = L;
		L = max(L-1, 0);
	}
	for (i = 0; i < n; i++) LCP[i] = PLCP[SA[i]];
}

char S[1 << 20];
int SA[1 << 20],R[1 << 20],CS,LCP[1 << 20];
int T;
int CTR[10],ctr;
int who[MAXN];

void insert(int p,deque<int> & dq){
	CTR[who[SA[p]]]++;
	while(!dq.empty() && LCP[dq.back()] >= LCP[p]) dq.pop_back();
	dq.pb(p);
}


int get(int & j,deque<int> & dq){
	int r = 0;	
	for(;!dq.empty();j++){
		CTR[who[SA[j]]]--;
		if(dq.front() == j) dq.pop_front();
		if(CTR[who[SA[j]]] == 0) {
			r = LCP[dq.front()];
			break;
		}
	}
	return r;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&CS); int n = 0;
		loop(i,CS){
			scanf("%s",S + n);
			for(;S[n];n++) who[n] = i;
			who[n] = -1;
			S[n++] = '&' + i + 1;
		}
		S[--n] = 0;
		//cerr << S << endl << "#######################" << endl;
		build(S,SA,R);
		computeLCP(S,++n,SA,LCP);
		//loop(i,n) cerr << LCP[i] << " " << (SA[i] + S) << endl;
		fill(CTR,CTR + 10,0); ctr = 0;	
		deque<int> MQ;
		int p = 0,mx = 0,j = 0;
		loop(i,n){
			if(who[SA[i]] == -1) MQ.clear(),j = i + 1;
			else {
				if(!CTR[who[SA[i]]]) ++ ctr;
				insert(i,MQ);
				if(ctr == CS){
				//	cerr << j << " " << i << " -> " ;
					int tmp = get(j,MQ);
				//	cerr << tmp << endl;
					if(tmp > mx){
						mx = tmp;
						p = SA[i];
					}
					if(j == MQ.front()) MQ.pop_front();
					++j;
					--ctr;
				}
			}
		}
		if(mx < 3) puts("no significant commonalities");
		else{
			loop(i,mx) putchar(S[p + i]);
			puts("");
		}
	}
	return 0;
}
