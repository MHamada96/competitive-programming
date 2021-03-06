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

const int MAX = 1e6;
int prime_factor[MAX];

void sieve(){
	loop(i,MAX) prime_factor[i] = i;
	prime_factor[0] = 1;
	prime_factor[1] = 0;
	for(ll i = 2;i < MAX;i++)
		if(prime_factor[i] == i)
			for(ll j = i*i;j < MAX;j += i)
				prime_factor[j] = i;
}

int main(){
	sieve();
	vi V;
	int ctr = 0;
	for(int i = 1;i < MAX;i++){
		int a = 0,b = 0,ac = 0,bc = 0;
		for(int j = i;j > 1;j /= prime_factor[j]) {
			if(a){
				if(a == prime_factor[j]) ac++;
				else if(b){
					if(b == prime_factor[j]) bc++;
					else {
						ac = bc = 1;
						break;
					}
				}
				else b = prime_factor[j],bc = 2;
			}
			else a = prime_factor[j],ac = 2;
		}
		if(b == 0){
			bc = prime_factor[ac];
			ac /= bc;
		}
		if(ac == prime_factor[ac] && bc == prime_factor[bc] && ac != bc){
			++ctr;
			if(ctr == 9) 
			 printf("%d\n",i);
			if(ctr == 9) ctr = 0;
		}
	}
}

