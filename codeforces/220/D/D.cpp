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

const int MAX = 1 << 22;
int BIT[MAX + 1],n,m;
int A[1 << 22];
int V[1 << 22];
int IDX[1 << 22];

void update(int p,int v){
	for(;p <= MAX;p += LSOne(p)) BIT[p] += v; 
}

int get(int p){
	int r = 0;
	for(;p;p -= LSOne(p)) r += BIT[p];
	return r;
}

bool cmp(const int & a,const int & b){
	return get(a) < b;
}


int main(){
	loop(i,MAX - 1) update(i + 1,1),IDX[i + 1] = i + 1;
	int e = 1,ctr = 0,command;
	scanf("%d %d",&n,&m);
	loop(i,m) scanf("%d",A + i);
	
	loop(i,n){
		scanf("%d",&command);
		if(command != -1){
			V[e++] = command;
			ctr ++;
		}	
		else{
			auto p = upper_bound(A,A + m,ctr);
			if(p == A) continue;
			int idx = p - A - 1;
			while(idx >= 0){
				auto p = lower_bound(IDX + 1,IDX + MAX,A[idx],&cmp) - IDX;
				update(IDX[p],-1);
				idx--;
			}
			ctr -= p - A;
		}
	}
	if(ctr == 0){
		puts("Poor stack!");
		return 0;
	}
	int nxt = 1,i = 1;
	while(nxt <= ctr){
		if(get(i) == nxt){
			printf("%d",V[i]);
			nxt++;
		}
		i++;
	}
	puts("");
	return 0;
}
