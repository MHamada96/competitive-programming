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


int start[12] = {};
int now[12] = {};
int nDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};


bool is_leap(int y){
	if(y%4) return 0;
	if(y%100) return 1;
	if(y%400) return 0;
	return 1;
}

void init(int y){
	loop(i,11) start[i + 1] = (start[i] + nDays[i] + (i == 1 && is_leap(y)))%7;
	copy(start,start + 12,now);
}

bool Equal(){
	loop(i,12) if(start[i] != now[i]) return 0;
	return 1;
}

int main(){
	int x,y = 1,shift = 0; cin >> x; 
	init(x);
	prArr(start,12,int);
	while(!Equal() || y == 1){
		now[0] = (now[11] + nDays[11])%7;
		loop(i,11) now[i + 1] = (now[i] + nDays[i] + (i == 1 && is_leap(x + y)))%7;		
		y++;
	}
	prArr(now,12,int);
	cout << x + y - 1 << endl;
	cerr << x + y - 1 << endl;
	return 0;
}
