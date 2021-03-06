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

const int MAX = 300000 + 1e3;
const int mod = 1e9 + 9;
int F1[MAX],F2[MAX],A[MAX];
int ST[MAX << 2],LAZY[MAX << 2][2];
int n0 = 276601605,n1 = 691504013,n2 = 308495997;
int RRR;
#define add(a,b) (RRR = a + b,RRR += (RRR < 0) ? mod : 0,RRR -= (RRR >= mod) ? mod : 0)
#define mul(a,b) (((a*1LL*b)%mod + mod)%mod)
#define get_new_offset(offset,s,s2,F) mul(offset,F[s2 - s])

inline void update(int node,int s,int e,int offset1,int offset2){
	int tmp1 = add(F1[e - s + 1],-1); tmp1 = mul(tmp1,n1);  tmp1 = mul(tmp1,offset1);
	int tmp2 = add(F2[e - s + 1],-1); tmp2 = mul(tmp2,n2);  tmp2 = mul(tmp2,offset2);
	int tmp = add(tmp1,-tmp2);
	ST[node] = add(ST[node],tmp);
	LAZY[node][0] = add(LAZY[node][0],offset1);
	LAZY[node][1] = add(LAZY[node][1],offset2);
}

inline void advance(int node,int s,int e){
	if(s == e) return;
	int m = (s + e) >> 1,left = node << 1,right = left | 1;
	update(left,s,m,LAZY[node][0],LAZY[node][1]);
	update(right,m + 1,e,mul(LAZY[node][0],F1[m + 1 - s]),mul(LAZY[node][1],F2[m + 1 - s]));
	LAZY[node][0] = LAZY[node][1] = 0;
}

inline void update(int node,int s,int e,int l,int r,int offset1,int offset2){
	if(l <= s && e <= r) return update(node,s,e,offset1,offset2);
	advance(node,s,e);
	int m = (s + e) >> 1,left = node << 1,right = left | 1;
	if(r <= m) update(left,s,m,l,r,offset1,offset2);
	else if(m < l) update(right,m + 1,e,l,r,offset1,offset2);
	else{
		update(left,s,m,l,m,offset1,offset2);
		update(right,m + 1,e,m + 1,r,mul(offset1,F1[m + 1 - l]),mul(offset2,F2[m + 1 - l]));
	}
	ST[node] = add(ST[left] , ST[right]);
}

struct vertex{
	int node,s,e,l,r;
public:
	vertex(){}
	vertex(int a,int b,int c,int d,int e):node(a),s(b),e(c),l(d),r(e){}
};

int query(int node,int s,int e,int l,int r){
	int ans = 0;
	queue<vertex> q; q.push(vertex(node,s,e,l,r));
	while(!q.empty()){
		node = q.front().node,s = q.front().s,e = q.front().e;
		l = q.front().l,r = q.front().r;
		q.pop();
		if(l <= s && e <= r) {
			ans = add(ans, ST[node]);
			continue;
		}
		advance(node,s,e);
		int m = (s + e) >> 1,left = node << 1,right = left | 1;
		if(r <= m) { 
			q.push(vertex(left,s,m,l,r));
			continue;
		}
		else if(m < l) {
			q.push(vertex(right,m + 1,e,l,r));
		}
		else {
			q.push(vertex(left,s,m,l,m));
			q.push(vertex(right,m + 1,e,m + 1,r));	
		}
	}
	return ans;
}


int main(){
	int n,m,a,b,c;
	scanf("%d %d",&n,&m);
	F1[0] = F2[0] = 1;
	loop(i,n + 5) {
		F1[i + 1] = mul(F1[i],n1);
		F2[i + 1] = mul(F2[i],n2); 
	}	
	loop(i,n) {
		scanf("%d",A + i + 1);
		A[i + 1] = add(A[i + 1],A[i]);
	}
	while(m--){
		scanf("%d %d %d",&c,&a,&b);
		if(c == 1) update(1,1,n,a,b,n1,n2);
		else{
			int ans = add(A[b] ,-A[a - 1]);
			ans = add(ans,mul(n0,query(1,1,n,a,b)));
			printf("%d\n",ans);
		}
	}
	return 0;
}
