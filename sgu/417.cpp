#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
#define step(i,a,b,d) for(int i = (a);i <= (b); i += d)
#define all(A) A.begin(),A.end()
#define pb push_back
#define mp make_pair
#define sz(A) A.size()
#define len(A) A.length()
#define print(A,t) cout << #A << ": "; copy(all(A),ostream_iterator<t>(cout," " )); cout << endl
#define pi pair<int,int>
#define point pi
#define vi vector<int>
#define ll long long
#define pl pair<ll,ll>
#define pre() cin.tie(0),cout.tie(0),ios_base::sync_with_stdio(0)
#define popcnt(x) __builtin_popcount(x)
using namespace std;

double adaptiveSimpsonsAux(double(*f)(const double&), double a,double b,double epsilon, double S, double fa, double fb, double fc, int bottom) {
	double c = (a + b) / 2, h = b - a;
	double d = (a + c) / 2, e = (c + b) / 2;
	double fd = f(d), fe = f(e);
	double Sleft = (h / 12) * (fa + 4 * fd + fc);
	double Sright = (h / 12) * (fc + 4 * fe + fb);
	double S2 = Sleft + Sright;
	if (bottom <= 0 || fabs(S2 - S) <= 15 * epsilon)
		return S2 + (S2 - S) / 15;
	return adaptiveSimpsonsAux(f, a, c, epsilon / 2, Sleft, fa,fc, fd,bottom - 1) + adaptiveSimpsonsAux(f, c, b,epsilon / 2, Sright, fc,fb, fe, bottom - 1);
}

double adaptiveSimpsons(double(*f)(const double&), double a, double b, double epsilon,int maxRecursionDepth) {
	double c = (a + b) / 2, h = b - a;
	double fa = f(a), fb = f(b), fc = f(c);
	double S = (h / 6) * (fa + 4 * fc + fb);
	return adaptiveSimpsonsAux(f, a, b, epsilon, S, fa, fb, fc,maxRecursionDepth);
}

double X0,Y0,R,b;


/*double g(const double & t){
	double a = 2*cos(t)*X0 + 2*sin(t)*Y0;
	return sqrt(4*b - a*a) * atan2(a + 2*R,sqrt(4*b - a*a)) + (a/2 + R)*log(R*(a + R) + b) - 2*R;
}*/
double g(const double & t){
	double a = 2*cos(t)*X0 + 2*sin(t)*Y0;
	double s = sqrt(4*b - a*a);
	double d = 2*(b + R*R) - a*a;
	double y = log(R*R + a*R + b);
	return (s*(d*y + 2*R*(a-R)) + 2*a*(a*a-4*b)*atan2(a+2*R,s))/4.0/s;
}


double I(){
	return adaptiveSimpsons(g,0,2*acos(-1),1e-15,15);
}

int main(){
	while(cin >> X0 >> Y0 >> R){
		b = X0*X0 + Y0*Y0;
		double ans = I();	
		R = 0;
		ans -= I();
		if(ans < 0) ans = 0;
		printf("%.15lf\n",ans);
	}	
	return 0;
}