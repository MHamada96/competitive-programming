#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b,long long & x,long long &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	long long d = gcd(b,a%b,x,y);
	long long t = x;	
	x = -y;
	y = t + (a/b)*y; y = -y;
	return d;
}

int main(){
	long long x,y,a,b,n,m,d;
	int t;
	cin >> t;
	while(t--){
		cin >> a >> n >> b >> m;
		if(a > b){
			swap(a,b);
			swap(n,m);
		}
		d = __gcd(n,m);
		if((b - a)%d) puts("no solution");
		else{
			gcd(n,m,x,y);
			//cout << n * x - m*y << " " << d << endl;
			x *= (b - a)/d;
			y *= (b - a)/d;
			long long ans = x * n + a,l = n*m/d;
			ans = (ans%l + l)%l;
			printf("%lld %lld\n",ans,l);
		}	
	}
	return 0;
}
