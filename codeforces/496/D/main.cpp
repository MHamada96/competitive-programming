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

const int MAX = 1e5 + 1e2;
int A[MAX],CTR[3][MAX],n;
int vis[MAX];
int IDX[3][MAX];

bool can1(int k,int & s){
	int win[2] = {0},ctr1 = 0,ctr2 = 0;
	loop(i,n){
		if(A[i] == 1) ctr1++;
		else ctr2++;
		if(ctr1 == k || ctr2 == k){
			win[ctr2 == k]++;
			ctr1 = ctr2 = 0;
		}
	}
	s = max(win[0],win[1]);
	int q = (win[1] > win[0]) + 1;
	return win[0] != win[1] && !ctr1 && !ctr2 && (A[n-1] == q);
}

void get(int & p,int pos,int idx,int k){
	int target = CTR[idx][pos] + k;
	if(A[pos] == idx) target--;
	if(target > CTR[idx][n - 1]) p = n;
	else p = IDX[idx][target];
}
vi DB;

bool can2(int k,int & s){
	int win[2] = {0};
	int pos = 0,ctr = 0;
	while(pos < n){
		ctr++;
		int p,q ;
		get(p,pos,1,k); 
		get(q,pos,2,k);
		if(p == n && q == n) return 0;
		win[min(p,q) == q]++;
		pos = min(p,q) + 1;		
	}
	//cerr << k << " " << ctr << endl;
	s = max(win[0],win[1]);
	int q = (win[1] > win[0]) + 1;
	return win[0] != win[1] && (q == A[n - 1]);
}		

bool can(int k,int & s){	
	if(vis[k]) return 0;
	vis[k] = 1;
	if(k*1LL*k < n) return can1(k,s);
	return can2(k,s);
}


int main(){
	memset(IDX,-1,sizeof IDX);
	scanf("%d",&n);
	loop(i,n){
		scanf("%d",A + i);
		if(i) {loop(j,3) CTR[j][i] = CTR[j][i - 1];}
		CTR[A[i]][i]++;
		IDX[A[i]][CTR[A[i]][i]] = i;
	}
	vp sol;
	for(int k = 1;k <= n;k++){
		int s;
		if(can(k,s)) sol.pb(mp(s,k));
	}
	printf("%d\n",sz(sol));
	sort(all(sol));
	for(auto p : sol) printf("%d %d\n",p.xx,p.yy);
	print(DB,int);
	return 0;
}
