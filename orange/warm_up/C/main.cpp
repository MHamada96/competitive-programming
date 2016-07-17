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

const int MAX = 1000000;
int A[MAX],n,k;

int main(){
	scanf("%d %d",&n,&k);
	loop(i,n) scanf("%d",A + i);
	deque<int> dq;	
	loop(i,k){
		while(!dq.empty() && A[dq.back()] <= A[i]) dq.pop_back();
		dq.push_back(i);
	}
	printf("%d",A[dq.front()]);
	loop(i,n - k){
		if(dq.front() == i) dq.pop_front();
		while(!dq.empty() && A[dq.back()] <= A[i + k]) dq.pop_back();
		dq.push_back(i + k);		
		printf(" %d",A[dq.front()]);	
	}
	puts("");
	return 0;
}
