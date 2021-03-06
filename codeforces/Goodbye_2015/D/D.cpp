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
#define pi mypair<int>
#define point mypair<double>
#define pl mypair<ll>
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

template <class T>
struct mypair{
	T x,y;
public:
	mypair():x(0),y(0){}
	mypair(T x,T y):x(x),y(y){}
	bool operator < (const mypair<T> & o) const {
		return (x == o.x) ? (y < o.y) : (x < o.x);
	}
	bool operator > (const mypair<T> & o) const {
		return o < *this;
	}
	bool operator != (const mypair<T> & o) const {
		return (*this < o) || (o < *this);
	}
	bool operator == (const mypair<T> & o) const {
		return !(*this != o);
	}
	mypair<T> operator + (const mypair<T> & o){
		return mypair<T>(x + o.x,y + o.y);
	}
	mypair<T> operator * (const ll & n) const {
		return mypair<T>(n*x,n*y);
	}
	mypair<T> operator / (const ll & n) const {
		return mypair<T>(x/n,y/n);
	}
	mypair<T> operator - (const mypair<T> & o) const {
		return *this + (-1LL)*o;
	}
	ll operator * (const mypair<T> & o) const {
		return x*1LL*o.x + y*1LL*o.y;
	}
	ll cross(const mypair<T> & o){
		return x*1LL*o.y - y*1LL*o.x;
	}
	mypair<T> conj(){
		return mypair<T>(x,-y);
	}
	mypair<T> operator / (const mypair<T> & o) const {
		return (*this * o.conj())/hypot(o.x,o.y);
	}
	double angle(){
		double t = atan2(y,x);
		if(t < 0) t += PI;
		return t;	
	}
	friend ostream & operator << (ostream & stream,const mypair<T> & p)  {
		stream << "(" << p.x << " ," << p.y << ")";
		return stream;
	}
	friend istream & operator >> (istream & stream,mypair<T> & p){
		stream >> p.x >> p.y;
		return stream;
	}
	friend void swap(mypair<T> & u,mypair<T> & v){
		using std::swap;		
		u.x ^= v.x ^= u.x ^= v.x;
		u.y ^= v.y ^= u.y ^= v.y;
	}
};

const int MAX = 5001;
char line[MAX];
;int L;
ll F[MAX][MAX];
ll G[MAX][MAX];
int Z[20][MAX];
const ll mod = 1e9 + 7;

int ord[MAX];
int h;

int cmp(const int & a,const int & b){
	if(Z[h][a] != Z[h][b]) return Z[h][a] < Z[h][b];
	//cerr << a + (1 << h) << " "  << b + (1 << h) << " " << L << endl;
	return Z[h][a + (1 << h)] < Z[h][b + (1 << h)];
}

int f(int a,int b,int c,int d){
	if(b < a || d < c) return 0;
	if(b - a > d - c) return 1;
	if(b - a < d - c) return 0;
	if(b - a + 1 == 1) return line[a] < line[c];	
	int l = b - a + 1,lg = 0;
	while((1 << lg) <= l) lg++; lg--;
	if(Z[lg][a] != Z[lg][c]) return Z[lg][a] < Z[lg][c];
	return f(a + (1 << lg),b,c + (1 << lg),d);
}

int main(){
	scanf("%d %s",&L,line);
	line[L] = '0'-1;
	line[L + 1] = '\0';
	loop(i,L + 1) Z[0][i] = line[i];
	for(h = 0;h < 19;h++){
		if((1 << h) > L) break;
		loop(i,L + 1) ord[i] = i;
 		sort(ord,ord + L + 1,&cmp);
		//prArr(ord,L + 1,int);
		//cerr << cmp(ord[0],ord[0]) << " " <<  cmp(ord[0],ord[0]) << endl;
		loop(i,L + 1) {
			int j = i;
			while(j < L + 1 && cmp(ord[i],ord[j]) == 0 && cmp(ord[j],ord[i]) == 0){
		//		cerr << line + ord[j] << endl;
				Z[h + 1][ord[j]] = i;
				j++;				
			}
			i = j - 1;
		}
	//	cerr << endl;
	}
	range(j,0,L - 1){
		range(i,0,j){
			int i1 = -110000;
			if(i == 0) F[i][j] = G[i][j] = 1;
			else if(line[i] == '0') F[i][j] = 0,G[i][j] = G[i - 1][j];
			else{
				i1 = i - (j - i + 1);
		//		if(i == 2 && j == 3){
		//			cerr << "============ " << i1 << " " << i - 1 << " " << f(i1,i - 1,i,j) << endl;
		//		}
				if(i1 >= 0 && f(i1,i - 1,i,j)) 	F[i][j] = F[i1][i-1];
				F[i][j] += G[i - 1][i - 1];
				if(i1 >= 0) F[i][j] -= G[i1][i - 1];
				while(F[i][j] < 0) F[i][j] += mod;
				while(F[i][j] >= mod) F[i][j] -= mod;
				G[i][j] = F[i][j];
				G[i][j] += G[i - 1][j];		
				G[i][j] = (G[i][j] % mod + mod)%mod;		
			}
		//	cerr << i << " " << j << " " << F[i][j] << " " << G[i][j] << endl;
		}
	}	
	
	cout << G[L-1][L-1] << endl;
	return 0;
}
