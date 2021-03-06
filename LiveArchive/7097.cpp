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

int steps[10];

int FindSpiral(int index, int x, int y)
{
	if(y > x) {
		printf("%d 2 %d %d\n", index, x, y);
		steps[0] = 2;
		steps[1] = x;
		steps[2] = y;
	} else if (y >= 4) {
		printf("%d 6 1 2 3 %d %d %d\n", index, x + 5 - y, x+2, x+3);
		steps[0] = 6;
		steps[1] = 1;
		steps[2] = 2;
		steps[3] = 3;
		steps[4] = x + 5 - y;
		steps[5] = x+2;
		steps[6] = x+3;
	} else {
		printf("%d NO PATH\n", index);
		steps[0] = 0;
	}
	return steps[0];
}

int main(){
	int T,K; point p;
	cin >> T;
	while(T--){
		cin >> K >> p.first >> p.second;
		FindSpiral(K,p.first,p.second);
	}	
	return 0;
}
