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

int n;
char num[10];

bool get_diff(int a,int b,int oa,int & nb){
	a = a ? (a - 1) : 10;
	b = b ? (b - 1) : 10;
	oa = oa ? (oa - 1) : 10;
	int dx = b/3 - a/3;
	int dy = b%3 - a%3;
	int x = oa/3 + dx,y = oa%3 + dy;
	if(x < 0 || x > 3 || y < 0 || y >= 3) return 0;
	nb = x*3 + y;
	if(nb == 9 || nb > 10) return 0;
	if(nb == 10) nb = 0;
	else nb ++;
	return 1;
}

bool CAN(int v){
	int u = num[0] - '0',q;
	range(i,1,n - 1){
		if(!get_diff(u,num[i] - '0',v,q)) return 0;
		v = q;
		u = num[i] - '0';
//		cerr << v << " ";
	}
	return 1;
}

int main(){
	cin >> n >> num;
	bool c = 0;	
	loop(s,10) if(s != num[0] - '0'){
		bool t = CAN(s);
	//	cerr << t << " " << s << endl;
		c |= t;
	}
	puts(c ? "NO" : "YES");
	return 0;
}
