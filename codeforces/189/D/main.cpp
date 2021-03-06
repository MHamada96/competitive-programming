#include <bits/stdc++.h>
#define loop(i,n) for(int i = 0;i < (n);i++)
#define range(i,a,b) for(int i = (a);i <= (b);i++)
#define all(A) A.begin(),A.end()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define sz(A) ((int)A.size())
#define vi vector<int>
#define vl vector<long>
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

const int MAX = 1e5 + 1e2;
int nxt[MAX],val[MAX],alive[MAX],n,ans;

int main(){
	scanf("%d",&n);
	loop(i,n) scanf("%d",val + i),nxt[i] = i + 1,alive[i] = 1;
	val[n] = INT_MAX;
	set<int> murderer;
	loop(i,n) if(val[i] > val[nxt[i]]) murderer.insert(i);
	while(!murderer.empty()){
		ans++;
		vi toDel;
		for(auto it = murderer.rbegin(); it != murderer.rend(); it++){
			nxt[*it] = nxt[nxt[*it]];
			if(val[*it] < val[nxt[*it]]) toDel.pb(*it);
		}
		for(int p : toDel) murderer.erase(p);
	} 	
	printf("%d\n",ans);
	return 0;
}
