#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long long>
#define vd vector<double>
#define vp vector<pair<int,int> >
#define ll long long
#define pi pair<int,int>
#define pl pair<ll,ll>
#define popcnt(x) __builtin_popcountll(x)
#define LSOne(x) ((x) & (-(x)))
#define xx first
#define yy second
#define PQ priority_queue
#define print(A,t) cerr << #A << ": "; copy(all(A),ostream_iterator<t>(cerr," " )); cerr << endl
#define prp(p) cerr << "(" << (p).first << " ," << (p).second << ")";
#define prArr(A,n,t)  cerr << #A << ": "; copy(A,A + n,ostream_iterator<t>(cerr," " )); cerr << endl
#define PRESTDIO() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
#define what_is(x) cerr << #x << " is " << x << endl
#define bit_lg(x) (assert(x > 0),__builtin_ffsll(x) - 1)
const double PI = acos(-1);
using namespace std;

int A[1 << 10],B[1 << 10],P[ 1 << 10],n;
int vis[1 << 10];
bool is_permutation(){
	memset(vis,0,sizeof vis);
	loop(i,n) {
		if(P[i] < 1 || P[i] > n || vis[P[i]]) return 0;
		vis[P[i]] = 1;
	}
	return 1;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("in.in", "r", stdin);
	#endif
	scanf("%d",&n);
	loop(i,n) scanf("%d",A + i);
	loop(i,n) scanf("%d",B + i);
	loop(i,n) {
		copy(A,A + n,P);
		int ctr = 0;
		int S = n*(n + 1)/2;
		loop(j,n) if(i != j) ctr += P[j] != B[j],S -= P[j];
		if(ctr == 0){
			P[i] = S;
			if(is_permutation()) break;
		}
		if(ctr == 1){
			P[i] = B[i];
			if(is_permutation()) break;
		}
	}
	loop(i,n) printf("%d%c",P[i]," \n"[i==n-1]);
	return 0;
}
