#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define rrep(i,n) for(int i = (n);i >= 0;i--)
#define rran(i,a,b) for(int i = (b);i >= (a);i--)
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

char line[1 << 20];
int n;
vl op;
vector<pair<ll,int> > value;
int main(){
	fgets(line,1 << 20,stdin);
	n = strlen(line); line[--n] = 0;
	char deli [] = " ultiplyd",*token = strtok(line,deli);
	for(;token != NULL;token = strtok(NULL,deli)){
		if(token[0] == 'a') op.pb(0);
		else if(token[0] == 'm') op.pb(1);
		else if(token[0] == '(') value.pb(mp(0,1));		
		else if(token[0] == ')'){
			if(op.empty()) continue;
			ll tmp = op.back();
			while(!value.empty() && !value.back().yy){
				if(op.back()) tmp *= value.back().xx;
				else tmp += value.back().xx;
				value.pop_back();
			}
			if(!value.empty()) value.pop_back();
			op.pop_back();
			value.pb(mp(tmp,0));
			cerr << tmp << endl;
		}
		else {
			int a;
			sscanf(token,"%d",&a);
			value.pb(mp(a,0));
		}
	}
	while(!op.empty()){
		ll tmp = op.back();
		while(!value.empty() && !value.back().yy){
			if(op.back()) tmp *= value.back().xx;
			else tmp += value.back().xx;
			value.pop_back();
		}
		if(!value.empty()) value.pop_back();
		op.pop_back();
		value.pb(mp(tmp,0));
	}
	cout << value.back().xx << endl;
	cerr << value.back().xx << endl;
	return 0;
}
