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

char buffer[20];

int main(){
	int n,ctr = 0; scanf("%d",&n);
	string home ; cin >> home;
	loop(i,n){
		scanf("%s",buffer);
		string u ,v;
		for(char *token = strtok(buffer,"-> "); token ;token = strtok(0,"-> ")){
			if(u.empty()) u = string(token);
			else v = string(token);
		}
		if(u == home) ctr++;
		if(v == home) ctr--;

	}
	assert(ctr == 0 || ctr == 1);
	puts(ctr ? "contest" : "home");
	
	return 0;
}
