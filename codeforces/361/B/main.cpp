#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long>
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

int ans[1 << 20];
int A[1 << 20],n;

void insert(int a,int d,queue<int> & q){
	if(ans[a] != -1) return;
	ans[a] = d;
	q.push(a);
}

int main(){
	scanf("%d",&n);
	loop(i,n) scanf("%d",A + i + 1);
	memset(ans,-1,sizeof ans);
	ans[1] = 0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front(); q.pop();
		insert(u + 1,ans[u] + 1,q);
		insert(u - 1,ans[u] + 1,q);
		insert(A[u],ans[u] + 1,q);
	}
	loop(i,n) printf("%d%c",ans[i + 1]," \n"[i == n - 1]);
	return 0;
}
