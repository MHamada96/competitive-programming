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

int n,k;
char line[1 << 20];
int ctrA[1 << 20],ctrB[1 << 20];

int f(int l){
	loop(i,n - l + 1){
		int v = ctrA[i + l - 1] - (i ? ctrA[i - 1] : 0);
		if(v <= k) return 1;
		v = ctrB[i + l - 1] - (i ? ctrB[i - 1] : 0);
		if(v <= k) return 1;
	}
	return 0;
}

int main(){
	scanf("%d %d %s",&n,&k,line);
	loop(i,n){
		ctrA[i] = line[i] == 'a';
		ctrB[i] = line[i] == 'b';
		if(i) ctrA[i] += ctrA[i - 1];
		if(i) ctrB[i] += ctrB[i - 1];
	}
	int s = 0,e = n;
	while(s < e){
		int m = s + (e - s + 1)/2;
		if(f(m)) s = m;
		else e = m - 1;
	}
	cout << s << endl;
	return 0;
}
