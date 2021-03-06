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

const int MAX = 100000;
pair<string,int> OP[MAX];
vector<pair<string,int> > out;
int n;
char tmp[50];

int main(){
	scanf("%d",&n);
	loop(i,n) {
		scanf("%s",tmp); OP[i].xx = string(tmp);
		if(tmp[0] != 'r') scanf("%d",&OP[i].yy);
	}
	multiset<int> S;
	loop(i,n) {
		if(OP[i].xx[0] == 'i') {
			S.insert(OP[i].yy);
			out.pb(mp(OP[i].xx,OP[i].yy));
		}
		else if(OP[i].xx[0] == 'g'){
			while(!S.empty() && *S.begin() < OP[i].yy) {
				out.pb(mp("removeMin",OP[i].yy));
				S.erase(S.begin());		
			}
			if(S.empty() || *S.begin() > OP[i].yy){
				out.pb(mp("insert",OP[i].yy));				
				S.insert(OP[i].yy);
			}
			out.pb(mp(OP[i].xx,OP[i].yy));
		}
		else{
			if(!S.empty()) S.erase(S.begin());
			else out.pb(mp("insert", -1));
			out.pb(mp(OP[i].xx,OP[i].yy));
		}
	}
	printf("%lu\n",sz(out));
	for(auto p : out){
		if(p.xx[0] == 'r') printf("%s\n",p.xx.c_str());
		else printf("%s %d\n",p.xx.c_str(),p.yy);
	}
	return 0;
}
