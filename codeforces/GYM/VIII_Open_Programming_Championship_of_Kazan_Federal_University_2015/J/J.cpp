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

int P[1 << 20],V[1 << 20],L[1 << 20];
int D[10];
int main(){
	int n,A;
	scanf("%d",&n);
	loop(i,n) scanf("%d",D + i);
	scanf("%d",&A);
	sort(D,D + n);
	queue<int> q;
	q.push(0); P[0] = -1;
	while(!q.empty()){
		int u = q.front(); q.pop();
		loop(i,n){
			int v = (u * 10 + D[i])%A;
			if(V[v] || (D[i] == 0 && u == 0)) continue;			
			V[v] = 1; 
			P[v] = u;
			L[v] = D[i];
			if(v == 0) break;
			q.push(v);
		}
	}
	if(P[0] == -1){
		puts("-1");
		return 0;
	}
	int u = 0,c = 1,idx = 0;
	char out[1 << 20];
	while(u != 0 || c){
		c = 0;
		out[idx++] = L[u] + '0';
		u = P[u];
	}
	reverse(out,out + idx);
	out[idx] = '\0';	
	puts(out);
	return 0;
}
