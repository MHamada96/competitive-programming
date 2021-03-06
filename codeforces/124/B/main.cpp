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

char I[8][10],buffer[10];
int to[8],n,k;

int f(){
	int mn = INT_MAX,mx = 0,x;
	loop(i,n) {
		loop(j,k) buffer[to[j]] = I[i][j];
		sscanf(buffer,"%d",&x);
		mn = min(mn,x);
		mx = max(mx,x);
	}
	return mx - mn;
}

int main(){
	scanf("%d %d",&n,&k);
	loop(i,n) scanf("%s",I[i]);
	loop(i,k) to[i] = i;
	int ans = INT_MAX;	
	do{
		ans = min(ans,f());
	}while(next_permutation(to,to + k));	
	cout << ans << endl;
	
	return 0;
}
