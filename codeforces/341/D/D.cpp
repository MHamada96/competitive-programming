#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define step(i,a,b,d) for(int i = (a);i <= (b); i += d)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define len(A) A.length()
#define vi vector<int>
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
#define pre() cin.tie(0),cerr.tie(0),ios_base::sync_with_stdio(0)
using namespace std;

char out[12][12] = {"x^y^z",
			"x^z^y",
			"(x^y)^z",
			"(x^z)^y",
			"y^x^z",
			"y^z^x",
			"(y^x)^z",
			"(y^z)^x",
			"z^x^y",
			"z^y^x",
			"(z^x)^y",
			"(z^y)^x"};

struct value{
	double a,b;
public:
	value(){}
	value(double a,double b):a(a),b(log(b)){}
	bool operator < (const value & v2) const {
		const value & v1 = *this;
		if(abs(v1.b) < 1e-9) return v2.b > 0 && abs(v2.b) > 1e-9;
		double b1 = v1.b,b2 = v2.b;
		if(b1 < 0) {
			b1 *= -1,b2 *= -1;
			if(b2 < 0) return 1;
			double x = v1.a - v2.a , y = log(b2) - log(b1);
			return x > y && abs(x - y);	
		}			
		if(b2 < 0) return 0;
		double x = v1.a - v2.a , y = log(b2) - log(b1);
		return x < y && abs(x - y);	
	}
};
pair<value,int> V[12];

int main(){
	double x,y,z;
	cin >> x >> y >> z;
	V[0].xx = value(z*log(y),x);
	V[1].xx = value(y*log(z),x);
	V[2].xx = value(log(y*z),x);
	V[3].xx = value(log(y*z),x);
	V[4].xx = value(z*log(x),y);
	V[5].xx = value(x*log(z),y);
	V[6].xx = value(log(x*z),y);
	V[7].xx = value(log(x*z),y);
	V[8].xx = value(y*log(x),z);
	V[9].xx = value(x*log(y),z);
	V[10].xx =value(log(x*y),z);
	V[11].xx =value(log(x*y),z);
	loop(i,12) V[i].yy = i;	
	sort(V,V + 12);
	int c = V[11].yy;
	loop(i,12){
		if(!(V[i].xx < V[11].xx) && !(V[11].xx < V[i].xx)){
			cerr << V[i].yy << " ----- " << endl;
			c = min(c,V[i].yy);
		}
	}
	//loop(i,12) cerr << V[i].xx.a << " " << V[i].xx.b  << " " << V[i].yy << endl;
	//cerr << c << endl;
	puts(out[c]);
	return 0;
}
