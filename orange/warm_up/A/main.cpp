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

string A[3];

int main(){
	cin >> A[0];
	cin >> A[1]; cin >> A[1];
	cin >> A[2]; cin >> A[2];
	if(A[1][0] == 'x') swap(A[0],A[1]);
	if(A[0][0] == 'x'){
		int a,b;
		sscanf(A[1].c_str(),"%d",&a);
		sscanf(A[2].c_str(),"%d",&b);
		printf("%d\n",b - a);
	}
	else{
		int a,b;
		sscanf(A[0].c_str(),"%d",&a);
		sscanf(A[1].c_str(),"%d",&b);
		printf("%d\n",b + a);
	}
	return 0;
}
