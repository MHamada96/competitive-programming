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

const int MAX = 1900;
int n;
int g[MAX];

int gr(int n){
	for(ll i = 2;i*i <= n;i++)
		if(n%i == 0)
			return n/i;
	return 1;
}



int f(int n){
	if(n < MAX) return g[n];
	int ret = 1 << 29;
	for(int i = 0;i < MAX;i++){
		if(i == 1) continue;
		ret = min(ret,g[i] + gr(n - i));
	}	
	return ret;
}

int main(){
	g[0] = 0;
	g[1] = 1 << 29;	
	for(int i = 2;i < MAX;i++){
		g[i] = gr(i);
		for(int j = 2;j <= i - 2;j++)
			g[i] = min(g[i],g[j] + g[i - j]);
	}

	cin >> n; 
	cout << f(n) << endl;
	return 0;
}
