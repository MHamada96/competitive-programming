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

int main(){
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1 == x2) {
		int len = abs(y1 - y2);
		cout << x1 + len << " " << y1 << " " << x2 + len << " " << y2 << endl;
	}
	else if(y1 == y2) {
		int len = abs(x1 - x2);
		cout << x1 << " " << y1 + len << " " << x2 << " " << y2 + len << endl;
	}
	else if(abs(x1 - x2) != abs(y1 - y2)) cout << -1 << endl;
	else{
		cout << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
	}		
	return 0;
}
