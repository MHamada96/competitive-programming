#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	if(n == 0) cout << 0 << endl;
	else if (n == 1) cout << 1 << endl;
	else{
		long long ans = 1,dist = 1,deg = 2;
		for(int i = 2;i <= n;i++){
			if(i & 1) deg ++;
			else dist ++;
			ans += dist * deg;
		}
		printf("%.3lf\n",(double)ans);
	}
	return 0;
}