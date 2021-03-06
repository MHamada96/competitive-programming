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

int n,m,k;
int id[2000],W[2000],sum;
const int mod = 1e9 + 7;

int get(int p){
	return (id[p] == p) ? p : get(id[p]);
}

void join(int a,int b){
	a = get(a),b = get(b);
	if(a == b) return;
	if(W[a] < W[b]) swap(a,b);
	W[a] += W[b];
	id[b] = a;
	sum--;
}

int main(){
	cin >> n >> m >> k;
	loop(i,n) W[i] = 1,id[i] = i;
	sum = n;
	loop(i,n - k + 1){
		for(int j = i,l = i + k - 1;j < l;j++,l--)
			join(j,l);
	}

	int t = 1;
	for(;sum > 1;sum >>= 1){
		if(sum & 1) t = (t*1LL*m)%mod;
		m = (m*1LL*m)%mod;
	}
	m = (m*1LL*t)%mod;
	cout << m << endl;
	return 0;
}
